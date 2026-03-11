#include <stdio.h>
#include <stdlib.h>

void BT (int *x, int n, int k);
bool igeretes (int *x, int n, int k);
void kiir (int *x, int n, int k);

int main(void) {
    int n;
    printf("n: ");
    scanf("%d",&n);
    int *x=(int *)malloc(n*sizeof(int));
    if (!x) {
        printf("Memory allocation error!");
        return -1;
    }
    BT(x,n,0);
    return 0;
}

void BT (int *x, int n, int k) {
    for (x[k]=1; x[k]<=n; x[k]++) {
        if (igeretes (x, n, k)) {
            if (k<n-1) {
                BT (x, n, k+1);
            }
            else {
                kiir(x,n,k);
            }
        }
    }
}

bool igeretes (int *x, int n, int k) {
    for (int i=0; i<k; i++) {
        if (x[k]==x[i]) {
            return false;
        }
    }
    return true;
}

void kiir (int *x, int n, int k) {
    for (int i=0; i<n; i++) {
        printf("%d ",x[i]);
    }
    printf("\n");
}