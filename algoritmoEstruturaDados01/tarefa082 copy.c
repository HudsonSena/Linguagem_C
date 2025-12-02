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

void menu() {
    printf("===== Menu de Opcoes =====\n");
    printf("1 - Inserir Estudante\n");
    printf("2 - Mostrar lista\n");
    printf("3 - Sair\n");
    printf("==========================\n");
}

void ler(estudante *pe) {
    printf("Digite a matricula e nome do estudante: ");
    scanf("%d %s", &pe->mat, pe->nome);
}

void inserir_inicio(Lista *plista, estudante dado) {
    struct No* novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = plista->inicio;
    plista->inicio = novo;
}

void mostrar(Lista lista) {
    struct No * pi = lista.inicio;
    // for(pi=lista.inicio; pi!=NULL; pi=pi->prox){}
    while (pi != NULL) {
        printf("Matricula: %d, Nome: %s\n", pi->dado.mat, pi->dado.nome);
        pi = pi->prox;
    }
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while(op!=3) {
        if(op==1) {
            estudante e;
            ler(&e);
            inserir_inicio(&lista, e);
        } else if(op==2) {
            mostrar(lista);
        } else {
            printf("Opcao invalida!\n");
        }
        menu();
        scanf("%d", &op);
    }

    return 0;
}

