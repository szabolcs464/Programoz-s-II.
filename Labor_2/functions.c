//
// Created by nadys on 2/25/2026.
//

#include "functions.h"

#include <stdio.h>
#include <stdlib.h>

void feltoltes(int a[], int n) {
    for (int i = 0; i < n; i+=2) {
        a[i] = rand() % 3;
        a[i+1] = rand() % 3;
        if (a[i] == a[i+1]) {
            reroll(&a[i], &a[i+1]);
        }
    }
}

void reroll(int *a, int *b) {
    while (*a == *b) {
        *a = rand() % 3;
        *b = rand() % 3;
    }
}

void kiiras(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int findWinner(int a[], int n) {
    if (n == 2) {
        return winner(a[0], a[1]);
    }
    int currentWinner = winner(a[n-1], a[n-2]);
    return winner(currentWinner, findWinner(a, n-2));
}

int winner(int a, int b) {
    if (a == b) {
        reroll(&a, &b);
    }
    if ((a==0 && b==1) || (a==1 && b==2) || (a==2 && b==0)) {
        return b;
    }
    return a;
}
