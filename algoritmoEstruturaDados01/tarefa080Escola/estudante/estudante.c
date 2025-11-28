#include <stdio.h>
#include <stdlib.h>
#include "estudante.h"

struct estudante {
    int mat;
    char nome[100];
    float n1;
    float n2;
    float n3;
};

Estudante* cria(int n) {
    Estudante *v = (Estudante *) malloc(n * sizeof(Estudante));
    return v;
}

void ler(int n, Estudante *v) {
    printf("Informe os dados dos estudantes:\n");
    int i;
    for(i = 0; i < n; i++) {
        printf("Estudante %d:\n", i + 1);
        printf("Matricula: ");
        scanf("%d", &v[i].mat);
        printf("Nome: ");
        scanf("%s", v[i].nome);
        printf("Nota 1: ");
        scanf("%f", &v[i].n1);
        printf("Nota 2: ");
        scanf("%f", &v[i].n2);
        printf("Nota 3: ");
        scanf("%f", &v[i].n3);
    }
}

void media(int n, Estudante *v) {
    printf("Medias dos estudantes:\n");
    int i;
    for(i = 0; i < n; i++) {
        float media = (v[i].n1*2 + v[i].n2*3 + v[i].n3*5) / 10;
        printf("Estudante: %s, Media: %.2f\n", v[i].nome, media);
    }

}