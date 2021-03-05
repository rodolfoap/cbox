#!/usr/bin/env python3
from ctypes import cdll
from ctypes import c_char_p
from ctypes import c_double
from ctypes import c_int

# Naturally, all calls can all be included in a wrapper:
class Hello():
	def __init__(self):
		self.libhello = cdll.LoadLibrary('./libhello.so')
		self.hello = self.libhello.helloFactory()

	def sayHello(self):
		self.libhello.sayHello(self.hello)

	def printFloat(self, floatValue):
		self.libhello.printFloat(self.hello, c_double(floatValue))

	def doubleMe(self, intValue):
		return self.libhello.doubleMe(self.hello, intValue)

	def sayHelloName(self, string):
		self.libhello.sayHelloName.argtypes=[c_int, c_char_p]
		self.libhello.sayHelloName.restype=c_char_p
		return self.libhello.sayHelloName(self.hello, string).decode("utf-8")

# So, the code becomes:
hello = Hello()
hello.sayHello()
hello.printFloat(19.17)
print("Double of 19:", hello.doubleMe(19))
print(hello.sayHelloName(b"Thelonious"))
