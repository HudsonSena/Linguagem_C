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
    printf("2 - Mostrar fila\n");
    printf("3 - Remover jogador da fila\n");
    printf("4 - Verificar se a Fila esta Vazia\n");
    printf("5 - Ver quem e o proximo da Fila\n");
    printf("6 - Sair\n");
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

void mostrar(Fila *f) {
    if(f->inicio == NULL) {
        printf("A fila de matchmaking esta vazia.\n");
    }
    No * aux;
    for(aux = f->inicio; aux != NULL; aux = aux->prox){
        printf("ID: %d, Nickname: %s\n", aux->j.id,  aux->j.nickname);
    }
}

jogador remover(Fila *f) {
    jogador j;
    if(f->inicio == NULL) {
        printf("A fila de matchmaking esta vazia.\n");
        j.id = -1; 
        return j;
    }
    else if(f->inicio->prox == NULL) {
        No * aux = f->inicio;
        j = aux->j;
        f->inicio = NULL;
        f->fim = NULL;
        free(aux);
        return j;
    }
    else {
        No * aux = f->inicio;
        j = aux->j;
        f->inicio = f->inicio->prox;
        free(aux);
        return j;
    }
}

int estaVazia(Fila *f) {
    if(f->inicio == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

jogador verinicio(Fila *f) {
    if(f->inicio != NULL) {
        return f->inicio->j;
    }
    jogador j;
    j.id = -1; 
    return j;
}

int main() {
    Fila fila;
    fila.inicio = NULL;
    fila.fim = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while (op!=6) {
        switch (op) {
            case 1: {
                jogador j;
                printf("Informe o ID e o nickname do jogador:\n");
                ler(&j);
                inserir(&fila, j);
                break;
            }
            case 2: {
                mostrar(&fila);
                break;
            }
            case 3: {
                jogador j = remover(&fila);
                if(j.id != -1) {
                    printf("O jogador %s (ID: %d) foi removida da fila e entrou em uma partida\n",j.nickname, j.id);
                }
                break;
            }
            case 4: {
                if(estaVazia(&fila)) {
                    printf("SIM, a fila esta vazia.\n");
                }
                else {
                    printf("NAO, a fila contem jogadores.\n");
                }
                break;
            }
            case 5: {
                jogador j = verinicio(&fila);
                if(j.id != -1) {
                    printf("O proximo jogador a entrar na partida e: %s (ID: %d)\n", j.nickname, j.id);
                }
                else {
                    printf("A fila esta vazia.\n");
                }
                break;
            }
            default:
                break;
        }
        menu();
        scanf("%d", &op);
    }

    return 0;
}