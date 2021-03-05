#!/usr/bin/env python3
import holder
import ctypes

img = holder.create(19, b"Thelonious")
holder.modify(img, b"Monk", 13)
holder.destroy(img)
