//
// Created by nadys on 5/6/2026.
//

#include "functions.h"

// Buborékrendezés
void sorba_rendez(int csomagok[], int darab) {
    int i, j, csere;
    for (i = 0; i < darab - 1; i++) {
        for (j = 0; j < darab - i - 1; j++) {
            if (csomagok[j] > csomagok[j+1]) {
                csere = csomagok[j];
                csomagok[j] = csomagok[j+1];
                csomagok[j+1] = csere;
            }
        }
    }
}

// Greedy algoritmus.
int maximum_kiszallitas(int csomagok[], int darab, int max_energia) {
    int kiszallitott_darab = 0;
    int i;

    sorba_rendez(csomagok, darab);

    for (i = 0; i < darab; i++) {
        if (max_energia >= csomagok[i]) {
            max_energia = max_energia - csomagok[i];
            kiszallitott_darab++;
        } else {
            // Elfogyott az energia
            break;
        }
    }

    return kiszallitott_darab;
}