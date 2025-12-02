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
    printf("1 - Inserir Inicio\n");
    printf("2 - Inserir Fim\n");
    printf("3 - Mostrar Lista\n");
    printf("4 - Pesquisar por matricula\n");
    printf("5 - Sair\n");
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

void inserir_fim(Lista *plista, estudante dado) {
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
    //struct No * pi = lista.inicio;
    struct No * pi;
    for(pi=lista.inicio; pi!=NULL; pi=pi->prox){ printf("Matricula: %d, Nome: %s\n", pi->dado.mat, pi->dado.nome); }
    /*while (pi != NULL) {
        printf("Matricula: %d, Nome: %s\n", pi->dado.mat, pi->dado.nome);
        pi = pi->prox;
    }*/
}

struct No* pesquisar(Lista lista, int mat) {    
    //struct No* pi = lista.inicio;
    struct No * pi;
    for(pi=lista.inicio; pi!=NULL && pi->dado.mat!=mat; pi=pi->prox);
    return pi;
    /*while (pi != NULL & pi->dado.mat <= mat) {
        if (pi->dado.mat == mat) {
            return pi;
        }
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
            estudante e;
            ler(&e);
            inserir_inicio(&lista, e);
        }
        if(op==2) {
            estudante e;
            ler(&e);
            inserir_fim(&lista, e);            
        }
        if(op==3) {
            mostrar(lista);            
        }
        if(op==4) {
            int mat;
            printf("Informe a matricula: ");
            scanf("%d", &mat);
            struct No * pi = pesquisar(lista, mat);
            if(pi!=NULL) {
                printf("Matricula: %d, Nome: %s\n", pi->dado.mat, pi->dado.nome);
            } else {
                printf("Estudante nao encontrado\n");
            }
        }
        menu();
        scanf("%d", &op);
    }

    return 0;
}

