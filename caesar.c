#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "caesar.h"

// ASCII ranges
#define ASCII_LO_R1 97
#define ASCII_LO_R2 122

#define ASCII_UP_R1 65
#define ASCII_UP_R2 90

char* cleanDict(char* dict)
{
	char* cDict = calloc(1, sizeof(int));
	cDict[0] = '\0';

	int dictLen = 0;
	while (*dict != '\0')
	{
		if (!charInDict(*dict, cDict) && isalpha(*dict))
		{
			dictLen += 1;
			cDict = realloc(cDict, dictLen * sizeof(int));
			cDict[dictLen - 1] = *dict;
		}
		dict += 1;
	}

	return cDict;
}

bool charInDict(int c, char* dict)
{
	while (*dict != '\0')
	{
		if (*dict == c)
		{
			return true;
		}

		dict += 1;
	}
	
	return false;
}

int posInDict(int c, char* dict)
{
	int pos = 0;
	while (*dict != '\0')
	{
		if (c == *dict)
		{
			return pos;
		}
		pos += 1;

		dict += 1;
	}
	return -1;
}


bool isLowerCase(int c)
{
	return (c & 32) != 0;
}

int caesar(int c, int k)
{
	// int oldc = c;

	if (isalpha(c))
	{
		if (isLowerCase(c))
		{
			k %= 26;
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
	}

	// printf(" %d -> %d = %c ", oldc, c, c);

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
