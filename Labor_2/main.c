#include <stdio.h>

#include "functions.h"

int main(void) {
    int n;
    scanf("%d", &n);
    if (n % 2 == 1) {
        printf("A megadott szam nem paros");
        return 0;
    }
    else {
        int a[n];
        feltoltes(a, n);
        kiiras(a, n);
        printf("\n%d",findWinner(a, n));
    }
    return 0;
}