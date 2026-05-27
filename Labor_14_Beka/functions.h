//
// Created by nadys on 5/27/2026.
//

#ifndef LABOR__4_BEKA_FUNCTIONS_H
#define LABOR__4_BEKA_FUNCTIONS_H

int** read_matrix(const char* filename, int* n);

void free_matrix(int** matrix);

void print_matrix(int n, int** matrix);

int find_max_greedy_path(int n, int** matrix);

#endif //LABOR__4_BEKA_FUNCTIONS_H