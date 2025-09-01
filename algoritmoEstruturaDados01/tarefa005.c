#include <stdio.h>

int main() {
    int pontuacao = 0;
    int *ponteiro_pontuacao;
    ponteiro_pontuacao = &pontuacao;
    printf("Endereço pontuacao: %p\n", ponteiro_pontuacao);
    printf("Pontuacao inicial: %d\n", pontuacao);
    *ponteiro_pontuacao = *ponteiro_pontuacao +10;
    *ponteiro_pontuacao = *ponteiro_pontuacao +10;
    *ponteiro_pontuacao = *ponteiro_pontuacao +10;
    printf("Pontuacao final apos coletar 3 moedas: %d", pontuacao);
    
}