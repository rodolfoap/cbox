CC=g++
CLIBS=-lm
CFLAGS=-c -fPIC

default: all

all: edit

edit:
	vim -O foo.cpp app.py
	$(CC) $(CFLAGS) $(CLIBS) -o foo.o foo.cpp
	$(CC) -shared -Wl,-soname,libfoo.so -o libfoo.so foo.o
	./app.py

clean:
	rm -rf foo.o libfoo.so
