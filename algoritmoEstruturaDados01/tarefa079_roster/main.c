#include <stdio.h>
#include "heroi/heroi.h"

int main() {
    int n;
    printf("Quantidade de Herois:\n");
    scanf("%d", &n);
    Heroi *v = cria(n);
    ler(n, v);
    imprimir(n, v);
    return 0;
}