#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int mat;
    char nome[100];
} estudante;

struct No {
    estudante dado;
    struct No* prox;
};

typedef struct {
    struct No* inicio;
} Lista;

void ler(estudante *pe) {
    scanf("%d %s", &pe->mat, pe->nome);
}

void menu() {
    printf("===== escolha uma opcao: =====\n");
    printf("1 - Inserir novo estudante\n");
    printf("2 - Sair\n");
    printf("==============================\n");    
}

void inserir_inicio(Lista *lista, estudante dado) {
    struct No* novo = (struct No*)malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = lista->inicio;
    lista->inicio = novo;
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while(op!=2) {
        //usando switch case para as opcoes do menu, para diferenciar da tarefa e treinar o uso do switch
        switch(op) {
            case 1: {
                estudante e;
                ler(&e);
                inserir_inicio(&lista, e);
                break;
            }
            default:
                printf("Opcao invalida!\n");
        }
        menu();
        scanf("%d", &op);
    }
}