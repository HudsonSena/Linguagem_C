#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[100];
} heroi;

struct No {
    heroi dado;
    struct No* prox;
};

typedef struct {
    struct No* inicio;
} Lista;

void menu() {
    printf("===== Menu de Opcoes =====\n");
    printf("1 - Inserir Fim\n");
    printf("2 - Inserir Antes\n");
    printf("3 - Mostrar Formacao\n");
    printf("4 - Sair\n");
    printf("==========================\n");
}

void ler(heroi *pe) {
    printf("Digite o ID e nome do heroi: ");
    scanf("%d %s", &pe->id, pe->nome);
}

void inserir_fim(Lista *plista, heroi dado) {
    struct No* novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = NULL;
    if (plista->inicio == NULL) {
        plista->inicio = novo;
    } else {
        struct No* pi = plista->inicio;
        while (pi->prox != NULL) {
            pi = pi->prox;
        }
        pi->prox = novo;
    }
}

struct No* inserir_antes(Lista *plista, heroi dado, int id) {
    if(plista->inicio == NULL) {
        return NULL;
    }
    else if(plista->inicio->dado.id == id) {
        struct No* novo = (struct No*) malloc(sizeof(struct No));
        novo->dado = dado;
        novo->prox = plista->inicio;
        plista->inicio = novo;
    }
    else {
        struct No* pi;
        for(pi = plista->inicio; pi->prox != NULL && pi->prox->dado.id != id; pi = pi->prox);
        if(pi->prox == NULL) {
            return NULL;
        }
        else {
            struct No *novo = (struct No *) malloc(sizeof(struct No));
            novo->dado = dado;
            novo->prox = pi->prox;
            pi->prox = novo;
            return pi;
        }
    }
}

void mostrar(Lista lista) {
    struct No * pi;
    for(pi=lista.inicio; pi!=NULL; pi=pi->prox){
        printf("ID: %d, Nome: %s\n", pi->dado.id, pi->dado.nome);
    }
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while(op!=4) {
        if(op==1) {
            heroi e;
            ler(&e);
            inserir_fim(&lista, e);            
        }
        if(op==2) {
            heroi e;
            ler(&e);
            int id;
            printf("Informe o ID do heroi para inserir antes:\n");
            scanf("%d", &id);
            struct No * pi = inserir_antes(&lista, e, id);
            if(pi==NULL) {
                printf("Nao foi possivel inserir o heroi\n");
            }
        }
        if(op==3) {
            mostrar(lista);            
        }
        menu();
        scanf("%d", &op);
    }

    return 0;
}
