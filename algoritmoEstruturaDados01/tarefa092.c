#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[100];
} mercenario;

struct No {
    mercenario dado;
    struct No* prox;
};

typedef struct {
    struct No* inicio;
} Lista;

void menu() {
    printf("===== Menu de Opcoes =====\n");
    printf("1 - Contratar mercenario\n");
    printf("2 - Exibir companhia\n");
    printf("3 - Declarar falencia\n");
    printf("4 - Sair\n");
    printf("==========================\n");
}

void ler(mercenario *pe) {
    printf("Digite o ID e nome do mercenario: ");
    scanf("%d %s", &pe->id, pe->nome);
}

void inserir_fim(Lista *plista, mercenario dado) {
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

void mostrar(Lista lista) {
    struct No * pi;
    for(pi=lista.inicio; pi!=NULL; pi=pi->prox){ printf("ID: %d, Nome: %s\n", pi->dado.id, pi->dado.nome); }
    if(lista.inicio == NULL) {
        printf("Companhia vazia\n");
    }
}

void deletar_lista(Lista *plista) {
    struct No * pi;
    while(plista->inicio != NULL) {
        pi = plista->inicio;
        plista->inicio = pi->prox;
        free(pi);
    }
    if(plista->inicio == NULL) {
        printf("Companhia vazia\n");
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
            mercenario e;
            ler(&e);
            inserir_fim(&lista, e);            
        }
        if(op==2) {
            mostrar(lista);            
        }
        if(op==3) {
            deletar_lista(&lista);
        }
        menu();
        scanf("%d", &op);
    }

    return 0;
}
