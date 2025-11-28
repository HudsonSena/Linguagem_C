#include <stdio.h>
#include "calculadora.h"

int main() {
    int a, b;
    printf("Informe os valores de a e b:\n");
    scanf("%d %d", &a, &b);
    int ra = adiciona(a, b);
    printf("Adicao: %d + %d = %d\n", a, b, ra);
    int rs = subtrai(a, b);
    printf("Subtracao: %d - %d = %d\n", a, b, rs);
    int rm = multiplica(a, b);
    printf("Multiplicacao: %d * %d = %d\n", a, b, rm);
    int rd = divide(a, b);
    printf("Divisao: %d / %d = %d\n", a, b, rd);
}