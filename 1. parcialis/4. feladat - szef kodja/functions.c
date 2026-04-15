//
// Created by nadys on 4/1/2026.
//

#include "functions.h"

int keres(int kod[KOD_HOSSZ], int index) {
    // Feltöltöttük mind a 3 helyet
    if (index == KOD_HOSSZ) {
        // Szabályok ellenőrzése
        if (kod[0] + kod[1] + kod[2] == 7 && kod[0] < kod[2]) {
            return 1;
        }
        return 0;
    }

    for (int szam = 1; szam <= 4; szam++) {
        kod[index] = szam; // Beírjuk a tippet

        if (keres(kod, index + 1) == 1) {
            return 1;
        }

        // Ha a keresés 0-val tér vissza, a ciklus pörög továb és felülírja a kod[index]-et a következő 'szam'-mal.
    }

    return 0;
}