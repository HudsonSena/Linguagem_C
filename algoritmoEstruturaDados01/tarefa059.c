#include <stdio.h>

typedef struct {
    int id;
    char nome[50];
    int hp;
    int ataque;
} Monstro;

void ler(Monstro *mo) {
    scanf("%d %s %d %d", &mo->id, mo->nome, &mo->hp, &mo->ataque);
}

void menu() {
    printf("======== Menu de opcoes =======\n");
    printf("1 - Procurar monstro\n");
    printf("2 - Sair\n");
    printf("===============================\n");
}

int buscabinaria(int id, Monstro v[], int i, int f) {
    if(i > f) return -1;
    int meio = (i + f)/2;
    if(v[meio].id == id) {
        return meio;
    }
    if(v[meio].id < id) {
        return buscabinaria(id, v, meio + 1, f);
    }
    return buscabinaria(id, v, i, meio -1);
}

int main() {
    int n;
    printf("Quantos monstros?\n");
    scanf("%d", &n);
    Monstro v[n];
    int i;
    for(i=0; i<n; i++) {
        printf("Monstro %d, ID Nome HP Ataque:\n", i +1);
        ler(&v[i]);
    }
    int op;
    menu();
    scanf("%d", &op);
    while(op != 2) {
        if(op == 1) {
            int id;
            printf("Id do Monstro:\n");
            scanf("%d", &id);
            int idx = buscabinaria(id, v, 0, n - 1);
            if(idx != -1) {
                printf("==================================================\n");
                printf("Monstro encontrado: %s (ID: %d) HP: %d Ataque: %d\n", v[idx].nome, v[idx].id, v[idx].hp, v[idx].ataque);
                printf("==================================================\n");
                
            } else {
                printf("Monstro com ID %d, nao encontrado\n", id);
            }
        }
        menu();
        scanf("%d", &op);        
    }
    printf("Programa finalizado");
}