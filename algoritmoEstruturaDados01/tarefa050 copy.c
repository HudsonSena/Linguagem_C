#include <stdio.h>

int main() {
    float nota1;
    float nota2;
    float nota3;
    printf("informe as notas:\n");
    scanf("%f %f %f", &nota1, &nota2, &nota3);
    float media = (nota1 + nota2 + nota3)/3;
    printf("%.2f\n", media);
}