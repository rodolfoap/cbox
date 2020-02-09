#!/usr/bin/env python3
from ctypes import cdll

# Get the library
libhello=cdll.LoadLibrary('./libhello.so')

# Get an instance
hello=libhello.getHello()

# Call a function
libhello.sayHello(hello)

# See https://stackoverflow.com/questions/145270/calling-c-c-from-python
