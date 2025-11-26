#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
    int mat;
    char nome[100];
} estudante;

int particiona(int e, int d, estudante v[]) {
    estudante pivo = v[d];
    int j = e - 1;
    int i;
    for(i=e; i<d; i++) {
        if(v[i].mat <= pivo.mat) {
            j++;
            estudante temp = v[j];
            v[j] = v[i];
            v[i] = temp;
        }
    }
    estudante temp = v[j+1];
    v[j+1] = v[d];
    v[d] = temp;
    return j + 1;
}

void quicksort(int i, int f, estudante v[]) {
    if(i<f) {
        int p = particiona(i, f, v);
        quicksort(i, p-1, v);
        quicksort(p+1, f, v);
    }
}

void ler(estudante *pe) {
    scanf("%d %s", &pe->mat, pe->nome);
}

int main() {
    int n;
    printf("Informe o valor de n\n");
    scanf("%d", &n);
    estudante v[n];
    int i;
    for(i=0; i<n; i++) {
        ler(&v[i]);
    }
    quicksort(0, n-1, v);
    printf("Vetor ordenado\n");
    for(i=0; i<n; i++) {
        printf("%d %s\n", v[i].mat, v[i].nome);
    }
    printf("\n");
}