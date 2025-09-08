#include <stdio.h>
#include <string.h>

int main(){
    char inventario[5][20];
    char s[50];
    printf("Digite 5 itens:\n");
    scanf("%s %s %s %s %s %s", inventario[0], inventario[1], inventario[2], inventario[3], inventario[4], s);
    for(int i=0; i<5; i++){
        if(strcmp(inventario[i], s)==0){
            printf("Porta aberta:\n");
            return 0;           
        }
    }
    printf("Voce nao tem o item necessario");
}