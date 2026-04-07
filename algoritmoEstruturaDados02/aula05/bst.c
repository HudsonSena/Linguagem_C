#include <stdlib.h>
typedef struct no {
  int valor;
  struct no *esq;
  struct no *dir;
} No;

int main() {
  No *raiz = (No *)malloc(sizeof(No));
  raiz->valor = 50;
  raiz->esq = NULL;
  raiz->dir = NULL;
}