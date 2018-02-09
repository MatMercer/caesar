CC=gcc

caesar: main.c caesar.c caesar.h
	$(CC) -o caesar main.c caesar.c caesar.h

clean: 
	- echo "Removing generated files"
	- rm -v caesar

install:
	- cp caesar /usr/bin
