#include <stdio.h>
#include <string.h>

int main(){
    char nome_jogador[50];
    char titulo_conquistado[50];
    printf("Nome do heroi:\n");
    scanf("%s", nome_jogador);
    strcat(nome_jogador, " ");
    printf("titulo conquistado:\n");
    scanf("%s", titulo_conquistado);
    strcat(nome_jogador, titulo_conquistado);
    printf("O heroi agora eh conhecido como: %s\n", nome_jogador);  
}