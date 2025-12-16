#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[100];
} mercenario;

struct No {
    mercenario dado;
    struct No* prox;
};

typedef struct {
    struct No* inicio;
} Lista;

void menu() {
    printf("===== Menu de Opcoes =====\n");
    printf("1 - Inserir mercenario\n");
    printf("2 - Exibir mercenarios\n");
    printf("3 - Total de mercenarios\n");
    printf("4 - Sair\n");
    printf("==========================\n");
}

void ler(mercenario *pe) {
    printf("Digite o ID e nome do mercenario: ");
    scanf("%d %s", &pe->id, pe->nome);
}

void inserir_fim(Lista *plista, mercenario dado) {
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

int tamanho(Lista lista) {
    struct No * pi;
    int cont = 0;
    for(pi=lista.inicio; pi!=NULL; pi=pi->prox){
        cont++;
    }
    return cont;
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while(op!=4) {
        if(op==1) {
            mercenario e;
            ler(&e);
            inserir_fim(&lista, e);            
        }
        if(op==2) {
            mostrar(lista);            
        }
        if(op==3) {
            int tam = tamanho(lista);
            if(tam==0) {
                printf("A guilda esta vazia\n");
            }
            else {
                printf("Total de mercenarios: %d\n", tam);
            }            
        }
        menu();
        scanf("%d", &op);
    }

    return 0;
}
