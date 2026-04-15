#include <stdio.h>
#include "functions.h"

int main() {
    int palya[MERET][MERET] = {
        {1, 2, 5, 6},
        {1, 3, 4, 5},
        {0, 8, 8, 4},
        {0, 1, 2, 3}
    };

    int latogatott[MERET][MERET] = {0};

    printf("Eredeti hegy (magassagok):\n");
    kiir_palya(palya);

    if (keres(palya, latogatott, 0, 0, palya[0][0]) == 1) {
        printf("\nMegvan a bejart ut (*-gal jelolve):\n");
        kiir_palya(palya);
    } else {
        printf("\nA hegymaszo nem tud eljutni a celba ekkora ugrasokkal!\n");
    }

    return 0;
}