#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[100];
} membro;

struct No {
    membro dado;
    struct No* prox;
};

typedef struct {
    struct No* inicio;
} Lista;

void menu() {
    printf("===== Menu de Opcoes =====\n");
    printf("1 - Adicionar Membro\n");
    printf("2 - Mostrar Lista da Guilda\n");
    printf("3 - Criar lista\n");
    printf("4 - Ordenar Lista\n");
    printf("5 - Salvar em Arquivo\n");
    printf("6 - Sair\n");
    printf("==========================\n");
}

void ler(membro *pe) {
    printf("Digite o ID e nome do membro: ");
    scanf("%d %s", &pe->id, pe->nome);
}

void inserir_fim(Lista *plista, membro dado) {
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

Lista criar_lista(int n) {
    Lista lista;
    lista.inicio = NULL;
    int i;
    for(i=0; i<n; i++) {
        membro e;
        ler(&e);
        inserir_fim(&lista, e);            
    }
    return lista;    
}

void ordenar(Lista *plista) {
    struct No * pi;
    struct No * pj;
    struct No * pfim = NULL;
    if(plista->inicio == NULL) {
        return;
    }
    for(pi=plista->inicio; pi->prox!=NULL; pi=pi->prox) {
        for(pj=plista->inicio; pj->prox!=pfim; pj=pj->prox) {
            if(pj->dado.id > pj->prox->dado.id) {
                membro temp = pj->dado;
                pj->dado = pj->prox->dado;
                pj->prox->dado = temp;
            }
        }
        pfim = pj;
    }
}

void salvar_guild_aquivo(Lista lista) {
    FILE *file = fopen("../guild_roster.bin", "wb");
    struct No * pi;
    for(pi=lista.inicio; pi!=NULL; pi=pi->prox) {
        fwrite(&pi->dado, sizeof(membro), 1, file);
    }
    fclose(file);
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while(op!=6) {
        if(op==1) {
            membro e;
            ler(&e);
            inserir_fim(&lista, e);            
        }
        if(op==2) {
            mostrar(lista);            
        }
        if(op==3) {
            int n;
            printf("Informe a quantidade de membros:\n");
            scanf("%d", &n);
            lista = criar_lista(n);
        }
        if(op==4) {
            ordenar(&lista);
        }
        if(op==5) {
            salvar_guild_aquivo(lista);
            printf("Arquivo salvo com sucesso\n");
        }
        menu();
        scanf("%d", &op);
    }

    return 0;
}
