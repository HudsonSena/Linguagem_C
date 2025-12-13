#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[100];
} jogador;

struct No {
    jogador dado;
    struct No* prox;
};

typedef struct {
    struct No* inicio;
} Lista;

void menu() {
    printf("===== Menu de Opcoes =====\n");
    printf("1 - Adicionar jogador ao fim da fila\n");
    printf("2 - Iniciar partida\n");
    printf("3 - Mostrar fila de espera\n");
    printf("4 - Sair\n");
    printf("==========================\n");
}

void ler(jogador *pe) {
    printf("Digite o ID e nome do jogador: ");
    scanf("%d %s", &pe->id, pe->nome);
}

void inserir_fim(Lista *plista, jogador dado) {
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

void deletar_inicio(Lista *plista) {
    if(plista->inicio == NULL) {
        printf("Nao ha jogadores na fila\n");
    } else {
        struct No* pi = plista->inicio;
        plista->inicio = pi->prox;
        free(pi);
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
            jogador e;
            ler(&e);
            inserir_fim(&lista, e);            
        }
        if(op==2) {
            deletar_inicio(&lista);
        }
        if(op==3) {
            mostrar(lista);            
        }        
        menu();
        scanf("%d", &op);
    }

    return 0;
}
