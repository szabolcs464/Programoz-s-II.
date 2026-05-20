#include <stdio.h>
#include "functions.h"

int main() {
    // Készpénz mennyisége
    int utca[] = {2000, 7000, 9000, 3000, 10000};
    int hazak_szama = 5;
    int eredmeny;

    eredmeny = maximalis_zsakmany(utca, hazak_szama);

    printf("A betoro altal elviheto maximalis osszeg: %d\n", eredmeny);

    return 0;
}