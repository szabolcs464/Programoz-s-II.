//
// Created by nadys on 4/1/2026.
//

#include <stdio.h>
#include "functions.h"

int keres(int targyak[TARGYAK_DB], int kivalasztott[TARGYAK_DB], int index, int db, int osszsuly) {
    // Megvan a 3 targy es a suly 14
    if (db == 3 && osszsuly == 14) {
        return 1;
    }

    //Túlléptük a limitet vagy elfogytak a tárgyak
    if (db > 3 || osszsuly > 14 || index >= TARGYAK_DB) {
        return 0;
    }

    kivalasztott[index] = 1;

    if (keres(targyak, kivalasztott, index + 1, db + 1, osszsuly + targyak[index]) == 1) {
        return 1;
    }

    kivalasztott[index] = 0;    //Ha az első ág nem jött be, kivesszük a táskából

    // Mi történik, ha kihagyjuk
    if (keres(targyak, kivalasztott, index + 1, db, osszsuly) == 1) {
        return 1;
    }

    return 0;
}