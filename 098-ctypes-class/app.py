#!/usr/bin/env python3
from holder import holder

img=holder(19, b"Thelonious")
img.print(b"created")
img.modify(b"Monk", 13)
img.print(b"modified")
img.destroy()

# See https://github.com/sol-prog/Python-using-C-CPP-libraries-with-ctypes
