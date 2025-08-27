#include <stdio.h>

int main() {
    int pontuacao_jogador = 1500;
    int *ponteiro_p = &pontuacao_jogador;
    printf("Pontuacao antes do power-up: %d\n", pontuacao_jogador);
    int power = aplicar_powerup_pontuacao_dupla(ponteiro_p);
    printf("Pontuacao apos o power-up: %d\n", power);

    return 0;
}

void aplicar_powerup_pontuacao_dupla(int *pp) {
    int power = *pp * 2;
    return power;
}