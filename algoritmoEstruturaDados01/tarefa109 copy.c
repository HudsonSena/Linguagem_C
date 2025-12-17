#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int mat;
    char nome[100];
} estudante;

struct  no {
    estudante dado;
    struct no * prox;
};

typedef struct no No;

typedef struct {
    No * inicio;
    No * fim;
} Fila;


void menu() {
    printf("===== Escolha uma opcao =====\n");
    printf("1 - Inserir\n");
    printf("2 - Mostrar\n");
    printf("3 - Sair\n");
    printf("=============================\n");
}

void ler(estudante *pe) {
    scanf("%d %s", &pe->mat, pe->nome);
}

void inserir(Fila *fila, estudante dado) {
    No * novo = (No *) malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = NULL;
    if(fila->inicio == NULL) {        
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
}

void mostrar(Fila fila) {
    No * pi;
    for(pi = fila.inicio; pi != NULL; pi = pi->prox){
        printf("Matricula: %d, Nome: %s\n", pi->dado.mat, pi->dado.nome);
    }
}

int main() {
    Fila fila;
    fila.inicio = NULL;
    fila.fim = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while(op!=3) {
        if(op==1) {
            estudante e;
            printf("Informe a matricula e o nome do estudante:\n");
            ler(&e);
            inserir(&fila, e);
        }
        if(op==2) {
            mostrar(fila);
        }
        menu();
        scanf("%d", &op);
    }
    return 0;
}