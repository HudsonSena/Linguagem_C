#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int mat;
    char nome[100];
} estudante;

struct no {
    estudante dado;
    struct no* prox;
};

typedef struct no No;

typedef struct {
    No * topo;
} Pilha;

void menu() {
    printf("==== Escolha uma opcao ====\n");
    printf("1 - Inserir\n");
    printf("2 - Mostrar\n");
    printf("3 - Remover\n");
    printf("4 - Vazia\n");
    printf("5 - Topo\n");
    printf("6 - Inverter\n");
    printf("7 - Sair\n");
    printf("===========================\n");
}

void ler(estudante *pe) {
    scanf("%d %s", &pe->mat, pe->nome);
}

void inserir(Pilha *ppilha, estudante dado) {
    No * novo = (No *) malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = ppilha->topo;
    ppilha->topo = novo;
}

void mostrar(Pilha pilha) {
    No * pi;
    for(pi = pilha.topo; pi != NULL; pi = pi->prox) {
        printf("Matricula: %d, Nome: %s\n", pi->dado.mat, pi->dado.nome);
    }
}

void remover(Pilha *ppilha) {
    if(ppilha->topo == NULL) {
        printf("A pilha esta vazia\n");
        return;
    }
    else {
        No * pi = ppilha->topo;
        ppilha->topo = pi->prox;
        free(pi);
    }
}

//isEmpty
int vazia(Pilha pilha) {
    if(pilha.topo == NULL) {
        return 1;
    } else {
        return 0;
    }
}

No * topo(Pilha pilha) {
    return pilha.topo;
}

void inverter(Pilha *ppilha) {
    Pilha aux;
    aux.topo = NULL;
    No * pi;
    for(pi = ppilha->topo; pi != NULL; pi = ppilha->topo) {
        inserir(&aux, pi->dado);
        remover(ppilha);
    }
    ppilha->topo = aux.topo;
}

int main() {
    Pilha pilha;
    pilha.topo = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while(op!=7) {
        if(op==1) {
            estudante e;
            printf("Informe a matricula e o nome do estudante:\n");
            ler(&e);
            inserir(&pilha, e);
        }
        else if(op==2) {
            mostrar(pilha);
        }
        else if(op==3) {
            remover(&pilha);
        }
        else if(op==4) {
            int r = vazia(pilha);
            if(r!=0) {
                printf("Pilha vazia\n");
            } else {
                printf("A pilha contem elementos\n");
            }
        }
        else if(op==5) {
            No * pi = topo(pilha);
            if(pi==NULL) {
                printf("A pilha esta vazia\n");
            } else {
                printf("Topo - Matricula: %d, Nome: %s\n", pi->dado.mat, pi->dado.nome);
            }
        }
        else if(op==6) {
            inverter(&pilha);
        }
        
        menu();
        scanf("%d", &op);
    }
    return 0;
}