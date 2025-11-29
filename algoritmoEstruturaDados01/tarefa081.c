#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome_golpe[50];
} movimento;

struct No {
    movimento dado;
    struct No* prox;
};

typedef struct {
    struct No* inicio;
} Lista;

void menu() {
    printf("===== escolha uma opcao: =====\n");
    printf("1 - Inserir novo movimento no inicio do combo\n");
    printf("2 - Sair\n");
    printf("==============================\n");    
}

void ler(movimento *pm) {
    scanf("%d %s", &pm->id, pm->nome_golpe);
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while(op!=2) {
        switch(op) {
            case 1: {
                movimento m;
                ler(&m);
                struct No* novo = (struct No*)malloc(sizeof(struct No));
                novo->dado = m;
                novo->prox = lista.inicio;
                lista.inicio = novo;
                break;
            }
            default:
                printf("Opcao invalida!\n");
        }
        menu();
        scanf("%d", &op);
    }
    return 0;
}