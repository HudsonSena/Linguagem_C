#include <stdio.h>

typedef struct {
    int id;
    int pontos;
} jogador;

void bolha(int n, jogador v[]) {
    int i, j;
    for(i=0; i<n-1; i++) {
        int trocou = 0;
        for(j=0; j<n-i-1; j++) {
            if(v[j].pontos < v[j+1].pontos) {
                jogador temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                trocou = 1;
            }
        }
        if(trocou == 0) {
            return;
        }
    }
}

void ler(jogador *pe) {
    scanf("%d %d", &pe->id, &pe->pontos);
}

int main() {
    int n;
    printf("Quantidade de jogadores\n");
    scanf("%d", &n);
    jogador v[n];
    int i;
    for(i=0; i<n; i++) {
        ler(&v[i]);
    }
    bolha(n, v);
    for(i=0; i<n; i++) {
        printf("%d: %d\n", v[i].id, v[i].pontos);
    }
    printf("\n");
}