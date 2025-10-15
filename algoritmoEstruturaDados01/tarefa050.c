#include <stdio.h>

int main() {
    float forca;
    float bonusArma;
    float bonusBuff;
    printf("Digite a forca, bonus da arma e bonus do feitico\n");
    scanf("%f %f %f", &forca, &bonusArma, &bonusBuff);
    float dano = forca + bonusArma + bonusBuff;
    printf("Dano total: %.2f", dano);
}