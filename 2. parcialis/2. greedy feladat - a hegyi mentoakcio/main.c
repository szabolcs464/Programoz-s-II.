#include <stdio.h>
#include "functions.h"

int main() {
    int sielok_szama = 4;
    int sielok_igenyei[] = {5, 9, 3, 2};

    int takarok_szama = 5;
    int takaro_ertekek[] = {1, 2, 8, 4, 6};

    int eredmeny = megmentett_sielok(sielok_igenyei, sielok_szama, takaro_ertekek, takarok_szama);

    printf("A mentocsapat %d sielot tudott megmenteni a fagyastol.\n", eredmeny);

    return 0;
}