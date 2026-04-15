#include <stdio.h>
#include "functions.h"

int main() {
    int palya[HOSSZ] = {1, 1, 0, 1, 1, 1, 0, 1, 1, 1};  // 1: levél, 0: víz

    printf("A palya:\n");
    for (int i = 0; i < HOSSZ; i++) {
        printf("%d ", palya[i]);
    }
    printf("\n\n");

    // Ez a tömb tarolja az aktuálisan vizsgált útvonalat
    int ut[HOSSZ] = {0};

    printf("Ezeken az utakon (indexeken) tud atkelni a beka:\n");

    int eredmeny = osszes_ut(palya, ut, 0, 0);

    printf("\nOsszesen: %d db megoldas.\n", eredmeny);

    return 0;
}