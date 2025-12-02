#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char titulo[100];
    char status[10];
} missao;

struct No {
    missao dado;
    struct No* prox;
};

typedef struct {
    struct No* inicio;
} Lista;

void menu() {
    printf("===== Menu de Opcoes =====\n");
    printf("1 - Adicionar Missao\n");
    printf("2 - Mostrar Missoes\n");
    printf("3 - Buscar Missao por ID\n");
    printf("4 - Sair\n");
    printf("==========================\n");
}

void ler(missao *pe) {
    printf("Digite o id, o titulo e status(Ativo ou Concluido) da missao: ");
    scanf("%d %s %s", &pe->id, pe->titulo, pe->status);
}

void inserir_fim(Lista *plista, missao dado) {
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
    for(pi=lista.inicio; pi!=NULL; pi=pi->prox){ printf("Matricula: %d, Titulo: %s e Status: %s\n", pi->dado.id, pi->dado.titulo, pi->dado.status); }
}

struct No* pesquisar(Lista lista, int id) {
    struct No * pi;
    for(pi=lista.inicio; pi!=NULL && pi->dado.id!=id; pi=pi->prox);
    return pi;
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while(op!=4) {
        if(op==1) {
            missao e;
            ler(&e);
            inserir_fim(&lista, e);            
        }
        if(op==2) {
            mostrar(lista);            
        }
        if(op==3) {
            int id;
            printf("ID da missao: ");
            scanf("%d", &id);
            struct No * pi = pesquisar(lista, id);
            if(pi!=NULL) {
                printf("ID: %d, Titulo: %s e Status: %s\n", pi->dado.id, pi->dado.titulo, pi->dado.status);
            } else {
                printf("Missao nao encontrada\n");
            }
        }
        menu();
        scanf("%d", &op);
    }

    return 0;
}

