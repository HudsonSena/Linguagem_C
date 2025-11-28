#include <stdio.h>
#include "combate.h"

int main() {
    int ataque_base, bonus_arma;
    printf("Informe o ataque base e o bonus da arma:\n");
    scanf("%d %d", &ataque_base, &bonus_arma);
    int ataque_total = calcular_ataque_total(ataque_base, bonus_arma);

    int vida_atual, dano_sofrido;
    printf("Informe a vida inicial inimigo:\n");
    scanf("%d", &vida_atual);
    int vida_restante = aplicar_dano(vida_atual, ataque_total);
    printf("Ataque total: %d\n", ataque_total);
    printf("Vida restante: %d\n", vida_restante);

    return 0;
}