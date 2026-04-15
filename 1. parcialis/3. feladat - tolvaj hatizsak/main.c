
#include <stdio.h>
#include "functions.h"

int main() {
    int targyak[TARGYAK_DB] = {3, 5, 8, 2, 7};

    int kivalasztott[TARGYAK_DB] = {0};

    if (keres(targyak, kivalasztott, 0, 0, 0) == 1) {
        printf("Megvan a kombinacio! A tolvaj ezeket viszi el:\n");
        for (int i = 0; i < TARGYAK_DB; i++) {
            if (kivalasztott[i] == 1) {
                printf("%d kg\n", targyak[i]);
            }
        }
    } else {
        printf("Nincs olyan kombinacio, ami megfelel a felteteleknek.\n");
    }

    return 0;
}