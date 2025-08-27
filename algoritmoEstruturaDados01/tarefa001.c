#include <stdio.h>

int main(){
    int vida = 100;//Variável Vida
    int *pvida = &vida;//Ponteiro de Vida

    printf("Conteudo da variavel vida: %d\n", vida);
    printf("Conteudo do Ponteiro: %d\n", *pvida);
    printf("Endereco da variavel: %p\n", &vida);
    printf("endereco da do ponteiro: %p\n", &pvida);

    //Simulador de Dano
    vida = 50;
    

    return -1;

}