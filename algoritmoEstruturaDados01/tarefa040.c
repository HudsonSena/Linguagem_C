#include <stdio.h>

typedef struct {
    char nome[50];
    int pontuacao;
} jogador;

int main() {
    int n;
    printf("Quantidade de jogadores:\n");
    scanf("%d", &n);
    jogador v[n];
    FILE *file = fopen("../highscores.txt", "w");
    int i;
    for(i=0; i<n; i++) {
        printf("Jogador e Pontuacao:\n");
        scanf("\n%s %i", v[i].nome, &v[i].pontuacao);
    }
    jogador maior = v[0];
    for(i=0; i<n; i++) {
        if(v[i].pontuacao > maior.pontuacao) {
            maior = v[i];
        }
    }
    fprintf(file, "Nome: %s, Pontuacao: %i", maior.nome, maior.pontuacao);
    fclose(file);
}