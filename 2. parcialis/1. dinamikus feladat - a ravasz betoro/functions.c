//
// Created by nadys on 5/13/2026.
//

#include "functions.h"

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// A dinamikus programozás algoritmus
int maximalis_zsakmany(int hazak[], int db) {
    int max_penz[100];
    int i;

    max_penz[0] = hazak[0];

    max_penz[1] = max(hazak[0], hazak[1]);

    // DP tábla kitöltése a 3. háztól
    for (i = 2; i < db; i++) {
        // max_penz[i-1] -> Kihagyjuk ezt a házat, marad az eddigi maximum.
        // max_penz[i-2] + hazak[i] -> Kiraboljuk ezt a házat,
        // de akkor csak a kettővel ezelőtti maximumhoz adhatjuk hozzá.
        max_penz[i] = max(max_penz[i-1], max_penz[i-2] + hazak[i]);
    }

    return max_penz[db - 1];
}