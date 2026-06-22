#include <stdio.h>
#include "estrutura01.c"
#include "estrutura02.c"

/*Aqui mostramos o tamanho em bits de cada estrutura, e vemos que a Estrutura01 tem 16 bytes, 
e a Estrutura02 tem 24 bytes, isso ocorre por causa do alinhamento de dados,
onde o compilador alinha os dados para otimizar o acesso à memória,
e nesse caso a Estrutura01 tem um char antes do long int, o que faz com que o compilador alinhe o long int para 8 bytes,
e a Estrutura02 tem o long int antes do char, o que faz com que o compilador alinhe o long int para 8 bytes,
e os chars para 1 byte, totalizando 24 bytes.*/

int main() {
    int x1 = sizeof(Estrutura01);
    int x2 = sizeof(Estrutura02);
    printf("\nEstrutura01: %d\nEstrutura02: %d\n", x1, x2);
}