#include <stdio.h>

int main(){
    int ma[2][3], mb[2][3], a, b, i, j, c, d;
    for(i=0; i<2; i++){
        for(j=0; j<3; j++){
            printf("Matriz A. Para posicao %i %i: ", i, j);
            scanf("%i", &ma[i][j]);
        }
    }

    printf("**************\n");

    for(a=0; a<2; a++){
        for(b=0; b<3; b++){
            printf("Matriz B. Para posicao %i %i: ", a, b);
            scanf("%i", &mb[a][b]);
        }
    }

    for(c=0; c<2; c++){
        for(d=0; d<3; d++){
            printf("%i  ", ma[c][d] + mb[c][d]);            
        }
        printf("\n");
    }
    
}