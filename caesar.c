#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "caesar.h"

// ASCII ranges
#define ASCII_LO_R1 65
#define ASCII_LO_R2 90

#define ASCII_UP_R1 97
#define ASCII_UP_R2 122

char* cleanDict(char* dict)
{
	int i;

	char* cDict = calloc(1, sizeof(int));
	cDict[0] = '\0';

	int length = 0;
	int s = strlen(dict);
	for (i = 0; i < s; i += 1)
	{
		if (!charInDict(dict[i], cDict) && isASCIILetter(dict[i]))
		{
			length += 1;
			cDict = realloc(cDict, length * sizeof(int));
			cDict[length - 1] = dict[i];
		}
	}

	return cDict;
}

bool charInDict(int c, char* dict)
{
	int s = strlen(dict);
	int i;

	for (i = 0; i < s; i += 1)
	{
		if (dict[i] == c)
		{
			return true;
		}
	}
	
	return false;
}

int posInDict(int c, char* dict)
{
	int s = strlen(dict);

	int i;
	int pos = 0;
	for (i = 0; i < s; i++)
	{
		if (c == dict[i])
		{
			return pos;
		}
		pos += 1;
	}
	return -1;
}

bool isASCIILetter(int c)
{
	return (c >= ASCII_LO_R1 && c <= ASCII_LO_R2) || (c >= ASCII_UP_R1 && c <= ASCII_UP_R2);
}


bool isLowerCase(int c)
{
	return (c >= ASCII_LO_R1 && c <= ASCII_LO_R2);
}

int caesar(int c, int k)
{
	k %= 26;

	// int oldc = c;

	if (isLowerCase(c))
	{
		c += k;

		if (c < ASCII_LO_R1)
		{
			c = ASCII_LO_R2 - (ASCII_LO_R1 - c) + 1;
		}
		else if (c > ASCII_LO_R2)
		{
			c = (c - ASCII_LO_R2 - 1) + ASCII_LO_R1;
		}
	} else
	{
		c += k;

		if (c < ASCII_UP_R1)
		{
			c = ASCII_UP_R2 - (ASCII_UP_R1 - c) + 1;
		}
		else if (c > ASCII_UP_R2)
		{
			c = (c - ASCII_UP_R2 - 1) + ASCII_UP_R1;
		}
	}

	// printf(" %d -> %d ", oldc, c);

	return c;
}

int caesarDict(int c, int k, char* dict)
{
	if (charInDict(c, dict))
	{
		int s = strlen(dict);

		k %= s;

		// acac [a, b, d] k = 2
		// dcdc
		//
		// dcdc [a, b, d] k = -2
		// acac

		// acac [a, a, d] k = 1 -> [a, d]
		// acac
		//
		// dcdc [a, d] k = -1
		// acac

		int dictPos = k + s + posInDict(c, dict);

		//printf("%d\n\n", dictPos);

		if (dictPos >= s)
		{
			dictPos %= s;
		}
		if (dictPos < 0)
		{
			dictPos += s;
		}

		//printf("Need to change %c by %c in pos %d", c, dict[dictPos], dictPos);

		return dict[dictPos];
	}

	return c;
}
