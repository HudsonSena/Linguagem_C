#include <stdio.h>

int main(){
    int mapa_fase1[5][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 2, 0, 1, 1},
        {0, 0, 1, 1, 0, 1, 0, 0},
        {1, 1, 1, 1, 2, 2, 1, 1}
    };
    int p = 2;
    printf("Verificando espinhos...\n");
    for(int i=0; i<5; i++){
        for(int j=0; j<8; j++){
            if(mapa_fase1[i][j] == p){
                printf("\nEspinho encontrado na linha %d, coluna %d", i, j);
            }
        }
    }
}