#!/usr/bin/env python3
from ctypes import cdll
from ctypes import c_char_p
from ctypes import c_double
from ctypes import create_string_buffer

# Get the library
libhello = cdll.LoadLibrary('./libhello.so')

# Get an instance
hello = libhello.helloFactory()

# Call functions
libhello.sayHello(hello)
libhello.printFloat(hello, c_double(19.17))
print("Double of 19:", libhello.doubleMe(hello, 19))

libhello.sayHelloName.restype = c_char_p
#lib.return_string.argtypes = [c_char_p]
result=libhello.sayHelloName(hello, b"Thelonious")
print(result)
