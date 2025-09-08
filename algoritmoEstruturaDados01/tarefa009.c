#include <stdio.h>

int main(){
    int moedas_coletadas[] = {10, 50, 20, 5, 100};
    int pontuacao_total = 0;
    int *ponteiro_moeda = moedas_coletadas;

    for(int i=0; i<5; i++){
        pontuacao_total += *(ponteiro_moeda + i);
    }

    printf("Pontuacao total do nivel: %d", pontuacao_total);

}