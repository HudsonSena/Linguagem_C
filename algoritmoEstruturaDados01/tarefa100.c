#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int custo_mana;
    char nome[100];
} Feitico;

struct no {
    Feitico dado;
    struct no* prox;
};

typedef struct no No;

typedef struct {
    No * topo;
} Pilha;

void menu() {
    printf("============== Escolha uma opcao ==============\n");
    printf("1 - Adicionar novo feitico a pilha de comandos\n");
    printf("2 - Finalizar a sequencia de comandos e sair\n");
    printf("===============================================\n");
}

void ler(Feitico *pe) {
    scanf("%s %d", pe->nome, &pe->custo_mana);
}

void inserir(Pilha *ppilha, Feitico dado) {
    No * novo = (No *) malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = ppilha->topo;
    ppilha->topo = novo;
}

int main() {
    Pilha pilha;
    pilha.topo = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while(op!=2) {
        if(op==1) {
            Feitico e;
            printf("Informe o nome e o custo de mana do feitico:\n");
            ler(&e);
            inserir(&pilha, e);
        }
        menu();
        scanf("%d", &op);
    }
    return 0;
}