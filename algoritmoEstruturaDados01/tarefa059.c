#include <stdio.h>

typedef struct {
    int mat;
    char nome[6];
    float n1;
    float n2;
    float n3;
} estudante;

void ler(estudante *pe) {
    scanf("%d %s %f %f %f", &pe->mat, pe->nome, &pe->n1, &pe->n2, &pe->n3);
}

void menu(){
    printf("=======Menu de opcoes===========\n");
    printf("1 - Pesquisar\n");
    printf("2 - Sair\n");
    printf("================================\n");

}

int buscabinaria(int mat, estudante v[], int i, int f) {
    if(i > f) return -1;
    int meio = (i + f)/2;
    if(v[meio].mat == mat) {
        return meio;
    }
    if(v[meio].mat < mat) {
        return buscabinaria(mat, v, meio + 1, f);
    }
    return buscabinaria(mat, v, i, meio -1);
}

int main() {
    int n;
    printf("Quantidade de estudantes:\n");
    scanf("%d", &n);
    estudante v[n];
    int i;
    for(i=0; i<n; i++) {
       ler(&v[i]); 
    }
    int op;
    menu();
    scanf("%d", &op);
    while(op != 2) {
        if(op == 1){
            int mat;
            printf("informe uma matricula\n");
            scanf("%d", &mat);
            int idx = buscabinaria(mat, v, 0, n-1);
            if(idx != -1) {
                v[idx].n3 = v[idx].n3 + 1;
                float media = (v[idx].n1*2 + v[idx].n2*3 + v[idx].n3*4)/9;
                printf("%s: %.2f\n", v[idx].nome, media);
            }
        }
        menu();
        scanf("%d", &op);
    }
    printf("Programa finalizado!\n");
}