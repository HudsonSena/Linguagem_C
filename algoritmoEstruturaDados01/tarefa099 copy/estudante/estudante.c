#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estudante.h"

struct Estudante {
    int mat;
    char nome[100];
};

struct no {
    estudante dado;
    struct no* prox;
};

struct lista {
    No* inicio;
};

void menu() {
    printf("===== Menu de Opcoes =====\n");
    printf("1 - Inserir Inicio\n");
    printf("2 - Inserir Fim\n");
    printf("3 - Inserir Apos\n");
    printf("4 - Inserir Antes\n");
    printf("5 - Mostrar Lista\n");
    printf("6 - Pesquisar por Matricula\n");
    printf("7 - Deletar Inicio\n");
    printf("8 - Deletar Fim\n");
    printf("9 - Deletar por Matricula\n");
    printf("10 - Deletar Apos\n");
    printf("11 - Deletar Antes\n");
    printf("12 - Deletar Lista\n");
    printf("13 - Alterar Item\n");
    printf("14 - Tamanho da Lista\n");
    printf("15 - Criar lista\n");
    printf("16 - Ordenar Lista\n");
    printf("17 - Salvar em Arquivo\n");
    printf("18 - Ler de Arquivo\n");
    printf("19 - Sair\n");
    printf("==========================\n");
}

void ler(estudante *pe) {
    printf("Digite a matricula e nome do estudante: ");
    scanf("%d %s", &pe->mat, pe->nome);
}

void inserir_inicio(Lista *plista, estudante dado) {
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = plista->inicio;
    plista->inicio = novo;
}

void inserir_fim(Lista *plista, estudante dado) {
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = NULL;
    if (plista->inicio == NULL) {
        plista->inicio = novo;
    } else {
        No* pi = plista->inicio;
        //for(pi=plista->inicio; pi->prox!=NULL; pi=pi->prox){}
        while (pi->prox != NULL) {
            pi = pi->prox;
        }
        pi->prox = novo;
    }
}

No* inserir_apos(Lista *plista, estudante dado, int mat) {
    No * pi;
    for(pi=plista->inicio; pi!=NULL && pi->dado.mat != mat; pi=pi->prox);
    if(pi == NULL) {
        return pi;
    } else {
        No *novo = (No *) malloc(sizeof(No));
        novo->dado = dado;
        novo->prox = pi->prox;
        pi->prox = novo;
        return pi;
    }
}

No* inserir_antes(Lista *plista, estudante dado, int mat) {
    if(plista->inicio == NULL) {
        return NULL;
    }
    else if(plista->inicio->dado.mat == mat) {
        No* novo = (No*) malloc(sizeof(No));
        novo->dado = dado;
        novo->prox = plista->inicio;
        plista->inicio = novo;
    }
    else {
        No* pi;
        for(pi = plista->inicio; pi->prox != NULL && pi->prox->dado.mat != mat; pi = pi->prox);
        if(pi->prox == NULL) {
            return NULL;
        }
        else {
            No *novo = (No *) malloc(sizeof(No));
            novo->dado = dado;
            novo->prox = pi->prox;
            pi->prox = novo;
            return pi;
        }
    }
}

void mostrar(Lista lista) {
    No * pi;
    for(pi=lista.inicio; pi!=NULL; pi=pi->prox){ printf("Matricula: %d, Nome: %s\n", pi->dado.mat, pi->dado.nome); }
}

No* pesquisar(Lista lista, int mat) {
    No * pi;
    for(pi=lista.inicio; pi!=NULL && pi->dado.mat!=mat; pi=pi->prox);
    return pi;
}

void deletar_inicio(Lista *plista) {
    if(plista->inicio == NULL) {
        printf("A lista esta vazia\n");
    } else {
        No* pi = plista->inicio;
        plista->inicio = pi->prox;
        free(pi);
    }
}

void deletar_fim(Lista *plista) {
    if(plista->inicio == NULL) {
        printf("O estudante nao pode ser deletado\n");
    } else if(plista->inicio->prox == NULL) {        
        No* pi = plista->inicio;
        plista->inicio = NULL;
        free(pi);
    } else {
        No* pi;
        No* pa;
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
        No* pi = plista->inicio;
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
        No * pa;
        No * pi;
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
    No * pa;
    No * pi;
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
        No * pi;
        No * pa = NULL;
        No * paa = NULL;
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
    No * pi;
    while(plista->inicio != NULL) {
        pi = plista->inicio;
        plista->inicio = pi->prox;
        free(pi);
    }    
}

void alterar(Lista *plista, int mat, char nome[]) {
    No * pi = pesquisar(*plista, mat);
    if(pi == NULL) {
        printf("O estudante nao pode ser alterado\n");
    } else {
        strcpy(pi->dado.nome, nome);
    }
}

int tamanho(Lista lista) {
    No * pi;
    int cont = 0;
    for(pi=lista.inicio; pi!=NULL; pi=pi->prox){
        cont++;
    }
    return cont;
}

Lista criar_lista(int n) {
    Lista lista;
    lista.inicio = NULL;
    int i;
    for(i=0; i<n; i++) {
        estudante e;
        ler(&e);
        inserir_fim(&lista, e);            
    }
    return lista;    
}

void ordenar(Lista *plista) {
    No * pi;
    No * pj;
    No * pfim = NULL;
    if(plista->inicio == NULL) {
        return;
    }
    for(pi=plista->inicio; pi->prox!=NULL; pi=pi->prox) {
        for(pj=plista->inicio; pj->prox!=pfim; pj=pj->prox) {
            if(pj->dado.mat > pj->prox->dado.mat) {
                estudante temp = pj->dado;
                pj->dado = pj->prox->dado;
                pj->prox->dado = temp;
            }
        }
        pfim = pj;
    }
}

void salvar_aquivo(Lista lista) {
    FILE *file = fopen("../estudantes099.b", "wb");
    No * pi;
    for(pi=lista.inicio; pi!=NULL; pi=pi->prox) {
        fwrite(&pi->dado, sizeof(estudante), 1, file);
    }
    fclose(file);
}

Lista ler_arquivo() {
    Lista lista;
    lista.inicio = NULL;
    FILE *file = fopen("../estudantes099.b", "rb");
    estudante e;
    while(fread(&e, sizeof(estudante), 1, file)) {
        inserir_fim(&lista, e);
    }
    fclose(file);
    return lista;
}

void main_estudante() {
    Lista lista;
    lista.inicio = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while(op!=19) {
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
            No * pi = inserir_apos(&lista, e, mat);
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
            No * pi = inserir_antes(&lista, e, mat);
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
            No * pi = pesquisar(lista, mat);
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
        if(op==15) {
            int n;
            printf("Informe a quantidade de elementos:\n");
            scanf("%d", &n);
            lista = criar_lista(n);
        }
        if(op==16) {
            ordenar(&lista);
        }
        if(op==17) {
            salvar_aquivo(lista);
            printf("Arquivo salvo com sucesso\n");
        }
        if(op==18) {
            lista = ler_arquivo();
            printf("Arquivo lido com sucesso\n");
        }
        menu();
        scanf("%d", &op);
    }
}
