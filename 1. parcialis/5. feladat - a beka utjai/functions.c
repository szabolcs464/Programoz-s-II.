//
// Created by nadys on 4/1/2026.
//

#include <stdio.h>
#include "functions.h"

int osszes_ut(int palya[HOSSZ], int ut[HOSSZ], int index, int lepes_db) {
    //Túlugrott a pályán, vagy vízbe esett
    if (index >= HOSSZ || palya[index] == 0) return 0;

    // Rögzítjük, hogy ráléptünk erre az indexre
    ut[lepes_db] = index;
    lepes_db++;

    // Az utolsó levélre érkezett
    if (index == HOSSZ - 1) {
        // Sikeres ut kiiras
        for (int i = 0; i < lepes_db; i++) {
            printf("%d ", ut[i]);
        }
        printf("\n");

        return 1;
    }

    int megoldasok_szama = 0;

    // Ugrasok (probalkozas)
    for (int ugras = 1; ugras <= 3; ugras++) {
        megoldasok_szama += osszes_ut(palya, ut, index + ugras, lepes_db);  // A lepes_db-t érték szerint adjuk át, így visszalépésnél magától a régi értéket használja a ciklus
    }

    return megoldasok_szama;
}