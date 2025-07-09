#include <stdio.h>

int main(){
    float me;
    int m[5][3];
    int s=0;
    int i, j, a, b;
    for(i=0; i<5; i++){
        for(j=0; j<3; j++){
            printf("Nota %i Aluno %i: ", j, i);
            scanf("%i", &m[i][j]);
        }
    }

    for(a=0; a<5; a++){
        for(b=0; b<3; b++){
            s = s + m[a][b];
        }

        me = s/3;
        printf("Aluno %i, %f", a, me);
        printf("\n");
    }

}