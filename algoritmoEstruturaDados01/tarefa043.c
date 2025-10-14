#include <stdio.h>

typedef struct {
    char nome[50];
    int vida;
    int ataque;
} inimigo;

int main() {
    FILE *file = fopen("../wave_data.txt", "r");
    if(file == NULL){
        printf("Erro: Arquivo não lido\n");
        exit(1);
    }
    inimigo in;
    inimigo maior;
    maior.ataque = 0;
    while(fscanf(file, "%s %d %d", in.nome, &in.vida, &in.ataque) != EOF){
        if(in.ataque > maior.ataque) {
            maior = in;
        }
    }
    printf("Maior Ameaca: %s\nVida: %d\nAtaque: %d\n", maior.nome, maior.vida, maior.ataque);
    fclose(file);
}