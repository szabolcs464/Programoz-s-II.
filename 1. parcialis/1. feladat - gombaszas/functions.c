//
// Created by nadys on 4/1/2026.
//

#include <stdio.h>
#include "functions.h"

// Irányok
int irany_sor[] = {-1, 1, 0, 0};
int irany_oszlop[] = {0, 0, -1, 1};

void kiir_palya(int palya[MERET][MERET]) {
    for (int i = 0; i < MERET; i++) {
        for (int j = 0; j < MERET; j++) {
            printf("%d ", palya[i][j]);
        }
        printf("\n");
    }
}

int keres(int palya[MERET][MERET], int latogatott[MERET][MERET], int sor, int oszlop, int gomba_db) {
    if (sor < 0 || sor >= MERET || oszlop < 0 || oszlop >= MERET) return 0; //leleptunk a palyarol
    if (palya[sor][oszlop] == 2) return 0;      //kő
    if (latogatott[sor][oszlop] == 1) return 0; //voltunk itt

    if (palya[sor][oszlop] == 1) {
        gomba_db++;
    }

    //Célba értünk-e?
    if (sor == MERET - 1 && oszlop == MERET - 1) {
        if (gomba_db == 3) {
            palya[sor][oszlop] = 9;
            return 1;
        } else {
            return 0;
        }
    }

    latogatott[sor][oszlop] = 1;

    for (int i = 0; i < 4; i++) {
        int uj_sor = sor + irany_sor[i];
        int uj_oszlop = oszlop + irany_oszlop[i];

        if (keres(palya, latogatott, uj_sor, uj_oszlop, gomba_db) == 1) {
            palya[sor][oszlop] = 9;
            return 1;
        }
    }

    latogatott[sor][oszlop] = 0;    //Ha egy irány sem volt jó, töröljük a nyomunkat
    return 0;
}