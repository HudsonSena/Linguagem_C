#include "bst.c"

No* criarNo(int valor){
    No *res = (No*)malloc(sizeof(No));
    res->valor = valor;
    res->esq = NULL;
    res->dir = NULL;
    return res;
}

No* inserir(No* raiz, int valor){
    if(raiz == NULL){
        return criarNo(valor);
    }
}