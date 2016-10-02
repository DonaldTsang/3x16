#include <Python.h>

#include "x16o.h"
#include "x16r.h"
#include "x16c.h"

static PyObject *hash_func(void (*func)(const char*, uint32_t, char*), PyObject *self, PyObject *args, const unsigned int buf_size)
{
    int ret;
    char* ptr;
    Py_ssize_t size = 0;
    char *output = NULL;
    PyObject *value;

#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
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

static PyObject *x16o512_gethash(PyObject *self, PyObject *args)
{
    return hash_func(x16o512_hash, self, args, 64);
}

static PyObject *x16r512_gethash(PyObject *self, PyObject *args)
{
    return hash_func(x16r512_hash, self, args, 64);
}

static PyObject *x16c512_gethash(PyObject *self, PyObject *args)
{
    return hash_func(x16c512_hash, self, args, 1024);
}

static PyObject *x16o256_gethash(PyObject *self, PyObject *args)
{
    return hash_func(x16o256_hash, self, args, 32);
}

static PyObject *x16r256_gethash(PyObject *self, PyObject *args)
{
    return hash_func(x16r256_hash, self, args, 32);
}

static PyObject *x16c256_gethash(PyObject *self, PyObject *args)
{
    return hash_func(x16c256_hash, self, args, 512);
}

static PyObject *x16o384_gethash(PyObject *self, PyObject *args)
{
    return hash_func(x16o384_hash, self, args, 48);
}

static PyObject *x16r384_gethash(PyObject *self, PyObject *args)
{
    return hash_func(x16r384_hash, self, args, 48);
}

static PyObject *x16c384_gethash(PyObject *self, PyObject *args)
{
    return hash_func(x16c384_hash, self, args, 768);
}

static PyMethodDef X16Methods[] = {
    { "getHash_512o", x16o512_gethash, METH_VARARGS, "Returns the proof of work hash using X16 hash" },
    { "getHash_512r", x16r512_gethash, METH_VARARGS, "Returns the proof of work hash using X16 hash" },
    { "getHash_512c", x16c512_gethash, METH_VARARGS, "Returns the proof of work hash using X16 hash" },
    { "getHash_256o", x16o256_gethash, METH_VARARGS, "Returns the proof of work hash using X16 hash" },
    { "getHash_256r", x16r256_gethash, METH_VARARGS, "Returns the proof of work hash using X16 hash" },
    { "getHash_256c", x16c256_gethash, METH_VARARGS, "Returns the proof of work hash using X16 hash" },
    { "getHash_384o", x16o384_gethash, METH_VARARGS, "Returns the proof of work hash using X16 hash" },
    { "getHash_384r", x16r384_gethash, METH_VARARGS, "Returns the proof of work hash using X16 hash" },
    { "getHash_384c", x16c384_gethash, METH_VARARGS, "Returns the proof of work hash using X16 hash" },
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
