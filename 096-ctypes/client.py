#!/usr/bin/env python3
from secbroker import secbroker

img=secbroker(b"Thelonious", 79)
img.display(b"created")
img.modify(b"Monk", 13)
img.display(b"modified")
img.destroy()
img.display(b"modified")
