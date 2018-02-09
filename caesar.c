#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// ASCII ranges
#define ASCII_LO_R1 65
#define ASCII_LO_R2 90

#define ASCII_UP_R1 97
#define ASCII_UP_R2 122

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

	if (isLowerCase(c))
	{
		c += k;

		if (c < ASCII_LO_R1)
		{
			c = ASCII_LO_R2 - (ASCII_LO_R1 - c) + 1;
		}
		else if (c > ASCII_LO_R2)
		{
			c = (c - ASCII_LO_R2) + ASCII_LO_R1;
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
			c = (c - ASCII_UP_R2) + ASCII_UP_R1;
		}
	}

	return c;
}

int caesarDict(int c, int k, char* dict)
{
	if (charInDict(c, dict))
	{
		return caesar(c, k);
	}

	return c;
}
