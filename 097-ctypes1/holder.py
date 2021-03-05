#!/usr/bin/env python3
import ctypes
from ctypes import cdll
from ctypes import c_char_p
from ctypes import c_int
from ctypes import c_double
import sys, platform

holder = ctypes.cdll.LoadLibrary('./libholder.so')
class HOLDER(ctypes.Structure):
	_fields_ = [	('handle', ctypes.c_void_p),
			('width', ctypes.c_int32),
			('height', ctypes.c_int32),
			('channels', ctypes.c_int32)
	]
# Make the function names visible at the module level and add types
create = holder.create
create.argtypes = [ctypes.c_int32, ctypes.c_char_p]
create.restype = ctypes.POINTER(HOLDER)

modify = holder.modify
modify.argtypes = [ctypes.POINTER(HOLDER), ctypes.c_char_p, ctypes.c_uint32]
modify.restype = None

destroy = holder.destroy
destroy.argtypes = [ctypes.POINTER(ctypes.POINTER(HOLDER))]
destroy.restype = None
