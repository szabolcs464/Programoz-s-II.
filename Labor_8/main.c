#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "functions.h"

int main() {
    printf("Jatek:\n");
    int n;

    printf("Adja meg a szamsor hosszat (N): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Hibas bemenet.\n");
        return 1;
    }

    int arr[1000];

    srand(time(NULL));

    printf("A generalt szamsor: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
        printf("%d ", arr[i]);
    }
    printf("\n");

    int sum1, sum2;

    play_greedy_game(arr, n, &sum1, &sum2);

    int winner_sum = (sum1 > sum2) ? sum1 : sum2;
    printf("Az elso jatekos osszege: %d\n", sum1);
    printf("A masodik jatekos osszege: %d\n", sum2);
    printf("A nyertes osszeg: %d\n", winner_sum);

    printf("\n\nHatizsak I.:\n");
    int item_count, max_kapacitas;

    printf("Adja meg a targyak szamat (N): ");
    if (scanf("%d", &item_count) != 1 || item_count <= 0 || item_count > 1000) {
        printf("Hibas bemenet.\n");
        return 1;
    }

    printf("Adja meg a hatizsak kapacitasat (K): ");
    if (scanf("%d", &max_kapacitas) != 1 || max_kapacitas <= 0) {
        printf("Hibas bemenet.\n");
        return 1;
    }
    int meret_tomb[1000];
    srand(time(NULL));

    printf("A generalt targyak terfogatai: ");
    for (int h = 0; h < item_count; h++) {
        meret_tomb[h] = rand() % 50 + 1;
        printf("%d ", meret_tomb[h]);
    }
    printf("\n");

    int kivalasztott_elemek[1000];
    int eltarolt_mennyiseg;
    int elhasznalt_teremtek;

    fill_knapsack_greedy(meret_tomb, item_count, max_kapacitas, kivalasztott_elemek, &eltarolt_mennyiseg, &elhasznalt_teremtek);

    printf("\nA hatizsakba betett targyak terfogatai: ");
    for (int g = 0; g < eltarolt_mennyiseg; g++) {
        printf("%d ", kivalasztott_elemek[g]);
    }
    printf("\n");
    printf("Osszesen betett terfogat: %d / %d\n", elhasznalt_teremtek, max_kapacitas);

    return 0;
}