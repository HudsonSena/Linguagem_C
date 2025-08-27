#include <stdio.h>
#include <string.h>

int main(){
    int i;
    char nome[20];
    printf("Digite um nome: ");
    //scanf("%s", nome);
    //fgets(nome, 50, stdin);
    scanf("%20[^\n]", nome);
    printf("%s\n", nome);
    //for(i=0; i<20; i++){
    //    printf("%i %c\n", i, nome[i]);
    //}
    char *p = strchr(nome, 'i');
    printf("%s", *p);
    return 0;
}