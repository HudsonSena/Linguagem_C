#include <stdio.h>
/* Aula sobre manipulaçõ de strings

#include <string.h>

int main(){
    char *fonte[200];
    char *pesquisa[50];
    printf("Texto maior e o texto menor: ");
    scanf(" %[^\n]s", fonte);
    scanf(" %[^\n]s", pesquisa);
    char *resultado = strstr(fonte, pesquisa);
    if(resultado != NULL){
        printf("Texto menor, encontrado no texto maior.");
    } else {
        printf("Texto nao encontrado!");
    }
}*/

