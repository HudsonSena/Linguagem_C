#include "heroi.h"
#include <stdlib.h>
#include <stdio.h>

struct heroi {
    char nome[50];
    int hp;
    int ataque;
};

Heroi* cria(int n) {
    Heroi * v = (Heroi *) malloc(n * sizeof(Heroi));
    return v;
}

void ler(int n, Heroi *v) {
    printf("Informe os dados dos herois (nome, hp, ataque):\n");
    int i;
    for(i = 0; i < n; i++) {
        scanf("%s %d %d", v[i].nome, &v[i].hp, &v[i].ataque);
    }
}

void imprimir(int n, Heroi *v) {
    printf("Imprimindo os herois:\n");
    int i;
    for(i = 0; i < n; i++) {
        printf("Nome: %s, HP: %d, Ataque: %d\n", v[i].nome, v[i].hp, v[i].ataque);
    }
}