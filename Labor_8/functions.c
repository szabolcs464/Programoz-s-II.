//
// Created by nadys on 4/15/2026.
//

#include "functions.h"

void play_greedy_game(int arr[], int n, int *sum1, int *sum2) {
    int left = 0;
    int right = n - 1;
    int is_player1_turn = 1; // 1 = első játékos, 0 = második játékos

    *sum1 = 0;
    *sum2 = 0;

    while (left <= right) {
        int chosen_value;

        if (arr[left] >= arr[right]) {
            chosen_value = arr[left];
            left++;
        } else {
            chosen_value = arr[right];
            right--;
        }

        if (is_player1_turn) {
            *sum1 += chosen_value;
        } else {
            *sum2 += chosen_value;
        }

        is_player1_turn = !is_player1_turn;
    }
}

void fill_knapsack_greedy(int volumes[], int n, int k, int selected[], int *selected_count, int *total_volume) {
    int temp_volumes[1000];

    for (int i = 0; i < n; i++) {
        temp_volumes[i] = volumes[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (temp_volumes[j] < temp_volumes[j+1]) {
                int temp = temp_volumes[j];
                temp_volumes[j] = temp_volumes[j+1];
                temp_volumes[j+1] = temp;
            }
        }
    }

    *selected_count = 0;
    *total_volume = 0;
    int remaining_capacity = k;

    // Mohó algoritmus: a legnagyobbat próbáljuk berakni először
    for (int i = 0; i < n; i++) {
        if (temp_volumes[i] <= remaining_capacity) {
            selected[*selected_count] = temp_volumes[i];
            (*selected_count)++;
            *total_volume += temp_volumes[i];
            remaining_capacity -= temp_volumes[i];
        }
    }
}