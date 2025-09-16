#include <stdio.h>
#include <stdlib.h>

int main(){
    int *mochila = (int *) malloc(3 * sizeof(int));
    for(int i=0; i < 3; i++){
        printf("Digite um valor:\n");
        scanf("%d", mochila +i);
    }
    for(int i=0; i<3; i++){
        printf("%d ", *(mochila +i));
    }
    mochila = (int *) realloc(mochila, 2 * 3 * sizeof(int));
    for(int i=3; i < 6; i++){
        printf("\nDigite + um valor:\n");
        scanf("%d", mochila +i);
    }
    for(int i=0; i<6; i++){
        printf("%d ", *(mochila +i));
    }
    free(mochila);
    return 0;
}