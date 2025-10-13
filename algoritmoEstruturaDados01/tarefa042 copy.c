#include <stdio.h>

typedef struct {
    char nome[100];
    float nota1;
    float nota2;
    float nota3;
} estudante;

int main() {
    FILE *file = fopen("../estudantes03.txt", "r");
    if(file == NULL) {
        printf("ocorreu erro ao abrir o arquivo\n");
        system("pause");
        exit(1);
    }
    int n;
    fscanf(file, "%d", &n);
    int i;
    for(i=0; i<n; i++) {
        estudante e;
        fscanf(file, "%s %f %f %f", e.nome, &e.nota1, &e.nota2, &e.nota3);
        if(e.nota1 >= e.nota2 && e.nota1 >= e.nota3) {
            printf("%s: %.2f\n", e.nome, e.nota1);
        } else if(e.nota2 >= e.nota1 && e.nota2 >= e.nota3) {
            printf("%s: %.2f\n", e.nome, e.nota3);
        } else {
            printf("%s: %.2f\n", e.nome, e.nota3);
        }
    }
    fclose(file);
}