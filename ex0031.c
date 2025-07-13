#include <stdio.h>

int main(){
    int m[3][3], i, j, a, b;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("Digite um valor para a posicao %i %i :", i, j);
            scanf("%i", &m[i][j]);
        }        
    }

    for(a=2; a> -1; a--){
        for(b=2; b> -1; b--){
            printf("%i  ", m[a][b]);
        }    
        printf("\n");      
    }

    return 0;
}