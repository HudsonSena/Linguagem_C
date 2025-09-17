#include <stdio.h>
#include <stdlib.h>

int main(){
    //! showMemory(start=65520)
    int n_inimigos;
    int *ponteiro_onda;
    printf("Quantos inimigos a onda tera?\n");
    scanf("%d", &n_inimigos);
    ponteiro_onda = (int *) malloc(n_inimigos * sizeof(int));
    if(ponteiro_onda!=NULL){
        printf("Memoria alocada");
    }
    for(int i=0; i<n_inimigos; i++){
        printf("Digite o ID. EX(101):\n");
        scanf("%d", ponteiro_onda + i);
    }
    printf("Onda de inimigos criada com sucesso! IDs: ");
    for(int i=0; i<n_inimigos; i++){
        printf("%d ", *(ponteiro_onda + i));
    }
    return 0;
}