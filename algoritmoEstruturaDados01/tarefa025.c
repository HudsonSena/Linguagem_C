#include <stdio.h>
#include <stdlib.h>

int main(){
    int ni;
    printf("Numero de inimigos:\n");
    scanf("%d", &ni);
    int *status_inimigos = (int *) calloc(ni, sizeof(int));
    if(status_inimigos!=NULL){
        printf("Erro na alocacao!");
        return 0;
    }
    return 0;

}