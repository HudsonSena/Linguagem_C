#include <stdio.h>

int main(){
    int vida_jogador = 100;//Variável Vida
    int *ponteiro_vida;//ponteiro

    //Simulador de Dano
    vida_jogador = vida_jogador -50;
    printf("O jogador sofreu dano! Vida Atual: %d\n", vida_jogador);

    //Aplicando o valor com o ponteiro
    ponteiro_vida = &vida_jogador;
    *ponteiro_vida = *ponteiro_vida + 50;

    // imprimindo o valor
    printf("Power-up coletado! Vida restaurada: %d", vida_jogador);    

    return -1;
}