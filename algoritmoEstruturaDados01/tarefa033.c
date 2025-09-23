#include <stdio.h>

struct posicao {
    int x;
    int y;
};

int main() {
    struct posicao posicao_jogador = {0, 0};
    struct posicao *ponteiro_posicao = &posicao_jogador;
    printf("Posicao inicial do jogador: X=%d, Y=%d", (*ponteiro_posicao).x, ponteiro_posicao->y); 
    return 0;
}