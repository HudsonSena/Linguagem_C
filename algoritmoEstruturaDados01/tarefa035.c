#include <stdio.h>

typedef struct {
    char nome[50];
    int valor_pontos;
} ItemColetavel;

int main() {
    ItemColetavel inventario[3];
    for(int i=0; i<3; i++){
        printf("Digite o nome e o valor em pontos:\n");
        scanf("%s %d", inventario[i].nome, &inventario[i].valor_pontos);
    }

    ItemColetavel valioso;
    valioso = inventario[0];
    for(int i=1; i<3; i++){
        if(inventario[i].valor_pontos > valioso.valor_pontos){
            valioso = inventario[i];
        }
    }
    printf("O item mais valioso coletado foi: %s", valioso.nome);
}