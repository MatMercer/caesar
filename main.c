#include <stdio.h>
#include <stdlib.h>
#include "caesar.h"

int main(int argc, char** args)
{
	if (argc < 2)
	{
		printf("caesar: Error, please specify k: caesar [K]\n", stderr);
		return 1;
	}

	int k = atoi(args[1]);
	
	int ch;
	while ( (ch=getchar()) != EOF ) 
	{
		if (isASCIILetter(ch))
		{
			printf("%c", caesar(ch, k));
		} else
		{
			printf("%c", ch);
		}
	}

	return 0;	
}