#include <stdio.h>

struct inimigo {
    int vida;
    int ataque;
    float velocidade;
};

int main(){
    struct inimigo cogumelo_zumbi;
    cogumelo_zumbi.vida = 20;
    cogumelo_zumbi.ataque = 5;
    cogumelo_zumbi.velocidade =0.8;

    struct inimigo cavaleiro_esqueleto;
    cavaleiro_esqueleto.vida = 80;
    cavaleiro_esqueleto.ataque = 15;
    cavaleiro_esqueleto.velocidade = 1.2;

    printf("--- Atributos do inimigo: Esqueleto Zumbi ---");
    printf("\nVida: %d", cogumelo_zumbi.vida);
    printf("\nAtaque: %d", cogumelo_zumbi.ataque);
    printf("\nVelocidade: %.2f", cogumelo_zumbi.velocidade);


    printf("\n--- Atributos do inimino: Cogumelo Esqueleto ---");
    printf("\nVida: %d", cavaleiro_esqueleto.vida);
    printf("\nAtaque: %d", cavaleiro_esqueleto.ataque);
    printf("\nVelocidade: %.2f", cavaleiro_esqueleto.velocidade);

    return 0;
}