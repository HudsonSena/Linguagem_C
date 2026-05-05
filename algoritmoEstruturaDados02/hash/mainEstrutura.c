#include <stdio.h>
#include "estrutura01.c"
#include "estrutura02.c"

int main() {
    int x1 = sizeof(Estrutura01);
    int x2 = sizeof(Estrutura02);
    printf("\nEstrutura01: %d\nEstrutura02: %d\n", x1, x2);
}