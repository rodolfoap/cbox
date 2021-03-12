#!/usr/bin/env python3
from holder import holder

img=holder(19, b"Thelonious")
img.display(b"created")
img.modify(b"Monk", 13)
img.display(b"modified")
img.destroy()
img.display(b"modified")
