#include <stdio.h>

typedef struct {
    char nome[50];
    int eli;
} jogador;

void ler(jogador *pe) {
    scanf("%s %d", pe->nome, &pe->eli);
}

int main() {
    int n;
    printf("Numero de jogadores:\n");
    scanf("%d", &n);
    jogador v[n];
    int i, j;
    for(i=0; i<n; i++) {
        ler(&v[i]);
    }
    for(i=0; i<n; i++) {
        int imaior = i;
        for(j=i+1; j<n; j++)
        if(v[j].eli > v[imaior].eli) {
            imaior = j;
        }
        jogador temp = v[i];
        v[i] = v[imaior];
        v[imaior] = temp;
    }
    for(i=0; i<n; i++) {
        printf("%s: %d\n", v[i].nome, v[i].eli);
    }
}