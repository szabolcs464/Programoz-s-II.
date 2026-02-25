//
// Created by nadys on 2/18/2026.
//

#include "functions.h"

#include <stdio.h>

void readElementsRecursive(int *v, int n) {
    if (n>=0) {
        readElementsRecursive(v, n-1);
        scanf("%i", &v[n]);
    }
}

void printElementsRecursive(int *v, int n) {
    if (n>=0) {
        printElementsRecursive(v,n-1);
        printf("%i", v[n]);
    }
}

int sumElementsRecursive(int *v, int n) {
    if (n < 0) {
        return 0;
    }
    return v[n] + sumElementsRecursive(v, n - 1);
}

int minElementRecursive(int *v, int n) {
    if (n == 0) {
        return v[0];
    }
    int current_min = minElementRecursive(v, n - 1);
    return (v[n] < current_min) ? v[n] : current_min;
}

int countPositiveElementsRecursive(int *v, int n) {
    if (n < 0) {
        return 0;
    }
    int is_positive = (v[n] > 0) ? 1 : 0;
    return is_positive + countPositiveElementsRecursive(v, n - 1);
}