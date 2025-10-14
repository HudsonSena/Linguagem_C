#include <stdio.h>

typedef struct {
    char nome[100];
    float nota1;
    float nota2;
    float nota3;
} estudante;

int main() {
    FILE *file = fopen("../estudantes04.txt", "r");
    estudante e;
    while (fscanf(file, "%s %f %f %f", e.nome, &e.nota1, &e.nota2, &e.nota3) != EOF) {
        float media = (e.nota1 + e.nota2 + e.nota3)/3;
        printf("%s: %.2f\n", e.nome, media);
    }
    fclose(file);
}