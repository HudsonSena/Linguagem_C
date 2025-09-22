#include <stdio.h>

struct jogador {
    float pos_X;
    int pontuacao;
    int tem_pulo_duplo;
};

int main(){
    struct jogador heroi;
    heroi.pos_X = 50.0;
    heroi.pontuacao = 0;
    heroi.tem_pulo_duplo = 0;

    printf("\nInicio da fase! Posicao X: %.2f, Pontos: %d, Pulo Duplo: %d", heroi.pos_X, heroi.pontuacao, heroi.tem_pulo_duplo);
    heroi.pontuacao = heroi.pontuacao + 10;
    heroi.tem_pulo_duplo = 1;

    printf("\nItens coletados! Posicao X: %.2f, Pontos: %d, Pulo Duplo: %d", heroi.pos_X, heroi.pontuacao, heroi.tem_pulo_duplo);
    
    return 0;
}