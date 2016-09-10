#include <Python.h>

#include "x16o.h"
#include "x16r.h"
#include "x16c.h"

static PyObject *hash_func(void (*func)(const char*, uint32_t, char*), PyObject *self, PyObject *args, const unsigned int buf_size)
{
    int ret;
    char* ptr = NULL;
    Py_ssize_t size = 0;
    char *output = NULL;
    PyObject *value = NULL;

#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input = NULL;
#else
    PyStringObject *input = NULL;
#endif
    if (!PyArg_ParseTuple(args, "S", &input)) {
        return NULL;
    }

#if PY_MAJOR_VERSION >= 3
    ret = PyBytes_AsStringAndSize((PyObject*) input, &ptr, &size);
#else
    ret = PyString_AsStringAndSize((PyObject*) input, &ptr, &size);
#endif
    if (ret < 0) {
        return NULL;
    }

    Py_INCREF(input);
    output = PyMem_Malloc(buf_size);
    func(ptr, size, output);
    Py_DECREF(input);

#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, buf_size);
#else
    value = Py_BuildValue("s#", output, buf_size);
#endif
    PyMem_Free(output);
    return value;
}

static PyObject *x16o_getpowhash(PyObject *self, PyObject *args)
{
    return hash_func(x16o_hash, self, args, 64);
}

static PyObject *x16r_getpowhash(PyObject *self, PyObject *args)
{
    return hash_func(x16r_hash, self, args, 64);
}

static PyObject *x16c_getpowhash(PyObject *self, PyObject *args)
{
    return hash_func(x16c_hash, self, args, 1024);
}

static PyMethodDef X16Methods[] = {
    { "getPoWHash_o", x16o_getpowhash, METH_VARARGS, "Returns the proof of work hash using X16 hash" },
    { "getPoWHash_r", x16r_getpowhash, METH_VARARGS, "Returns the proof of work hash using X16 hash" },
    { "getPoWHash_c", x16c_getpowhash, METH_VARARGS, "Returns the proof of work hash using X16 hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef X16Module = {
    PyModuleDef_HEAD_INIT,
    "x16_hash",
    "...",
    -1,
    X16Methods
};

PyMODINIT_FUNC PyInit_x16_hash(void) {
    return PyModule_Create(&X16Module);
}

#else

PyMODINIT_FUNC initx16_hash(void) {
    (void) Py_InitModule("x16_hash", X16Methods);
}
#endif
