#include <stdio.h>

typedef struct {
    int mat;
    char nome[10];
} estudante;

void ler(estudante *pe) {
    scanf("%d %s", &pe->mat, pe->nome);
}

int main() {
    int n;
    printf("Informe o valor de n\n");
    scanf("%d", &n);
    estudante v[n];
    int i;
    for(i=0; i<n; i++){
        ler(&v[i]);
    }
    estudante menor = v[0];
    for(i=0; i<n; i++) {
        if(v[i].mat < menor.mat) {
            menor = v[i];            
        }
    }
    printf("%s: %d", menor.nome, menor.mat);
}