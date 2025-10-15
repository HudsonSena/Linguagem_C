#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} unidade;

int main(){
    int n;
    printf("Quantas unidades inimigas:\n");
    scanf("%d", &n);
    unidade *u;
    u = (unidade *) malloc(n * sizeof(unidade));
    int i, j;
    for(i=0; i<n; i++){
        printf("Digite as coordenadas x e y da Unidade %d:\n", i+1);
        scanf("%d %d", (u+i), ((u+i)+1));
    }
    for(i=0; i<n; i++){
        printf("(%d, %d)\n", u[i].x, u[i].y);
    }
    double raio = 10.2;
    double distancia;
    int cont = 0;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++){
            if(j>=i && j<n){
                printf("\nInterecao i: %d,  j: %d", i, j);
                distancia = sqrt(pow(u[j].x - u[i].x, 2) + pow(u[j].y - u[i].y, 2));
                printf("\n%f", distancia);
                if(distancia <= raio){
                    cont++;
                }
            }            
        }
    }
    printf("\nDuplas proximas: %i\n", cont);
    free(u);
}