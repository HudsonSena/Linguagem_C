#include <stdio.h>

typedef struct {
    int saude;
    int pontuacao;
    int posX;
    int posY;
} Heroi;

int main() {
    Heroi meuHeroi = {100, 0, 0, 0};
    printf("\nStatus: %d %d %d %d", meuHeroi.saude, meuHeroi.pontuacao, meuHeroi.posX, meuHeroi.posY);
    Heroi *ptrHeroi = &meuHeroi;
    
    (*ptrHeroi).saude = (*ptrHeroi).saude -25;
    printf("\nSaude: %d", (*ptrHeroi).saude);
    
    (*ptrHeroi).pontuacao = (*ptrHeroi).pontuacao +50;
    printf("\nPontucao: %d", (*ptrHeroi).pontuacao);
    
    (*ptrHeroi).posX = (*ptrHeroi).posX +10;
    printf("\nPosicao X: %d", (*ptrHeroi).posX);
    
    (*ptrHeroi).posY = (*ptrHeroi).posY -5;
    printf("\nPosicao Y: %d", (*ptrHeroi).posY);

    printf("\n********************");
    printf("\nStatus: %d %d %d %d", ptrHeroi->saude, ptrHeroi->pontuacao, ptrHeroi->posX, ptrHeroi->posY);

    return 0;
}