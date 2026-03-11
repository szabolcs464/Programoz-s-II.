#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void BT (int *x, int n, int k, int v, char nevek[][30]);
bool igeretes (int *x, int n, int k, int v);
void kiir (int *x, int n, int k, int v, char nevek[][30]);

int main(void) {
    int n, v;
    char nevek [][30] = {"Hat Izsak","Vicc Elek","Terd Kalacs","Kelep Elek","Spadermen Gabor","Semafor Armando","Ispilante Sentiment Brusli","Super Mario","Luigi"};
    printf("n: ");
    scanf("%d",&n);
    printf("v: ");
    scanf("%d",&v);
    int *x=(int *)malloc(n*sizeof(int));
    if (!x) {
        printf("Memory allocation error!");
        return -1;
    }
    BT(x,n,0,v,nevek);
    return 0;
}

void BT (int *x, int n, int k, int v, char nevek[][30]) {
    for (x[k]=1; x[k]<=n; x[k]++) {
        if (igeretes (x, n, k, v)) {
            if (k<v-1) {
                BT (x, n, k+1, v, nevek);
            }
            else {
                kiir(x,n,k,v,nevek);
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

void kiir (int *x, int n, int k, int v, char nevek[][30]) {
    for (int i=0; i<v; i++) {
        printf("%s ",nevek[x[i]-1]);
    }
    printf("\n");
}