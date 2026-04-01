#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    int valor;
    int nfilhos;
    struct no *filhos[10];
} No;

No *criarNo(int valor);
void addFilho(No *pai, No *filho);
void liberarArvore(No*);

int main() {
    No *raiz = criarNo(1);
    No *f[5] = {
        criarNo(3),
        criarNo(2),
        criarNo(5),
        criarNo(4),
        criarNo(5)
    };
    addFilho(raiz, f[0]);
    addFilho(raiz, f[1]);
    addFilho(raiz, f[2]);
    addFilho(f[0], f[3]);
    addFilho(f[0], f[4]);
    liberarArvore(raiz);
    return 0;
}

No *criarNo(int valor) {
    No *r = (No *)malloc(sizeof(No));
    r->valor = valor;
    r->nfilhos = 0;
    return r;
}

void addFilho(No *pai, No *filho) {
    pai->filhos[pai->nfilhos++] = filho;
}


void liberarArvore(No* raiz) {
    for(int i = 0; i < raiz->nfilhos; i++) {
        liberarArvore(raiz->filhos[i]);
    }
    printf("Liberando noo: %d\n", raiz->valor);
    free(raiz);
}