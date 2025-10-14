#include <stdio.h>

typedef struct {
    char nome[50];
    int nivel;
    int highScore;
} playerProfile;

int main() {
    FILE *file = fopen("../profiles.dat", "rb");
    if(file == NULL) {
        printf("Erro: Arquivo nao lido");
        exit(1);
    }
    playerProfile p;
    while(fread(&p, sizeof(playerProfile), 1, file)) {
        printf("Nome: %s\n", p.nome);
        printf("High Score: %d\n", p.highScore);
        if(p.highScore>10000) {
            printf("Rank: Mestre do jogo\n");
        } else if(p.highScore > 5000) {
            printf("Rank: Veterano\n");
        } else {
            printf("Rank: Aspirante\n");
        }
    }
    printf("Programa finalizado\n");
    fclose(file);
}