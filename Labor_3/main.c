#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "functions.h"

int main(void) {
    int n;
    scanf("%d", &n);
    int v[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++){
        v[i] = rand() % 200 - 100;
    }
    printf("A tomb:\n");
    kiir(v, n);
    mergeSort(v, 0, n-1);
    printf("\nRendezve:\n");
    kiir(v, n);
    binariskereses(v, n);
    return 0;
}
