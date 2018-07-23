CC=g++
CLIBS=-lm
CFLAGS=-g
st=""

default: all

all: app

edit:
	$(eval START=$(shell /bin/date +%s))
	@clear
	@cat README
	@cat model.cpp
	@read -p "Press any key to continue: " DUMMY
	vim app.cpp
	$(eval END=$(shell /bin/date +%s))
	echo $$(( $(START) - $(END) ))
	@echo ==================================================================================================
	@sdiff -abBWZ app.cpp model.cpp
	@echo ==================================================================================================
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

