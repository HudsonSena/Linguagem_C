#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[100];
} ward;

struct No {
    ward dado;
    struct No* prox;
};

typedef struct {
    struct No* inicio;
} Lista;

void menu() {
    printf("===== Menu de Opcoes =====\n");
    printf("1 - Adicionar Ward\n");
    printf("2 - Lancar Ward Shatter\n");
    printf("3 - Mostrar Wards Ativos\n");
    printf("4 - Sair\n");
    printf("==========================\n");
}

void ler(ward *pe) {
    printf("Digite o ID e nome do ward: ");
    scanf("%d %s", &pe->id, pe->nome);
}

void inserir_fim(Lista *plista, ward dado) {
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

void deletar_apos(Lista *plista, int id) {
    struct No * pa;
    struct No * pi;
    for(pa=plista->inicio; pa!=NULL && pa->dado.id!=id; pa=pa->prox);
    if(pa==NULL) {
        printf("Nao ha um ward apos ele para ser deletado\n");
    } else if(pa->prox==NULL) {
        printf("Nao ha um ward apos ele para ser deletado\n");
    } else {
        pi = pa->prox;
        pa->prox = pi->prox;
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
            ward e;
            ler(&e);
            inserir_fim(&lista, e);            
        }
        if(op==2) {
            int id;
            printf("ID do ward referencia:\n");
            scanf("%d", &id);
            deletar_apos(&lista, id);         
        }
        if(op==3) {
            mostrar(lista);            
        }
        menu();
        scanf("%d", &op);
    }

    return 0;
}
