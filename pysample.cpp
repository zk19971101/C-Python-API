#include<Python.h>
#include"myadd.h"

static PyObject *py_add(PyObject *self, PyObject *args)
{
    int x, y, result;
    if(!PyArg_ParseTuple(args, "ii", &x, &y))
    {
        return NULL;
    }
    result = c_add(x, y);
    return Py_BuildValue("i", result);
}

static PyObject *py_add_list(PyObject *self, PyObject *args)
{
    PyObject *listObj;
    if (!PyArg_ParseTuple(args, "O", &listObj)){
        return NULL;
    }
    int length = PyList_Size(listObj);
    int i;
    int sum=0;
    for(i=0; i<length; i++)
    {
        PyObject *temp = PyList_GetItem(listObj, i);
        long elem = PyLong_AsLong(temp);
        sum += elem;
    }
    return Py_BuildValue("i", sum);
}

static PyMethodDef addMethod[] = {
    {"add", py_add, METH_VARARGS, "子模块的help文档"},
    {"add_list", py_add_list, METH_VARARGS, "add list的help文档"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef my_add_module = {
    PyModuleDef_HEAD_INIT,
    "add",
    "包的文档",
    -1,
    addMethod
};

PyMODINIT_FUNC PyInit_sample(void)
{
    return PyModule_Create(&my_add_module);
}