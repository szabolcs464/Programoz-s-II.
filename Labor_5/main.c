#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void BT (int *x, int n, int k, char szinek[][10]);
bool igeretes (int *x, int n, int k);
void kiir (int *x, int n, int k, char szinek[][10]);

int main(void) {
    int n;
    printf("n: ");
    scanf("%d",&n);
    int *x=(int *)malloc(n*sizeof(int));
    if (!x) {
        printf("Memory allocation error!");
        return -1;
    }
    char szinek[][10] = {"kek", "sarga", "zold"};
    BT(x,n,0,szinek);
    return 0;
}

void BT (int *x, int n, int k, char szinek[][10]) {
    for (x[k]=0; x[k]<=1; x[k]++) {
        if (igeretes (x, n, k)) {
            if (k<n-1) {
                BT (x, n, k+1, szinek);
            }
            else {
                kiir(x,n,k,szinek);
            }
        }
    }
}

bool igeretes (int *x, int n, int k) {
    return true;
}

void kiir (int *x, int n, int k, char szinek[][10]) {
    for (int i=0; i<n; i++) {
        if (x[i]) {
            printf("%s ", szinek[i]);
        }
    }
    printf("\n");
}