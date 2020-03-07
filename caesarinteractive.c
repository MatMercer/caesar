#include "caesar.h"
#include "stdio.h"
#include "stdlib.h"

#define MAX_DATA_LEN 512

int main() {
    char *data = calloc(MAX_DATA_LEN, sizeof(char));
    int key;

    printf("Specify the data: ");
    fgets(data, MAX_DATA_LEN, stdin);

    fprintf(stderr, "Specify the key (negative for reverse): ");
    scanf("%i", &key);

    fprintf(stderr, "Using %i as the key\n", key);

    fprintf(stderr, "Transformed data:\n\n");

    while(*data) {
        printf("%c", caesar(*data++, key));
    }

    printf("\n");

    return 0;
}
