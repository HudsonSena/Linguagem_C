#include <stdio.h>
#include <stdlib.h>

int main(){
    int ni;
    printf("Numero de inimigos:\n");
    scanf("%d", &ni);
    int *status_inimigos = (int *) calloc(ni, sizeof(int));
    if(status_inimigos==NULL){
        printf("Erro na alocacao!");
        return 0;
    }
    for(int i=0; i<ni; i++){
        printf("Inimigo %d: Inativo (%d)\n", i, *(status_inimigos +i));
    }
    for(int i=0; i<ni; i++){
        *(status_inimigos +i) = 1;
    }

    for(int i=0; i<ni; i++){
        printf("Inimigo %d: Ativo (%d)\n", i, *(status_inimigos +i));
    }
    free(status_inimigos);
    return 0;
}