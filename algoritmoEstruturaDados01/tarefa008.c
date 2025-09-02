#include <stdio.h>

int main(){
    int fase[] = {0, 1, 0, 0, 1, 1, 0, 1, 0};
    int *ponteiro_jogador;
    int moedas_coletadas = 0;
    ponteiro_jogador = &fase;

    for(int i=0; i<9; i++){
        if(*(ponteiro_jogador + i) == 1){
            moedas_coletadas += *(ponteiro_jogador + i);
        }
    }

    printf("O jogador coletou um total de %d moedas", moedas_coletadas);

    return 0;
}