#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[100];
} inimigo;

struct No {
    inimigo dado;
    struct No* prox;
};

typedef struct {
    struct No* inicio;
} Lista;

void menu() {
    printf("===== Menu de Opcoes =====\n");
    printf("1 - Inserir Inimigo\n");
    printf("2 - Mostrar Inimigos\n");
    printf("3 - Criar lista\n");
    printf("4 - Sair\n");
    printf("==========================\n");
}

void ler(inimigo *pe) {
    printf("Digite o ID e nome do inimigo: ");
    scanf("%d %s", &pe->id, pe->nome);
}

void inserir_fim(Lista *plista, inimigo dado) {
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

void mostrar(Lista lista) {
    struct No * pi;
    for(pi=lista.inicio; pi!=NULL; pi=pi->prox){ printf("ID: %d, Nome: %s\n", pi->dado.id, pi->dado.nome); }
}

Lista criar_lista(int n) {
    Lista lista;
    lista.inicio = NULL;
    int i;
    for(i=0; i<n; i++) {
        inimigo e;
        ler(&e);
        inserir_fim(&lista, e);            
    }
    return lista;    
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while(op!=4) {
        if(op==1) {
            inimigo e;
            ler(&e);
            inserir_fim(&lista, e);            
        }
        if(op==2) {
            mostrar(lista);            
        }

        if(op==3) {
            int n;
            printf("Informe a quantidade de inimigos:\n");
            scanf("%d", &n);
            lista = criar_lista(n);
        }
        menu();
        scanf("%d", &op);
    }

    return 0;
}
