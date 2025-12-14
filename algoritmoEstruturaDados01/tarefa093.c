#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[100];
} membro;

struct No {
    membro dado;
    struct No* prox;
};

typedef struct {
    struct No* inicio;
} Lista;

void menu() {
    printf("===== Menu de Opcoes =====\n");
    printf("1 - Adicionar novos membros\n");
    printf("2 - Exibir registro atual\n");
    printf("3 - Alterar nome\n");
    printf("4 - Sair\n");
    printf("==========================\n");
}

void ler(membro *pe) {
    printf("Digite a matricula e nome do membro: ");
    scanf("%d %s", &pe->id, pe->nome);
}

void inserir_fim(Lista *plista, membro dado) {
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

struct No* pesquisar(Lista lista, int id) {
    struct No * pi;
    for(pi=lista.inicio; pi!=NULL && pi->dado.id!=id; pi=pi->prox);
    return pi;
}

void mostrar(Lista lista) {
    struct No * pi;
    for(pi=lista.inicio; pi!=NULL; pi=pi->prox){ printf("ID: %d, Nome: %s\n", pi->dado.id, pi->dado.nome); }
}

void alterar(Lista *plista, int id, char novo_nome[]) {
    struct No * pi = pesquisar(*plista, id);
    if(pi == NULL) {
        printf("O membro nao pode ser alterado\n");
    } else {
        strcpy(pi->dado.nome, novo_nome);
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
            membro e;
            ler(&e);
            inserir_fim(&lista, e);            
        }
        if(op==2) {
            mostrar(lista);            
        }
        if(op==3) {
            int id;
            char novo_nome[100];
            printf("Informe o ID do membro:\n");
            scanf("%d", &id);
            printf("Digite o novo nome do membro:\n");
            scanf("%s", novo_nome);
            alterar(&lista, id, novo_nome);
        }
        menu();
        scanf("%d", &op);
    }

    return 0;
}
