#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int mat;
    char nome[100];
} estudante;

struct No {
    estudante dado;
    struct No* prox;
};

typedef struct {
    struct No* inicio;
} Lista;

void menu() {
    printf("===== Menu de Opcoes =====\n");
    printf("1 - Inserir Inicio\n");
    printf("2 - Inserir Fim\n");
    printf("3 - Inserir Apos\n");
    printf("4 - Inserir Antes\n");
    printf("5 - Mostrar Lista\n");
    printf("6 - Pesquisar por matricula\n");
    printf("7 - Deletar Inicio\n");
    printf("8 - Deletar Fim\n");
    printf("9 - Deletar por matricula\n");
    printf("10 - Deletar Apos\n");
    printf("11 - Deletar Antes\n");
    printf("12 - Deletar Lista\n");
    printf("13 - Alterar\n");
    printf("14 - Tamanho\n");
    printf("15 - Sair\n");
    printf("==========================\n");
}

void ler(estudante *pe) {
    printf("Digite a matricula e nome do estudante: ");
    scanf("%d %s", &pe->mat, pe->nome);
}

void inserir_inicio(Lista *plista, estudante dado) {
    struct No* novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = plista->inicio;
    plista->inicio = novo;
}

void inserir_fim(Lista *plista, estudante dado) {
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

struct No* inserir_apos(Lista *plista, estudante dado, int mat) {
    struct No * pi;
    for(pi=plista->inicio; pi!=NULL && pi->dado.mat != mat; pi=pi->prox);
    if(pi == NULL) {
        return pi;
    } else {
        struct No *novo = (struct No *) malloc(sizeof(struct No));
        novo->dado = dado;
        novo->prox = pi->prox;
        pi->prox = novo;
        return pi;
    }
}

struct No* inserir_antes(Lista *plista, estudante dado, int mat) {
    if(plista->inicio == NULL) {
        return NULL;
    }
    else if(plista->inicio->dado.mat == mat) {
        struct No* novo = (struct No*) malloc(sizeof(struct No));
        novo->dado = dado;
        novo->prox = plista->inicio;
        plista->inicio = novo;
    }
    else {
        struct No* pi;
        for(pi = plista->inicio; pi->prox != NULL && pi->prox->dado.mat != mat; pi = pi->prox);
        if(pi->prox == NULL) {
            return NULL;
        }
        else {
            struct No *novo = (struct No *) malloc(sizeof(struct No));
            novo->dado = dado;
            novo->prox = pi->prox;
            pi->prox = novo;
            return pi;
        }
    }
}

void mostrar(Lista lista) {
    struct No * pi;
    for(pi=lista.inicio; pi!=NULL; pi=pi->prox){ printf("Matricula: %d, Nome: %s\n", pi->dado.mat, pi->dado.nome); }
}

struct No* pesquisar(Lista lista, int mat) {
    struct No * pi;
    for(pi=lista.inicio; pi!=NULL && pi->dado.mat!=mat; pi=pi->prox);
    return pi;
}

void deletar_inicio(Lista *plista) {
    if(plista->inicio == NULL) {
        printf("A lista esta vazia\n");
    } else {
        struct No* pi = plista->inicio;
        plista->inicio = pi->prox;
        free(pi);
    }
}

void deletar_fim(Lista *plista) {
    if(plista->inicio == NULL) {
        printf("O estudante nao pode ser deletado\n");
    } else if(plista->inicio->prox == NULL) {        
        struct No* pi = plista->inicio;
        plista->inicio = NULL;
        free(pi);
    } else {
        struct No* pi;
        struct No* pa;
        for(pi = plista->inicio; pi->prox != NULL; pi = pi->prox) {
            pa = pi;
        }
        pa->prox = NULL;
        free(pi);      
    }
}

void deletar_por_valor(Lista *plista, int mat) {
    //inicio == NULL
    if(plista->inicio == NULL) {
        printf("A lista esta vazia\n");
    }
    //No se encontra no inicio
    else if(plista->inicio->dado.mat == mat) {
        struct No* pi = plista->inicio;
        plista->inicio = pi->prox;
        free(pi);
    }
    //lista tem um unico o, matricula nao existe
    else if(plista->inicio->prox == NULL) {
        if(plista->inicio->dado.mat != mat) {
            printf("O estudante nao pode ser removido\n");
        }
    }
    //lista com multliplos Nos. Valor existe
    //lista com multliplos Nos. Valor nao existe
    else {
        struct No * pa;
        struct No * pi;
        for(pi = plista->inicio; pi != NULL && pi->dado.mat != mat; pi = pi->prox){
            pa = pi;
        }
        if(pi == NULL) {
            printf("O estudanto nao pode ser removido\n");
        }
        else {
            pa->prox = pi->prox;
            free(pi);
        }
    }
}

void deletar_apos(Lista *plista, int mat) {
    struct No * pa;
    struct No * pi;
    for(pa=plista->inicio; pa!=NULL && pa->dado.mat!=mat; pa=pa->prox);
    if(pa==NULL) {
        printf("O estudante nao pode ser removido\n");
    } else if(pa->prox==NULL) {
        printf("O estudante nao pode ser removido\n");
    } else {
        pi = pa->prox;
        pa->prox = pi->prox;
        free(pi);
    }
}

void deletar_antes(Lista *plista, int mat) {    
    if(plista->inicio == NULL) {
        printf("A lista esta vaiza\n");
    } else {
        struct No * pi;
        struct No * pa = NULL;
        struct No * paa = NULL;
        for(pi = plista->inicio; pi != NULL && pi->dado.mat != mat; pi = pi->prox) {
            paa = pa;
            pa = pi;
        }
        if(pi == NULL) {
            printf("Estudante nao pode ser removido\n");
        }
        else if(pa == NULL) {
            printf("Estudante nao pode ser removido\n");
        }
        else if(paa == NULL) {
            plista->inicio = pi;
            free(pa);
        }
        else {
            paa->prox = pi;
            free(pa);
        }
    }
}

void deletar_lista(Lista *plista) {
    struct No * pi;
    while(plista->inicio != NULL) {
        pi = plista->inicio;
        plista->inicio = pi->prox;
        free(pi);
    }    
}

void alterar(Lista *plista, int mat, char nome[]) {
    struct No * pi = pesquisar(*plista, mat);
    if(pi == NULL) {
        printf("O estudante nao pode ser alterado\n");
    } else {
        strcpy(pi->dado.nome, nome);
    }
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
    while(op!=15) {
        if(op==1) {
            estudante e;
            ler(&e);
            inserir_inicio(&lista, e);
        }
        if(op==2) {
            estudante e;
            ler(&e);
            inserir_fim(&lista, e);            
        }
        if(op==3) {
            estudante e;
            ler(&e);
            int mat;
            printf("Informe a matricula do estudante para inserir apos:\n");
            scanf("%d", &mat);
            struct No * pi = inserir_apos(&lista, e, mat);
            if(pi==NULL) {
                printf("Nao foi possivel inserir o estudante\n");
            }
        }
        if(op==4) {
            estudante e;
            ler(&e);
            int mat;
            printf("Informe a matricula do estudante para inserir antes:\n");
            scanf("%d", &mat);
            struct No * pi = inserir_antes(&lista, e, mat);
            if(pi==NULL) {
                printf("Nao foi possivel inserir o estudante\n");
            }
        }
        if(op==5) {
            mostrar(lista);            
        }
        if(op==6) {
            int mat;
            printf("Informe a matricula:\n");
            scanf("%d", &mat);
            struct No * pi = pesquisar(lista, mat);
            if(pi!=NULL) {
                printf("Matricula: %d, Nome: %s\n", pi->dado.mat, pi->dado.nome);
            } else {
                printf("Estudante nao encontrado\n");
            }
        }
        if(op==7) {
            deletar_inicio(&lista);
        }
        if(op==8) {
            deletar_fim(&lista);
        }
        if(op==9) {
            int mat;
            printf("Informe a matricula:\n");
            scanf("%d", &mat);
            deletar_por_valor(&lista, mat);         
        }
        if(op==10) {
            int mat;
            printf("Informe a matricula:\n");
            scanf("%d", &mat);
            deletar_apos(&lista, mat);         
        }
        if(op==11) {
            int mat;
            printf("Informe a matricula:\n");
            scanf("%d", &mat);
            deletar_antes(&lista, mat);         
        }
        if(op==12) {
            deletar_lista(&lista);
        }
        if(op==13) {
            int mat;
            char nome[100];
            printf("Informe a matricula do estudante:\n");
            scanf("%d", &mat);
            printf("Digite o novo nome do estudante:\n");
            scanf("%s", nome);
            alterar(&lista, mat, nome);
        }
        if(op==14) {
            int tam = tamanho(lista);
            printf("O tamanho da lista: %d\n", tam);
        }
        menu();
        scanf("%d", &op);
    }

    return 0;
}
