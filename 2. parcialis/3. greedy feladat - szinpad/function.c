//
// Created by nadys on 5/13/2026.
//

#include "function.h"

// Buborékrendezés a befejezési idők alapján
void sorba_rendez_vege_szerint(Koncert koncertek[], int darab) {
    int i, j;
    Koncert csere;
    for (i = 0; i < darab - 1; i++) {
        for (j = 0; j < darab - i - 1; j++) {
            if (koncertek[j].vege > koncertek[j+1].vege) {
                csere = koncertek[j];
                koncertek[j] = koncertek[j+1];
                koncertek[j+1] = csere;
            }
        }
    }
}

// Greedy algoritmus
int maximum_koncert(Koncert koncertek[], int darab) {
    int i;
    int kivalasztott_darab = 0;
    int utolso_befejezes = 0;

    sorba_rendez_vege_szerint(koncertek, darab);

    for (i = 0; i < darab; i++) {
        if (koncertek[i].kezd >= utolso_befejezes) {
            kivalasztott_darab++;
            utolso_befejezes = koncertek[i].vege; // Szabad időpont kezdete
        }
    }

    return kivalasztott_darab;
}