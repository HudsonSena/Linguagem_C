#include <stdio.h>

typedef struct {
    int posicao_x;
    int posicao_y;
    int valor;
} Moedas;

int main() {
    int n, i;
    printf("Quantas moedas serao cadastradas\n");
    scanf("%d", &n);
    Moedas *v= (Moedas*) malloc(n * sizeof(Moedas));
    for(i=0; i<n; i++){
        printf("Posicao x, y e o valor: ");
        scanf("%d %d %d", &v[i].posicao_x, &v[i].posicao_y, &v[i].valor);
    }
    int total_pontos;
    for(i=0; i<n; i++){
        total_pontos = total_pontos + v[i].valor;
    }
    printf("Pontuacao maxima do nivel: %i", total_pontos);
    free(v);
}