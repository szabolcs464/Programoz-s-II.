#include <stdio.h>
#include "functions.h"

int main() {
    int lepcsok_szama = 5;
    int eredmeny;

    eredmeny = modok_szama(lepcsok_szama);

    printf("A robot %d kulonbozo modon tud feljutni a %d fokos lepcsore.\n", eredmeny, lepcsok_szama);

    return 0;
}