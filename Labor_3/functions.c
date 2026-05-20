//
// Created by nadys on 3/4/2026.
//

#include "functions.h"

#include <stdio.h>
#include <stdlib.h>

void kiir(char v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%c ", v[i]);
    }
    printf("\n");
}

void rendezes(int v[], int n) {
    char temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i; j < n; j++) {
            if (v[i] > v[j]) {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

static void merge(char arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char *L = (char*)malloc(n1 * sizeof(char));
    char *R = (char*)malloc(n2 * sizeof(char));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(char arr[], int left, int right){
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void kereses(int v[], int n) {
    int x;
    printf("\nSzam kereses: ");
    scanf("%d", &x);
    for (int i = 0; i < n; i++) {
        if (v[i] == x) {
            printf("Ez a szam benne van!\n");
            return;
        }
    }
    printf("Ez a szam nincs benne!\n");
}

void binariskereses(int v[], int jobb) {
    int x;
    printf("\nSzam kereses: ");
    scanf("%d", &x);
    int bal=0,kozep;
    jobb--;
    while (bal < jobb) {
        kozep = bal + (jobb - bal) / 2;
        if (v[kozep] == x) {
            printf("Ez a szam benne van!\n");
            return;
        }
        if (v[kozep] < x) {
            bal = kozep + 1;
        }
        else {
            jobb = kozep - 1;
        }
    }
    printf("Ez a szam nincs benne!\n");
}