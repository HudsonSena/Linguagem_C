#include <stdio.h>
#include <string.h>
int main(){
    char nome_jogador[50];
    printf("Digite seu nome: ");
    scanf("%[^\n]s", nome_jogador);
    if(strlen(nome_jogador)<=15){
        printf("\nNome valido! Bem vindo ao jogo, %s", nome_jogador);
    } else {
        printf("\nNome muito longo! Por favor, escolha um nome com ate 15 carecteres");
    }
    return 0;
}