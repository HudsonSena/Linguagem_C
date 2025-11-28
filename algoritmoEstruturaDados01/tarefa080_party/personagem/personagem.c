#include <stdio.h>
#include <stdlib.h>
#include "personagem.h"

struct personagem {
    char nome[50];
    char classe[30];
    int nivel;
    int hp;
};

Personagem* cria_party(int num_membros) {
    Personagem* party = (Personagem*) malloc(num_membros * sizeof(Personagem));
    return party;
}

void registra_membros(Personagem* party, int num_membros) {
    printf("Membros da equipe:\n");
    for(int i = 0; i < num_membros; i++) {
        printf("Membro %d:\n", i + 1);
        printf("Nome | Classe | Nivel | HP\n");
        scanf("%s %s %d %d", party[i].nome, party[i].classe, &party[i].nivel, &party[i].hp);
    }
}

void exibe_relatorio(Personagem* party, int num_membros) {
    printf("Relatorio da equipe:\n");
    for(int i = 0; i < num_membros; i++) {
        printf("Nome: %s, Classe: %s, Nivel: %d, HP: %d\n", party[i].nome, party[i].classe, party[i].nivel, party[i].hp);
    }
}

void libera_party(Personagem* party) {
    free(party);
}