#include <stdio.h>
#include <stdlib.h>

int main(){
    void *ponteiro_duracao = malloc(sizeof(int));
    ponteiro_duracao = (int *) 10;
    printf("Power-up Super Salto ativado! Duracao: %d segundos", ponteiro_duracao);
}