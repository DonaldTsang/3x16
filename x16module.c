#include <Python.h>

#include "x16o.h"
#include "x16r.h"
#include "x16c.h"
#include "simple.h"
#include "val.h"

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

#define HASHER(name) \
static PyObject *gethash256_ ## name(PyObject *self, PyObject *args) \
{ \
    return hash_func(hash_256 ## name, self, args, 32); \
} \
static PyObject *gethash384_ ## name(PyObject *self, PyObject *args) \
{ \
    return hash_func(hash_384 ## name, self, args, 48); \
} \
static PyObject *gethash512_ ## name(PyObject *self, PyObject *args) \
{ \
    return hash_func(hash_512 ## name, self, args, 64); \
}

#define HASHERS(name) \
static PyObject *gethash320_ ## name(PyObject *self, PyObject *args) \
{ \
    return hash_func(hash_320 ## name, self, args, 40); \
} \
static PyObject *gethash448_ ## name(PyObject *self, PyObject *args) \
{ \
    return hash_func(hash_448 ## name, self, args, 56); \
}

HASHER(blake)
HASHER(bmw)
HASHER(groestl)
HASHER(jh)
HASHER(keccak)
HASHER(skein)
HASHER(luffa)
HASHER(cubehash)
HASHER(shavite)
HASHER(simd)
HASHER(echo)
HASHER(hamsi)
HASHER(fugue)
HASHER(shabal)
HASHER(whirl)
HASHER(sha)

HASHERS(blake)
HASHERS(bmw)
HASHERS(groestl)
HASHERS(jh)
HASHERS(keccak)
HASHERS(skein)
HASHERS(luffa)
HASHERS(cubehash)
HASHERS(shavite)
HASHERS(simd)
HASHERS(echo)
HASHERS(hamsi)
HASHERS(fugue)
HASHERS(shabal)
HASHERS(whirl)
HASHERS(sha)

#define HASH_ARRAY(name) \
{"getHash_256" #name, gethash256_ ## name, METH_VARARGS, "Returns the 256 bit hash of" #name}, \
{"getHash_384" #name, gethash384_ ## name, METH_VARARGS, "Returns the 384 bit hash of" #name}, \
{"getHash_512" #name, gethash512_ ## name, METH_VARARGS, "Returns the 512 bit hash of" #name}, 

#define HASHS_ARRAY(name) \
{"getHash_320" #name, gethash320_ ## name, METH_VARARGS, "Returns the 320 bit hash of" #name}, \
{"getHash_448" #name, gethash448_ ## name, METH_VARARGS, "Returns the 448 bit hash of" #name}

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
	HASH_ARRAY(blake)
	HASH_ARRAY(bmw)
	HASH_ARRAY(groestl)
	HASH_ARRAY(jh)
	HASH_ARRAY(keccak)
	HASH_ARRAY(skein)
	HASH_ARRAY(luffa)
	HASH_ARRAY(cubehash)
	HASH_ARRAY(shavite)
	HASH_ARRAY(simd)
	HASH_ARRAY(echo)
	HASH_ARRAY(hamsi)
	HASH_ARRAY(fugue)
	HASH_ARRAY(shabal)
    HASH_ARRAY(whirl)
	HASH_ARRAY(sha)
	HASH_ARRAYS(blake)
	HASH_ARRAYS(bmw)
	HASH_ARRAYS(groestl)
	HASH_ARRAYS(jh)
	HASH_ARRAYS(keccak)
	HASH_ARRAYS(skein)
	HASH_ARRAYS(luffa)
	HASH_ARRAYS(cubehash)
	HASH_ARRAYS(shavite)
	HASH_ARRAYS(simd)
	HASH_ARRAYS(echo)
	HASH_ARRAYS(hamsi)
	HASH_ARRAYS(fugue)
	HASH_ARRAYS(shabal)
    HASH_ARRAYS(whirl)
	HASH_ARRAYS(sha)
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