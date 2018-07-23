CC=g++
CLIBS=-lm
CFLAGS=-g

default: all

all: app

edit:
	vim app.cpp
	$(CC) $(CFLAGS) $(CLIBS) -o app app.cpp
	./app

app: app.cpp
	$(CC) $(CFLAGS) $(CLIBS) -o app app.cpp
	./app

debug: app.cpp
	$(CC) $(CFLAGS) $(CLIBS) -o app app.cpp
	gdb -x app.dbg ./app

clean:
	rm -rf app
