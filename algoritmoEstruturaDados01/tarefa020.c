#include <stdio.h>
#include <stdlib.h>

int main(){
    int *ponteiro_duracao = malloc(sizeof(int));
    printf("Valor o super salto: ");
    *((int *) ponteiro_duracao) = 10;
    printf("\nPower-up Super Salto ativado! Duracao: %d segundos", *((int *) ponteiro_duracao));
    *((int *) ponteiro_duracao) -= 3;
    printf("\n3 segundos se passaram... Duracao restante: %d segundos", *((int *) ponteiro_duracao));
    free(ponteiro_duracao);
    return 0;
}