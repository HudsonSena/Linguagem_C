#include <stdio.h>

typedef struct {
    int posX;
    int posY;
    int moedas;
} Personagem;

void atualizarPersonagemComPonteiro(Personagem *jogador);

int main() {
    Personagem jogador;
    jogador.posX = 0;
    jogador.posY = 0;
    jogador.moedas = 0;
    printf("\nPosicao inicial: (%d, %d) - Moedas: %d", jogador.posX, jogador.posY, jogador.moedas);

    atualizarPersonagemComPonteiro(&jogador);

    printf("\nPosicao atualizada: (%d, %d) - Moedas: %d", jogador.posX, jogador.posY, jogador.moedas);
    return 0;
}

void atualizarPersonagemComPonteiro(Personagem *jogador){
    jogador->posX = 10;
    jogador->posY = 5;
    jogador->moedas++;
};