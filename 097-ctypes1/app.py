#!/usr/bin/env python3
from ctypes import cdll
from ctypes import c_char_p
from ctypes import c_double

# Get the library
libhello=cdll.LoadLibrary('./libhello.so')

# Get an instance
hello=libhello.helloFactory()

# Call functions
libhello.sayHello(hello)
print("Double of 19:", libhello.doubleme(hello, 19))
libhello.printfloat(hello, c_double(19.17))
