#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[100];
} monstro;

struct No {
    monstro dado;
    struct No* prox;
};

typedef struct {
    struct No* inicio;
} Lista;

void menu() {
    printf("===== Menu de Opcoes =====\n");
    printf("1 - Adicionar monstro\n");
    printf("2 - Mostrar Bestiario\n");
    printf("3 - Criar Bestiario\n");
    printf("4 - Ordenar Bestiario\n");
    printf("5 - Sair\n");
    printf("==========================\n");
}

void ler(monstro *pe) {
    printf("Digite o ID e nome do monstro: ");
    scanf("%d %s", &pe->id, pe->nome);
}

void inserir_fim(Lista *plista, monstro dado) {
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
    for(pi=lista.inicio; pi!=NULL; pi=pi->prox){ printf("ID: %d, Monstro: %s\n", pi->dado.id, pi->dado.nome); }
}

Lista criar_lista(int n) {
    Lista lista;
    lista.inicio = NULL;
    int i;
    for(i=0; i<n; i++) {
        monstro e;
        ler(&e);
        inserir_fim(&lista, e);            
    }
    return lista;    
}

void ordenar(Lista *plista) {
    struct No * pi;
    struct No * pj;
    struct No * pfim = NULL;
    if(plista->inicio == NULL) {
        return;
    }
    for(pi=plista->inicio; pi->prox!=NULL; pi=pi->prox) {
        for(pj=plista->inicio; pj->prox!=pfim; pj=pj->prox) {
            if(pj->dado.id > pj->prox->dado.id) {
                monstro temp = pj->dado;
                pj->dado = pj->prox->dado;
                pj->prox->dado = temp;
            }
        }
        pfim = pj;
    }
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while(op!=5) {
        if(op==1) {
            monstro e;
            ler(&e);
            inserir_fim(&lista, e);            
        }
        if(op==2) {
            mostrar(lista);            
        }
        if(op==3) {
            int n;
            printf("Informe a quantidade de Monstros:\n");
            scanf("%d", &n);
            lista = criar_lista(n);
        }
        if(op==4) {
            ordenar(&lista);
        }
        menu();
        scanf("%d", &op);
    }

    return 0;
}
