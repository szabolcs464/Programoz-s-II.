#include <stdio.h>

//olvass be egy max 10 szamjegyu szamot es ird ki azokat a szamjegyeket a szambol,
//amelyek paros helyen vannak, hatulrol inditjuk a sorszamozast

void paros_helyu_kiiras(int szam, int szamlalo) {
    if (szam <= 0) {
        return;
    }
    if (szamlalo % 2 == 0) {
        int x = szam%10;
        if (x % 2 != 0) {
            printf("%d ", x);
        }
    }
    szam = szam/10;
    szamlalo++;
    paros_helyu_kiiras(szam, szamlalo);
}

int main(void) {
    int szam;
    scanf("%d", &szam);
    paros_helyu_kiiras(szam, 0);
    return 0;
}