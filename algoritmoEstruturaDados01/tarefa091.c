#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char descricao[100];
} etapa;

struct No {
    etapa dado;
    struct No* prox;
};

typedef struct {
    struct No* inicio;
} Lista;

void menu() {
    printf("===== Menu de Opcoes =====\n");
    printf("1 - Inserir etapa no fim da lista\n");
    printf("2 - Mostrar todas as etapas da missao\n");
    printf("3 - Deletar etapa antes de um ID especifico\n");
    printf("4 - Sair\n");
    printf("==========================\n");
}

void ler(etapa *pe) {
    printf("Digite o ID e descricao da etapa: ");
    scanf("%d %s", &pe->id, pe->descricao);
}

void inserir_fim(Lista *plista, etapa dado) {
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
    for(pi=lista.inicio; pi!=NULL; pi=pi->prox){ printf("ID: %d, Descricao: %s\n", pi->dado.id, pi->dado.descricao); }
}

void deletar_antes(Lista *plista, int id) {    
    if(plista->inicio == NULL) {
        printf("A lista esta vazia\n");
    } else {
        struct No * pi;
        struct No * pa = NULL;
        struct No * paa = NULL;
        for(pi = plista->inicio; pi != NULL && pi->dado.id != id; pi = pi->prox) {
            paa = pa;
            pa = pi;
        }
        if(pi == NULL) {
            printf("Etapa nao pode ser removida\n");
        }
        else if(pa == NULL) {
            printf("Etapa nao pode ser removida\n");
        }
        else if(paa == NULL) {
            plista->inicio = pi;
            free(pa);
        }
        else {
            paa->prox = pi;
            free(pa);
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
            etapa e;
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
            deletar_antes(&lista, id);         
        }
        menu();
        scanf("%d", &op);
    }

    return 0;
}
