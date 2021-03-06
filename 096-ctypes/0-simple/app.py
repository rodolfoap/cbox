#!/usr/bin/env python3
from ctypes import cdll
from ctypes import c_char_p
from ctypes import c_int
from ctypes import c_double

# Get the library
libhello=cdll.LoadLibrary('./libapp.so')

# Get an instance using a factory
hello=libhello.helloFactory()

# Call functions
libhello.sayHello(hello)
libhello.printFloat(hello, c_double(19.17))
print("Double of 19:", libhello.doubleMe(hello, 19))

libhello.sayHelloName.argtypes=[c_int, c_char_p]
libhello.sayHelloName.restype=c_char_p
print(libhello.sayHelloName(hello, b'Thelonious').decode("utf-8"))
