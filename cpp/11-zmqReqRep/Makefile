CC=g++
CLIBS=-lzmq
CFLAGS=-g

default: all

all: server client

edit:
	vim -O server.cpp client.cpp
	$(CC) $(CFLAGS) $(CLIBS) -o server server.cpp
	$(CC) $(CFLAGS) $(CLIBS) -o client client.cpp
	./server &
	./client

server: server.cpp
	$(CC) $(CFLAGS) $(CLIBS) -o server server.cpp
	./server &

client: client.cpp
	$(CC) $(CFLAGS) $(CLIBS) -o client client.cpp
	./client &

clean:
	rm -rf server client
