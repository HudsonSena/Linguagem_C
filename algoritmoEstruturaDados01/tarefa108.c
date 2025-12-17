#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nickname[100];
} jogador;

struct no {
    jogador j;
    struct no * prox;
};

typedef struct no No;

typedef struct {
    No * inicio;
    No * fim;
} Fila;


void menu() {
    printf("===== Escolha uma opcao =====\n");
    printf("1 - Adicionar novo jogador a fila\n");
    printf("2 - Sair\n");
    printf("=============================\n");
}

void ler(jogador *pe) {
    scanf("%d %s", &pe->id, pe->nickname);
}

void inserir(Fila *f, jogador j) {
    No * novo = (No *) malloc(sizeof(No));
    novo->j = j;
    novo->prox = NULL;
    if(f->inicio == NULL) {        
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

int main() {
    Fila fila;
    fila.inicio = NULL;
    fila.fim = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while(op!=2) {
        if(op==1) {
            jogador e;
            printf("Informe o ID e o nickname do jogador:\n");
            ler(&e);
            inserir(&fila, e);
        }
        menu();
        scanf("%d", &op);
    }
    return 0;
}