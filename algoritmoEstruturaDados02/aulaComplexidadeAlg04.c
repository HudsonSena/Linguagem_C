#include <stdio.h>

float soma(float x, int n) {
    int soma = 0;
    int i = 0, j = 0;
    for(i = 0; i < n; i++) {
        int prod = 1;
        for(j = 0; j < n; j++) {
            prod = prod * x;
            printf("Produto: %2.f\n", prod);
        }
        soma = soma + prod;
    }
    return soma;
}

int main() {
    float x = 2.0;
    int n = 4;
    float res = soma(x, n);
    printf("Resultado: %f\n", res);
    return 0;
}