#include <stdio.h>
#include <stdlib.h>
int main(){
    int *vida_inimigo = (int *) malloc(4);
    if(vida_inimigo == NULL){
        printf("Erro");
        return 0;
    }
    *vida_inimigo = 80;
    printf("Um novo inimigo apareceu com %d de vida.", *vida_inimigo);
    *vida_inimigo = *vida_inimigo - 35;
    printf("O jogador atacou! Vida restante do inimigo: %d", *vida_inimigo);
}