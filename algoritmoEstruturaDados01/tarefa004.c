#include <stdio.h>

void aplicar_powerup_pontuacao_dupla(int *pi);

int main() {
    int pontuacao_jogador = 1500;
    printf("Pontuacao antes de power-up: %d\n", pontuacao_jogador);
    int *pontuacao_power;
    pontuacao_power = &pontuacao_jogador;
    aplicar_powerup_pontuacao_dupla(pontuacao_power);
    printf("Pontuacao apos o power-up: %d\n", pontuacao_jogador);
    return 0;
}

void aplicar_powerup_pontuacao_dupla(int *pi) {
    *pi = *pi * 2;    
}