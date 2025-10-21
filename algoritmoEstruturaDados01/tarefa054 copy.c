#include <stdio.h>

struct estudante {
    int mat;
    char nome[6];
    float n1;
    float n2;
    float n3;
};

void ler(struct estudante *pe) {
    printf("Matricula, nome, nota 1, nota 2 e nota 3:\n");
    scanf("%d %s %f %f %f", &pe->mat, pe->nome, &pe->n1, &pe->n2, &pe->n3);
}

void menu() {
    printf("======== Escolha uma opcao ========\n");
    printf("1 - Pesquisar\n");
    printf("2 - Sair\n");
    printf("===================================\n");
}

int pesquisar(int mat, int n, struct estudante v[]) {
    int i;
    for(i=0; i<n; i++) {
        if(v[i].mat == mat) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Informe o valor de n\n");
    scanf("%d", &n);
    struct estudante v[n];
    int i;
    for(i=0; i<n; i++) {
        ler(&v[i]);
    }
    int op;
    menu();
    scanf("%d", &op);
    while(op != 2) {
        if(op == 1) {
            int mat;
            printf("Informe a matricula\n");
            scanf("%d", &mat);
            int idx = pesquisar(mat, n, v);
            if(idx != -1) {
                float media = (v[idx].n1*2 + v[idx].n2*3 + v[idx].n3 *4)/9;
                printf("%s: %f\n", v[idx].nome, media);
            }
        }
        menu();
        scanf("%d", &op);
    }
    printf("Programa finalizado!");
}