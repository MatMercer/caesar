CC=gcc

caesar: main.c
	$(CC) -o ./bin/caesar main.c caesar.c caesar.h

clean: 
	- echo "Removing generated files"
	- rm -v caesar
