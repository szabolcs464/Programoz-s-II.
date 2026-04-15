#include <stdio.h>
#include "functions.h"

int main() {
    int palya[MERET][MERET] = {
        {0, 1, 0, 2, 0},
        {0, 2, 0, 1, 0},
        {0, 0, 1, 2, 0},
        {2, 0, 0, 0, 1},
        {0, 1, 2, 0, 0}
    };

    int latogatott[MERET][MERET] = {0};

    printf("Eredeti palya:\n");
    kiir_palya(palya);

    if (keres(palya, latogatott, 0, 0, 0) == 1) {
        printf("\nBejart ut (9-essel jelolve):\n");
        kiir_palya(palya);
    } else {
        printf("\nNincs olyan ut, ahol pont 3 gombat eszik a suni!\n");
    }

    return 0;
}