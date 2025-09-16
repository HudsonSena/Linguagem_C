#include <stdio.h>
#include <stdlib.h>

#define LINHAS 5
#define COLUNAS 10

int main(){    
    int *level_map = (int *) malloc(LINHAS * COLUNAS * sizeof(int));
    if(level_map==NULL){
        printf("ERRo na alocacao!");
        return 0;
    }
    for(int i=0; i<LINHAS; i++){
        for(int j=0; j<COLUNAS; j++){
            if(i==LINHAS-1){
                *((int *) level_map + i * COLUNAS + j) = 1;
            } else {
                *((int *) level_map + i * COLUNAS + j) = 0;
            }
        }
    }
    for(int i=0; i<LINHAS; i++){
        for(int j=0; j<COLUNAS; j++){
            printf("%d ", *((int *) level_map + (i * COLUNAS) + j));
        }
        printf("\n");
    }

    
    free(level_map);
}