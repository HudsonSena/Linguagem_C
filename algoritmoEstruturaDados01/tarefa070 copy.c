#include <stdio.h>

// Função que conta a quantidade de números pares em um vetor usando divisão e conquista
int pares(int i, int f, int v[]) {
    if(i<f) {
        int m = (i+f)/2;
        int e = pares(i, m, v);
        int d = pares(m+1, f, v);
        return e + d;
    }
    if(v[i] % 2 == 0) return 1;
    return 0;
}

int main() {
    int n;
    printf("Informe o valor de n:\n");
    scanf("%d", &n);
    int v[n];
    int i;
    for(i=0; i<n; i++) {
        printf("Informe o valor de v[%d]:\n", i);
        scanf("%d", &v[i]);
    }
    int r = pares(0, n-1, v);
    printf("Quantidade de numeros pares: %d\n", r);
}