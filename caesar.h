#ifndef CAESAR_H
#define CAESAR_H

#include <stdbool.h>

bool isLowerCase(int c);
int caesar(int c, int k);
int caesarDict(int c, int k, char* dict);
char* cleanDict(char* dict);
bool charInDict(int c, char* dict);

#endif
