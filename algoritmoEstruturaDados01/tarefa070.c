#include <stdio.h>

// Função que conta a quantidade de números pares em um vetor usando divisão e conquista
int pares(int i, int f, int v[]) {
    if(i<f) {
        int m = (i+f)/2;
        int e = pares(i, m, v);
        int d = pares(m+1, f, v);
        return (e > d) ? e : d;
    }
    if(v[i] > v[0]) return v[i];
    return v[0];
}

int main() {
    int n;
    printf("Quantidade de fragmentos:\n");
    scanf("%d", &n);
    int v[n];
    int i;
    for(i=0; i<n; i++) {
        printf("Valor do fragmento na posicao [%d]:\n", i);
        scanf("%d", &v[i]);
    }
    int r = pares(0, n-1, v);
    printf("Maior poder dos fragmentos: %d\n", r);
}