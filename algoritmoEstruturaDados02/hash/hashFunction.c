#include "aluno.c"
#include <stdio.h>
int hashFunction(Aluno A) {
    int hash = 0;
    for(int i=0; A.nome[i] != '\0'; i++) {
        hash += A.nome[i];
    }
    return hash % 100;
}

void mostrarAluno(Aluno A) {
    printf("Nome: %s\n", A.nome);
    printf("Matricula: %d\n", A.matricula);
    printf("Turma: %c\n", A.turma);
}

int main() {
    Aluno A[3] = {
        {"Kennedy", 10, 'A'},
        {"Hudson", 20, 'B'},
        {"Diego", 30, 'C'}
    };
    for(int i=0; i<3; i++) {
        mostrarAluno(A[i]);
    }
    return 0;
}