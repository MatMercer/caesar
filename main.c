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

	char* endptr;
	int k = strtol(args[1], &endptr, 10);

	if (*endptr != '\0') 
	{
		printf("caesar: Error, invalid number for k\n", stderr);
		return 2;
	}
	
	// Alloc result arrays
	char* cripto = calloc(1, sizeof(char));
	cripto[0] = '\0';
	char* decripto = calloc(1, sizeof(char));
	decripto[0] = '\0';

	size_t criptoLen = 0;
	int ch;
	while ( (ch=getchar()) != EOF ) 
	{
	if (useDictionary)
		{
			char cCaesar = caesarDict(ch, k, cleanDict(dictionary));

			criptoLen += 1;

			cripto = realloc(cripto, criptoLen * sizeof(char));
			decripto = realloc(decripto, criptoLen * sizeof(char));

			// Send results to array
			cripto[criptoLen - 1] = cCaesar;
			decripto[criptoLen - 1] = caesarDict(cCaesar, -k, cleanDict(dictionary));;

		} else
		{
			char cCaesar = caesar(ch, k);

			criptoLen += 1;

			cripto = realloc(cripto, criptoLen * sizeof(char));
			decripto = realloc(decripto, criptoLen * sizeof(char));

			// Send results to array
			cripto[criptoLen - 1] = cCaesar;
			decripto[criptoLen - 1] = caesar(cCaesar, -k);
		}
	}

	printf("%s\n", cripto);
	printf("%s\n", decripto);

	return 0;	
}
