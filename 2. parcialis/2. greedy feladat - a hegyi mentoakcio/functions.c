//
// Created by nadys on 5/13/2026.
//

#include "functions.h"

// Buborekrendezés
void sorba_rendez(int tomb[], int n) {
    int i, j, csere;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (tomb[j] > tomb[j+1]) {
                csere = tomb[j];
                tomb[j] = tomb[j+1];
                tomb[j+1] = csere;
            }
        }
    }
}

// Greedy algoritmus
int megmentett_sielok(int igenyek[], int igeny_db, int takarok[], int takaro_db) {
    int megmentett_darab = 0;
    int takaro_index = 0;
    int i;

    // 1. Lépés: rendezés
    sorba_rendez(igenyek, igeny_db);
    sorba_rendez(takarok, takaro_db);

    // 2. Lépés: Megyunk sorba a sielokon es próbálunk takarót párosítani
    for (i = 0; i < igeny_db; i++) {

        // Addig léptetjük a takaró indexet, amíg nem találunk elég meleg takarót, vagy el nem fogynak a takarók.
        while (takaro_index < takaro_db && takarok[takaro_index] < igenyek[i]) {
            takaro_index++;
        }

        // Kifutottunk a takaró tömbből?
        if (takaro_index < takaro_db) {
            megmentett_darab++;
            takaro_index++;
        } else {
            // A takarók elfogytak
            break;
        }
    }

    return megmentett_darab;
}