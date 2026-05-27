//
// Created by nadys on 5/27/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int** read_matrix(const char* filename, int* n) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Hiba: Nem sikerult megnyitni a bemeneti fajlt");
        return NULL;
    }

    // N beolvasása
    if (fscanf(file, "%d", n) != 1) {
        fclose(file);
        return NULL;
    }

    // 2xN mátrix dinamikus foglalása
    int** matrix = (int**)malloc(2 * sizeof(int*));
    matrix[0] = (int*)malloc(*n * sizeof(int));
    matrix[1] = (int*)malloc(*n * sizeof(int));

    // Mátrix feltöltése
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < *n; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }

    fclose(file);
    return matrix;
}

void free_matrix(int** matrix) {
    if (matrix) {
        free(matrix[0]);
        free(matrix[1]);
        free(matrix);
    }
}

void print_matrix(int n, int** matrix) {
    if (!matrix) return;

    printf("A beolvasott matrix (%d oszloppal):\n", n);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            // A \t gondoskodik róla, hogy a többjegyű számok is szépen igazodjanak
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int find_max_greedy_path(int n, int** matrix) {
    if (n <= 0) return 0;

    // A béka az utolsó oszlopból indul, kiválasztja az itteni maximumot
    int current_col = n - 1;
    int sum = matrix[0][current_col] > matrix[1][current_col] ? matrix[0][current_col] : matrix[1][current_col];

    while (current_col > 0) {
        // Ha már csak 1 oszlop van hátra, csak 1-et ugorhat a célba
        if (current_col == 1) {
            int max_val = matrix[0][0] > matrix[1][0] ? matrix[0][0] : matrix[1][0];
            sum += max_val;
            current_col = 0; // Elértük az első oszlopot
        } else {
            // Mohó döntés: Megvizsgáljuk az 1 ugrásnyira és 2 ugrásnyira lévő mindkét sort
            int val_1_jump_row0 = matrix[0][current_col - 1];
            int val_1_jump_row1 = matrix[1][current_col - 1];
            int val_2_jump_row0 = matrix[0][current_col - 2];
            int val_2_jump_row1 = matrix[1][current_col - 2];

            int max_val = val_1_jump_row0;
            int step = 1; // Alapértelmezetten 1-et ugrunk

            if (val_1_jump_row1 > max_val) {
                max_val = val_1_jump_row1;
                step = 1;
            }
            // Csak akkor ugrunk kettőt, ha Szigorúan nagyobb értéket ad (lásd 2. feltételezés)
            if (val_2_jump_row0 > max_val) {
                max_val = val_2_jump_row0;
                step = 2;
            }
            if (val_2_jump_row1 > max_val) {
                max_val = val_2_jump_row1;
                step = 2;
            }

            sum += max_val;
            current_col -= step;
        }
    }

    return sum;
}