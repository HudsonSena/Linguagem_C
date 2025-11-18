#include <stdio.h>

typedef struct {
    int mat;
    char nome[100];
} estudante;

void ler(estudante *pe) {
    scanf("%d %s", &pe->mat, pe->nome);
}

int main() {
    int n;
    printf("Informe o valor de n\n");
    scanf("%d", &n);
    estudante v[n];
    int i, j;
    for(i=0; i<n; i++) {
        ler(&v[i]);
    }
    for(i=1; i<n; i++) {
        estudante x = v[i];
        for(j=i-1; j>=0 && x.mat < v[j].mat; j--) {
            v[j+1] = v[j];
        }
        v[j+1] = x;
    }
    printf("Imprimindo o vetor\n");
    for(i=0; i<n; i++) {
        printf("%d %s\n", v[i].mat, v[i].nome);
    }
    printf("\n");
}