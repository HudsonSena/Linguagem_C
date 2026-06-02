#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int matriz[a][b];
    for(int i=0; i<a; i++) {
        for(int j=0; j<b; j++) {
            matriz[i][j] = {I, J}
        }
    }
    printf("\n");
    for(int i=0; i<a; i++) {
        for(int j=0; j<b; j++) {
            printf("[ %d ]", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}

0,0 1,1 2,2 3,3 4,4 
1,0 1,1 1,2 1,3 1,4

0 = {0,0]0,1 0,2 0,3 0,4}
1 = {1,0 1,1 1,2 1,3 1,4}