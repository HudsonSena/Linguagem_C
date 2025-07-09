#include <stdio.h>

int main(){
    int ma[4][2];
    int i, j, a, b, c, d;
    for(i=0; i<4; i++){
        for(j=0; j<2; j++){
            printf("Digite: ");
            scanf("%i", &ma[i][j]);
        }
    }

    for(a=0; a<4; a++){
        for(b=0; b<2; b++){
            printf("%i  ", ma[a][b]);
        }
        printf("\n");
    }
    for(c=3; c> -1; c--){
        for(d=1; d> -1; d--){
            printf("%i  ", ma[a][b]);
        }
        printf("\n");
    }
}