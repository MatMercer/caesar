CC=gcc

caesar: main.c caesar.c caesar.h
	$(CC) -o caesar main.c caesar.c caesar.h

caesar-interactive: caesarinteractive.c caesar.c caesar.h
	$(CC) -o caesarinteractive caesarinteractive.c caesar.c caesar.h

clean: 
	- echo "Removing generated files"
	- rm -v caesar

install:
	- cp caesar /usr/bin
