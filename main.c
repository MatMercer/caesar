#include <stdio.h>
#include <stdlib.h>
#include "caesar.h"

int main(int argc, char** args)
{
	bool useDictionary = false;
	char* dictionary;

	if (argc < 2)
	{
		printf("caesar: Error, please specify k: caesar [K]\n", stderr);
		return 1;
	}
	if (argc == 3)
	{
		useDictionary = true;
		dictionary = args[2];
	}

	int k = atoi(args[1]);
	
	int ch;
	while ( (ch=getchar()) != EOF ) 
	{
		if (isASCIILetter(ch))
		{
			if (useDictionary)
			{
				printf("%c", caesarDict(ch, k, cleanDict(dictionary)));
			} else
			{
				printf("%c", caesar(ch, k));
			}
		} else
		{
			printf("%c", ch);
		}
	}

	return 0;	
}
