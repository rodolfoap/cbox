#!/usr/bin/env python3
import holder

img = holder.create(19, b"Thelonious")
holder.modify(img, b"Monk", 13)
holder.destroy(img)

# See https://github.com/sol-prog/Python-using-C-CPP-libraries-with-ctypes
