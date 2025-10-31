#include <stdio.h>

typedef struct {
    char nome[10];
    int hp;
} monstro;

void ler(monstro *mo) {
    scanf("%s %d", mo->nome, &mo->hp);
}

int main() {
    int n;
    printf("Quantidade de monstros:\n");
    scanf("%d", &n);
    monstro v[n];
    int i;
    for(i=0; i<n; i++) {
        printf("Nome e hp:\n");
        ler(&v[i]);
    }
    monstro menor = v[0];
    for(i=0; i<n; i++) {
        if(v[i].hp < menor.hp) {
            menor = v[i];
        }
    }
    printf("Alvo prioritario: %s (HP: %d)\n", menor.nome, menor.hp);
}