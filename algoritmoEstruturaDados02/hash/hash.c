#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10

typedef struct aluno{
    int matricula;
    char nome[81];
    char turma;
} Aluno;

typedef struct no {
    Aluno *aluno;
    struct no *prox;
} No;

No* tabela[TAM];

int hash(Aluno *a) {
    return a->matricula % TAM;
}

No *criarNo(Aluno *a);

void inserir(Aluno a) {
    int pos = hash(&a);
    No *novoNo = criarNo(&a);
    if(tabela[pos] == NULL) {
        tabela[pos] = novoNo;
    } else {
        No *temp = tabela[pos];
        while(temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novoNo;
    }
}

No* initTabela() {
    for(int i=0; i<TAM; i++) {
        tabela[i] = NULL;
    }
}

No *criarNo(Aluno *a) {
    No *novoNo = (No*)malloc(sizeof(No));
    novoNo->aluno = a;
    novoNo->prox = NULL;
    return novoNo;
}

void printAluno(Aluno* a) {
    printf("Matricula: %d\n", a->matricula);
    printf("Nome: %s\n", a->nome);
    printf("Turma: %c\n", a->turma);
}