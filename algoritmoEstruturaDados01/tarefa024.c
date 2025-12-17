#include <stdio.h>
#include <stdlib.h>
int main(){
    //! showMemory(start=290)
    int l, c, i, j, n1=0;
    printf("Digite o numero de linhas e colunas:\n");
    scanf("%d %d", &l, &c);
    int **mapa = (int **) malloc(l * sizeof(int *));
    for(i=0; i<l; i++){
        mapa[i] = (int *) malloc(c * sizeof(int));        
    }
    if(mapa==NULL){
        printf("Nao alocada-o");
    }
    for(i=0; i<l; i++){
        for(j=0; j<c; j++){
            printf("Digite 0, 1 ou 2:\n");
            scanf("%d", (int *) mapa + (c * i) + j);
        }
    }
    for(i=0; i<l; i++){
        for(j=0; j<c; j++){
            printf("%d ", *((int *) mapa + (c * i) + j));
            if(*((int *) mapa + (c * i) + j)==1){
                n1++;
            }
        }
        printf("\n");
    }
    printf("O mapa possui %d blocos de tijolos", n1);
    free(mapa);

    return 0;
}