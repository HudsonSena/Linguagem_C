#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int mat;
    char nome[100];
} estudante;

struct  no {
    estudante dado;
    struct no * prox;
};

typedef struct no No;

typedef struct {
    No * inicio;
    No * fim;
} Fila;


void menu() {
    printf("===== Escolha uma opcao =====\n");
    printf("1 - Inserir\n");
    printf("2 - Mostrar\n");
    printf("3 - Remover\n");
    printf("4 - Vazia\n");
    printf("5 - Inicio\n");
    printf("6 - Salvar\n");
    printf("7 - Ler\n");
    printf("8 - Sair\n");
    printf("=============================\n");
}

void ler(estudante *pe) {
    scanf("%d %s", &pe->mat, pe->nome);
}

void inserir(Fila *fila, estudante dado) {
    No * novo = (No *) malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = NULL;
    if(fila->inicio == NULL) {        
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
}

void mostrar(Fila fila) {
    No * pi;
    for(pi = fila.inicio; pi != NULL; pi = pi->prox){
        printf("Matricula: %d, Nome: %s\n", pi->dado.mat, pi->dado.nome);
    }
}

void remover(Fila *pfila) {
    if(pfila->inicio == NULL) {
        printf("Lista vazia\n");
    }
    else if(pfila->inicio->prox == NULL) {
        pfila->inicio = NULL;
        pfila->fim = NULL;
    }
    else {
        No * pi = pfila->inicio;
        pfila->inicio = pfila->inicio->prox;
        free(pi);        
    }
}

int vazia(Fila fila) {
    if(fila.inicio == NULL) {
        return 1;
    } else {
        return 0;
    }
}

No * inicio(Fila fila) {
    return fila.inicio;
}

void salvar(Fila fila) {
    FILE * file = fopen("../estudantes113.b", "wb");
    No * pi;
    for(pi = fila.inicio; pi != NULL; pi = pi->prox) {
        fwrite(&pi->dado, sizeof(estudante), 1, file);
    }
    fclose(file);
}

Fila lerdearquivo() {
    Fila fila;
    fila.inicio = NULL;
    fila.fim = NULL;
    FILE * file = fopen("../estudantes113.b", "rb");
    estudante e;
    while(fread(&e, sizeof(estudante), 1, file)) {
        inserir(&fila, e);
    }
    fclose(file);
    return fila;
}

int main() {
    Fila fila;
    fila.inicio = NULL;
    fila.fim = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while(op!=8) {
        if(op==1) {
            estudante e;
            printf("Informe a matricula e o nome do estudante:\n");
            ler(&e);
            inserir(&fila, e);
        }
        if(op==2) {
            mostrar(fila);
        }
        if(op==3) {
            remover(&fila);
        }
        if(op==4) {
            int r = vazia(fila);
            if(r!=0) {
                printf("Fila vazia.\n");
            } else {
                printf("Fila contem elementos.\n");
            }
        }
        if(op==5) {
            No * pi = inicio(fila);
            if(pi!=NULL) {
                printf("Inicio da fila - Matricula: %d, Nome: %s\n", pi->dado.mat, pi->dado.nome);
            } else {
                printf("Fila vazia.\n");
            }
        }
        if(op==6) {
            salvar(fila);
        }
        if(op==7) {
            fila = lerdearquivo();
        }
        menu();
        scanf("%d", &op);
    }
    return 0;
}