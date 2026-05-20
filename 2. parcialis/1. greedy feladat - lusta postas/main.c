#include <stdio.h>
#include "functions.h"

int main() {
    int postas_energia = 80;
    int csomagok[] = {40, 10, 25, 50, 15, 5};
    int db = 6;
    int eredmeny;

    eredmeny = maximum_kiszallitas(csomagok, db, postas_energia);

    printf("A lusta postas maximum %d csomagot tud kiszallitani.\n", eredmeny);

    return 0;
}