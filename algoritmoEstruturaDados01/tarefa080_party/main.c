#include <stdio.h>
#include "personagem/personagem.h"

int main() {
    int n;
    printf("Informe o numero de membros da equipe:\n");
    scanf("%d", &n);
    Personagem* party = cria_party(n);
    registra_membros(party, n);
    exibe_relatorio(party, n);
    libera_party(party);
}