#include <stdio.h>

typedef struct {
    char nome[100];
    int pontos;
} jogador;

void ler(jogador *pe) {
    scanf("%s %d", pe->nome, &pe->pontos);
}

int main() {
    int n;
    printf("Numero de jogadores\n");
    scanf("%d", &n);
    jogador v[n];
    int i, j;
    for(i=0; i<n; i++) {
        printf("Nome e pontuacao\n");
        ler(&v[i]);
    }
    for(i=1; i<n; i++) {
        jogador x = v[i];
        for(j=i-1; j>=0 && x.pontos > v[j].pontos; j--) {
            v[j+1] = v[j];
        }
        v[j+1] = x;
    }
    for(i=0; i<n; i++) {
        printf("| %d %s ", v[i].pontos, v[i].nome);
    }
}