#include <stdio.h>

typedef struct {
    char nome[100];
    int nivel;
    int vida;
    float mana;
} personagem;

void menu() {
    printf("\n========== Menu ==========\n");
    printf("1 - Criar novo personagem\n");
    printf("2 - Sair\n");
    printf("============================\n");
}

int main() {
    FILE *file = fopen("../savegame.sav", "wb");
    menu();
    int op;
    scanf("%d", &op);
    while(op != 2) {
        if(op == 1) {
            printf("Informacoes do personagem\n");
            personagem p;
            scanf("%s %d %d %f", p.nome, &p.nivel, &p.vida, &p.mana);
            fwrite(&p, sizeof(personagem), 1, file);
        }
        menu();
        scanf("%d", &op);        
    }
    printf("Programa finalizado");
    fclose(file);
}