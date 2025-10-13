#include <stdio.h>

typedef struct {
    char nome[50];
    int cont;
} estudante;

int main() {
    int n;
    printf("Informe a quantidade de estudantes\n");
    scanf("%d", &n);
    estudante v[n];
    int i;
    FILE *file = fopen("../alunos.txt", "w");
    for(i=0; i<n; i++) {
        scanf("%s %d", v[i].nome, &v[i].cont);
    }
    estudante maior = v[0];
    for(i=0; i<n; i++) {
        if(v[i].cont > maior.cont){
            maior = v[i];
        }
    }
    fprintf(file, "%s: %d", maior.nome, maior.cont);
    fclose(file);
}