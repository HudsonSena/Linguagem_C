#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[100];
} item;

struct No {
    item dado;
    struct No* prox;
};

typedef struct {
    struct No* inicio;
} Lista;

void menu() {
    printf("===== Menu de Opcoes =====\n");
    printf("1 - Inserir Item no Inicio\n");
    printf("2 - Inserir Item no Fim\n");
    printf("3 - Inserir Catalisador apos um fragmento\n");
    printf("4 - Mostrar inventario\n");
    printf("5 - Sair\n");
    printf("==========================\n");
}

void ler(item *pe) {
    printf("Digite o ID e nome do item: ");
    scanf("%d %s", &pe->id, pe->nome);
}

void inserir_inicio(Lista *plista, item dado) {
    struct No* novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = plista->inicio;
    plista->inicio = novo;
}

void inserir_fim(Lista *plista, item dado) {
    struct No* novo = (struct No*) malloc(sizeof(struct No));

    novo->dado = dado;
    novo->prox = NULL;
    if (plista->inicio == NULL) {
        plista->inicio = novo;
    } else {
        struct No* pi = plista->inicio;
        //for(pi=plista->inicio; pi->prox!=NULL; pi=pi->prox){}
        while (pi->prox != NULL) {
            pi = pi->prox;
        }
        pi->prox = novo;
    }
}

struct No* inserir_apos(Lista *plista, item dado, int id) {
    struct No * pi;
    for(pi=plista->inicio; pi!=NULL && pi->dado.id != id; pi=pi->prox);
    if(pi == NULL) {
        return pi;
    } else {
        struct No *novo = (struct No *) malloc(sizeof(struct No));
        novo->dado = dado;
        novo->prox = pi->prox;
        pi->prox = novo;
        return pi;
    }
}

void mostrar(Lista lista) {
    //struct No * pi = lista.inicio;
    struct No * pi;
    for(pi=lista.inicio; pi!=NULL; pi=pi->prox){ printf("ID: %d, Item: %s\n", pi->dado.id, pi->dado.nome); }
    /*while (pi != NULL) {
        printf("Matricula: %d, Nome: %s\n", pi->dado.id, pi->dado.nome);
        pi = pi->prox;
    }*/
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while(op!=5) {
        if(op==1) {
            item e;
            ler(&e);
            inserir_inicio(&lista, e);
        }
        if(op==2) {
            item e;
            ler(&e);
            inserir_fim(&lista, e);            
        }
        if(op==3) {
            item e;
            ler(&e);
            int id;
            printf("Informe o id do fragmento\n");
            scanf("%d", &id);
            struct No * pi = inserir_apos(&lista, e, id);
            if(pi==NULL) {
                printf("Nao foi possivel adicionar o catalisador ao inventario\n");
            }
        }
        if(op==4) {
            mostrar(lista);            
        }
        menu();
        scanf("%d", &op);
    }

    return 0;
}
