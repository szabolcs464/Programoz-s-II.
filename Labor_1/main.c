#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(void) {
    int n;
    if (scanf("%i", &n) != 1 || n <= 0) {
        return -1;
    }

    int *v = (int *)malloc(n * sizeof(int));
    if (!v) {
        printf("malloc failed\n");
        exit(-1);
    }

    readElementsRecursive(v, n - 1);

    printf("Elemek: ");
    printElementsRecursive(v, n - 1);
    printf("\n");

    printf("Osszeg: %i\n", sumElementsRecursive(v, n - 1));
    printf("Minimum: %i\n", minElementRecursive(v, n - 1));
    printf("Pozitiv elemek szama: %i\n", countPositiveElementsRecursive(v, n - 1));

    free(v);
    return 0;
}
