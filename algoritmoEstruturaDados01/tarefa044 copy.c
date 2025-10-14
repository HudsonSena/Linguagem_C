#include <stdio.h>

typedef struct {
    char nome[100];
    float nota1;
    float nota2;
    float nota3;
} estudante;

int main() {
    FILE *file = fopen("../estudantes044.txt", "r+");
    int n;
    fscanf(file, "%d", &n);
    int i;
    estudante e;
    for(i=0; i<n; i++){
        fscanf(file, "%s %f %f %f", e.nome, &e.nota1, &e.nota2, &e.nota3);
        int cont = 0;
        if(e.nota1 == 10) {
            cont++;
        }
        if(e.nota2 == 10) {
            cont++;
        }
        if(e.nota3 == 10) {
            cont++;
        }
        printf("\n%s: %d", e.nome, cont);
    }
    fseek(file, 0, SEEK_CUR);
    fprintf(file, "\nPrograma finalizado!");
}