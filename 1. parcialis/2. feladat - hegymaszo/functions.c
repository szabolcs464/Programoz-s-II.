//
// Created by nadys on 4/1/2026.
//

#include <stdio.h>
#include "functions.h"

int irany_sor[] = {-1, 1, 0, 0};
int irany_oszlop[] = {0, 0, -1, 1};

void kiir_palya(int palya[MERET][MERET]) {
    for (int i = 0; i < MERET; i++) {
        for (int j = 0; j < MERET; j++) {
            if (palya[i][j] == 99) printf("* ");    //99 = megtalalt ut
            else printf("%d ", palya[i][j]);
        }
        printf("\n");
    }
}

int keres(int palya[MERET][MERET], int latogatott[MERET][MERET], int sor, int oszlop, int elozo_magassag) {
    if (sor < 0 || sor >= MERET || oszlop < 0 || oszlop >= MERET) return 0; //leleptunk a palyarol
    if (latogatott[sor][oszlop] == 1) return 0; //mar voltunk
    if (palya[sor][oszlop] - elozo_magassag < -1 || palya[sor][oszlop] - elozo_magassag > 1) return 0;    //tul nagy lepes

    //Célba értünk-e?
    if (sor == MERET - 1 && oszlop == MERET - 1) {
        palya[sor][oszlop] = 99;
        return 1;
    }

    latogatott[sor][oszlop] = 1;

    for (int i = 0; i < 4; i++) {
        int uj_sor = sor + irany_sor[i];
        int uj_oszlop = oszlop + irany_oszlop[i];

        if (keres(palya, latogatott, uj_sor, uj_oszlop, palya[sor][oszlop]) == 1) {
            palya[sor][oszlop] = 99;
            return 1;
        }
    }

    latogatott[sor][oszlop] = 0;    //ha innen nincs jó út, visszavonjuk a lépést
    return 0;
}