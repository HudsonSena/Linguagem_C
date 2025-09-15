#include <stdio.h>
#include <stdlib.h>
int main(){
    int *duracaco_fumaca = (int *) malloc(sizeof(int));
    if(duracaco_fumaca==NULL){
        printf("Erro");
    } else {
        *((int *) duracaco_fumaca) = 5;
    }
    printf("Bomba de fumaca ativada! Duracao: %d segundos\n", *((int *) duracaco_fumaca));
    free(duracaco_fumaca);
    duracaco_fumaca = NULL;
    printf("A fumaca se dissipou\n");
    return 0;
}