#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void BT (int *x, int n, int k, int v);
bool igeretes (int *x, int n, int k, int v);
void kiir (int *x, int n, int k, int v);

int main(void) {
    int n, v;
    printf("n: ");
    scanf("%d",&n);
    printf("v: ");
    scanf("%d",&v);
    int *x=(int *)malloc(n*sizeof(int));
    if (!x) {
        printf("Memory allocation error!");
        return -1;
    }
    BT(x,n,0,v);
    return 0;
}

void BT (int *x, int n, int k, int v) {
    for (x[k]=1; x[k]<=n; x[k]++) {
        if (igeretes (x, n, k, v)) {
            if (k<v-1) {
                BT (x, n, k+1, v);
            }
            else {
                kiir(x,n,k,v);
            }
        }
    }
}

bool igeretes (int *x, int n, int k, int v) {
    for (int i=0; i<k; i++) {
        if (x[k]<=x[i]) {
            return false;
        }
    }
    return true;
}

void kiir (int *x, int n, int k, int v) {
    for (int i=0; i<v; i++) {
        printf("%d ",x[i]);
    }
    printf("\n");
}