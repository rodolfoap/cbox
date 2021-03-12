#!/usr/bin/env python3
import ctypes
from ctypes import cdll
from ctypes import c_char_p
from ctypes import c_int
from ctypes import c_double
import sys, platform

class secbroker():
	def __init__(self, name, size):
		class _secbroker(ctypes.Structure):
			fields=[('name', ctypes.c_char_p), ('size', ctypes.c_int32)]

		self._secbroker=ctypes.cdll.LoadLibrary('./libsecbroker.so')

		self._create=self._secbroker.create
		self._create.argtypes=[ctypes.c_char_p, ctypes.c_int32]
		self._create.restype=ctypes.POINTER(_secbroker)

		self._display=self._secbroker.display
		self._display.argtypes=[ctypes.POINTER(_secbroker), ctypes.c_char_p]
		self._display.restype=None

		self._modify=self._secbroker.modify
		self._modify.argtypes=[ctypes.POINTER(_secbroker), ctypes.c_char_p, ctypes.c_uint32]
		self._modify.restype=None

		self._destroy=self._secbroker.destroy
		self._destroy.argtypes=[ctypes.POINTER(ctypes.POINTER(_secbroker))]
		self._destroy.restype=None

		self.secbroker=self._create(name, size)

	def display(self, text):
		self._display(self.secbroker, text)

	def modify(self, name, size):
		self._modify(self.secbroker, name, size)

	def destroy(self):
		self._destroy(self.secbroker)
