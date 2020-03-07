#ifndef CAESAR_H
#define CAESAR_H

#include <stdbool.h>

bool isLowerCase(int c);
int caesar(int c, int k);
int caesarDict(int c, int k, char const* dict);
char* cleanDict(char const* dict);
bool charInDict(int c, char const* dict);

#endif
