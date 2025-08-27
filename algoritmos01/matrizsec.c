#include <stdio.h>

int main(){
    int a[3][3], x, y, s=0, c, d, e, f;
    for(x=0; x<3; x++){
        for(y=0; y<3; y++){
            printf("Digite um numero: ");
            scanf("%i", &a[x][y]);
        }
    }
    for(c=0; c<3; c++){
        for(d=0; d<3; d++){
            printf("%i ", a[c][d]);
        }
        printf("\n");
    }

    for(e=2; e> -1; e--){
        for(f=2; f> -1; f--){
            printf("%i ", a[e][f]);
        }
        printf("\n");
    }

    for(c=0; c<3; c++){
        for(d=0; d<3; d++){
            if(c+d==2){
                s = s + a[c][d];
            }
        }
    }
    printf("%i", s);
}