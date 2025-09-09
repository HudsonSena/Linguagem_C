#include <stdio.h>

int main(){
    int horas;
    double vhora;
    double salario;
    printf("Quantas horas trabalhou e o valor de cada hora\n");
    scanf("%D %lf", &horas, &vhora);
    salario = horas*vhora;
    printf("%lf\n", salario);
}