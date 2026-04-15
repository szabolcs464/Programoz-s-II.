
#include <stdio.h>
#include "functions.h"

int main() {
    int kod[KOD_HOSSZ] = {0};

    if (keres(kod, 0) == 1) {
        printf("A szef kodja: %d %d %d\n", kod[0], kod[1], kod[2]);
    } else {
        printf("Nem letezik ilyen kod!\n");
    }

    return 0;
}