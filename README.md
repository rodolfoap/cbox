# C++ Box

This is a personal C++ cookbook. A set of precooked recipes. Mostly mine, but a lot of it was just copied from the net. References to the original authors are normally included, if the code was remarkable.

## Requirements

* Work on Debian Buster, _YMMV_ if you use another distro.
* Normally, installing `cmake` and `build-tools` is enough.
* Some tools require ZeroMQ, OpenCV or SFML.
* `gdb` and `nemiver` are my debugging preference.

## Usage

Include this in your .bashrc to accelerate the process:

```
x() { source .x $@; } # eXecute
e() { source .x e;  } # Edit
k() { source .k $@; } # Kill, cancel, ESC, delete, etc.
```
So, the bash command `x` will e**x**ecute the application (see the `.x` file). `k` will delete (**k**ill) all unnecessary files (see `.k`)

Enjoy.
