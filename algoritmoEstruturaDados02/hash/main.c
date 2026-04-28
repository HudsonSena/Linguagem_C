#include "hash.c"

int main() {
    Aluno a = {1, "Hudson", 'A'};
    Aluno b = {2, "Maria", 'B'};
    initTabela();
    inserir(a);
    inserir(b);
}