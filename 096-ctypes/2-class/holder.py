#!/usr/bin/env python3
import ctypes
from ctypes import cdll
from ctypes import c_char_p
from ctypes import c_int
from ctypes import c_double
import sys, platform

class holder():
	def __init__(self, a, b):
		class _secbroker(ctypes.Structure):
			fields=[('width', ctypes.c_int32), ('height', ctypes.c_int32)]

		self._holder=ctypes.cdll.LoadLibrary('./libholder.so')

		self._create=self._holder.create
		self._create.argtypes=[ctypes.c_int32, ctypes.c_char_p]
		self._create.restype=ctypes.POINTER(_secbroker)

		self._display=self._holder.display
		self._display.argtypes=[ctypes.POINTER(_secbroker), ctypes.c_char_p]
		self._display.restype=None

		self._modify=self._holder.modify
		self._modify.argtypes=[ctypes.POINTER(_secbroker), ctypes.c_char_p, ctypes.c_uint32]
		self._modify.restype=None

		self._destroy=self._holder.destroy
		self._destroy.argtypes=[ctypes.POINTER(ctypes.POINTER(_secbroker))]
		self._destroy.restype=None

		self.holder=self._create(a, b)

	def display(self, text):
		self._display(self.holder, text)

	def modify(self, a, b):
		self._modify(self.holder, a, b)

	def destroy(self):
		self._destroy(self.holder)
