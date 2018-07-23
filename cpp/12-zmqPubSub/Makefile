CC=g++
CLIBS=-lzmq
CFLAGS=-g

default: all

all: publisher subscribr

edit:
	vim -O publisher.cpp subscribr.cpp
	$(CC) $(CFLAGS) $(CLIBS) -o publisher publisher.cpp
	$(CC) $(CFLAGS) $(CLIBS) -o subscribr subscribr.cpp
	./subscribr &
	./publisher

publisher: publisher.cpp
	$(CC) $(CFLAGS) $(CLIBS) -o publisher publisher.cpp
	./publisher &

subscribr: subscribr.cpp
	$(CC) $(CFLAGS) $(CLIBS) -o subscribr subscribr.cpp
	./subscribr

clean:
	rm -rf publisher subscribr weather.ipc
	killall publisher 2>/dev/null || true
	killall subscribr 2>/dev/null || true
