#include <stdio.h>

typedef struct {
    char nome[50];
    int vida;
    int ataque;
} unidade;

int main() {
    FILE *file = fopen("../squad048.dat", "wb");
    int n;
    printf("Quantas unidades?\n");
    scanf("%d", &n);
    unidade v[n];
    int i;
    for(i=0; i<n; i++){
        printf("Nome, nivel e ataque:\n");
        scanf("%s %d %d", v[i].nome, &v[i].vida, &v[i].ataque);
    }
    fwrite(v, sizeof(unidade), n, file);
    unidade maior = v[0];
    for(i=0; i<n; i++){
        if(v[i].ataque > maior.ataque){
            maior = v[i];
        }
    }
    printf("O maior pode de ataque eh do: %s", maior.nome);
    fclose(file);
}