#include <stdio.h>
#include <stdlib.h>

int main(){
    void *ponteiro_duracao = malloc(sizeof(int));
    printf("Valor o super salto: ");
    scanf("%d", ((int *) ponteiro_duracao));
    printf("\nPower-up Super Salto ativado! Duracao: %d segundos", *((int *) ponteiro_duracao));
    ponteiro_duracao = *((int *) ponteiro_duracao -3);
    printf("\n3 segundos se passaram... Duracao restante: %d segundos", ponteiro_duracao);
    free(ponteiro_duracao);
    return 0;
}