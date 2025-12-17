#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[100];
    int custo_mana;
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
    printf("2 - Lancar proximo feitico\n");
    printf("3 - Mostrar pilha de comandos\n");
    printf("4 - Verificar status da pilha\n");
    printf("5 - Finalizar a sequencia de comandos e sair\n");
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

// Na atividade pede para usar void mostrar_pilha(Pilha pilha)
// Na aula dessa atividade foi explicado que não há a necessidade de ponteiro
// Pois não vamos fazer nenhuma modificação, apenas mostrar a pilha de comandos.
void mostrar_pilha(Pilha pilha) {
    if(vazia(&pilha)) {
        printf("A pilha de comandos esta vazia.\n");
    } else {
        No * pi;
        for(pi=pilha.topo; pi!=NULL; pi=pi->prox) {
            printf("Feitico: %s, Custo de Mana: %d\n", pi->dado.nome, pi->dado.custo_mana);
        }
    }
}

Feitico pop(Pilha *ppilha) {
    if(vazia(ppilha)) {
        printf("A pilha de comandos esta vazia\n");
        Feitico falha = {"", -1};
        return falha;
    }
    else {
        No * pi = ppilha->topo;
        ppilha->topo = pi->prox;
        Feitico dado = pi->dado;
        free(pi);
        return dado;
    }
}

void liberar_pilha(Pilha *ppilha) {
    No * pi = ppilha->topo;
    while(pi != NULL) {
        No * temp = pi;
        pi = pi->prox;
        free(temp);
    }
    ppilha->topo = NULL;
}

int vazia(Pilha *pilha) {
    if(pilha->topo == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Pilha pilha;
    pilha.topo = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while(op!=5) {
        if(op==1) {
            Feitico e;
            printf("Informe o nome e o custo de mana do feitico:\n");
            ler(&e);
            inserir(&pilha, e);
        }
        else if(op==2) {
            Feitico feitico = pop(&pilha);
            if(feitico.custo_mana != -1) {
                printf("Feitico %s lancado com sucesso\n", feitico.nome);
            }
        }
        else if(op==3) {
            mostrar_pilha(pilha);
        }
        else if(op==4) {
            if(vazia(&pilha)) {
                printf("A pilha de comandos esta vazia.\n");
            } else {
                printf("A pilha de comandos possui feiticos pendentes.\n");
            }
        }
        menu();
        scanf("%d", &op);
    }
    liberar_pilha(&pilha);
    return 0;
}