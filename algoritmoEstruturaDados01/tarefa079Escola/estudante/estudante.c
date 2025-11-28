#include <stdio.h>
#include <stdlib.h>
#include "estudante.h"

struct estudante {
    int mat;
    char nome[100];
};

Estudante* cria(int n) {
    Estudante * v = (Estudante *) malloc(n * sizeof(Estudante));
    return v;
}

void ler(int n, Estudante *v) {
    printf("Informe os dados dos estudantes (matricula e nome):\n");
    int i;
    for(i = 0; i < n; i++) {
        scanf("%d %s", &v[i].mat, v[i].nome);
    }
}

void imprimir(int n, Estudante *v) {
    printf("Imprimindo os estudantes:\n");
    int i;
    for(i = 0; i < n; i++) {
        printf("Matricula: %d, Nome: %s\n", v[i].mat, v[i].nome);
    }
}