#include <stdio.h>
#include <stdlib.h>

int main(){
    char palavras[10];
    printf("Digite um nome: ");
    fgets(palavras, 10, stdin);
    printf("%s", palavras);
    return 0;
}