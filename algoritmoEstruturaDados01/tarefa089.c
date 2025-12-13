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
    printf("1 - Adicionar um heroi\n");
    printf("2 - Mostrar todos os herois\n");
    printf("3 - Dispensar heroi por ID\n");
    printf("4 - Sair\n");
    printf("==========================\n");
}

void ler(heroi *pe) {
    printf("Digite o ID e nome do heroi: ");
    scanf("%d %s", &pe->id, pe->nome);
}

void inserir_inicio(Lista *plista, heroi dado) {
    struct No* novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = plista->inicio;
    plista->inicio = novo;
}

void inserir_fim(Lista *plista, heroi dado) {
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
}

void dispensar_heroi(Lista *plista, int id) {
    //inicio == NULL
    if(plista->inicio == NULL) {
        printf("A lista esta vazia\n");
    }
    //No se encontra no inicio
    else if(plista->inicio->dado.id == id) {
        struct No* pi = plista->inicio;
        plista->inicio = pi->prox;
        free(pi);
    }
    //lista tem um unico o, matricula nao existe
    else if(plista->inicio->prox == NULL) {
        if(plista->inicio->dado.id != id) {
            printf("O heroi nao pode ser removido\n");
        }
    }
    //lista com multliplos Nos. Valor existe
    //lista com multliplos Nos. Valor nao existe
    else {
        struct No * pa;
        struct No * pi;
        for(pi = plista->inicio; pi != NULL && pi->dado.id != id; pi = pi->prox){
            pa = pi;
        }
        if(pi == NULL) {
            printf("O heroi nao pode ser removido\n");
        }
        else {
            pa->prox = pi->prox;
            free(pi);
        }
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
            mostrar(lista);            
        }
        if(op==3) {
            int id;
            printf("Informe o ID:\n");
            scanf("%d", &id);
            dispensar_heroi(&lista, id);         
        }
        menu();
        scanf("%d", &op);
    }

    return 0;
}
