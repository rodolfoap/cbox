#!/usr/bin/env python3

from ctypes import cdll
lib = cdll.LoadLibrary('./libhello.so')

class Dummy(object):
    def __init__(self):
        self.obj = lib.getHello()

    def sayHello(self):
        lib.sayHello(self.obj)

if __name__ == "__main__":
    d=Dummy()
    d.sayHello()

# See https://stackoverflow.com/questions/145270/calling-c-c-from-python
