#ifndef ALUNO_H
#define ALUNO_H
#include <stdio.h>
typedef struct aluno{
    char nome[50];
    int matricula;
    char turma;
} Aluno;
#endif

/*int main() {
    Aluno A = {
        "Kennedy",
        10,
        'A'
    };

    Aluno B = {
        "Hudson",
        20,
        'A'
    };

    Aluno C = {
        .turma = 'B',
        .matricula =30,
        .nome = "Diego"
    };
}*/