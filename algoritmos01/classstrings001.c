#include <stdio.h>
#include <stdlib.h>

char palavras[20];

int main(){
    //char palavras[] = {"Hudson Diego"};
    //printf("%c", palavras[6]);
    //printf("%c", palavras[0]);
    //printf("%c", palavras[5]);
    //printf("%s\n", palavras);
    //printf("Digite seu nome: ");
    //scanf("%s", palavras);
    //printf("%s", palavras);
    scanf("%20[^\n]", palavras);
    printf("%s", palavras);
    return 0;
}