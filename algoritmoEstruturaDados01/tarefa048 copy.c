#include <stdio.h>

typedef struct {
    char nome[100];
    float nota1;
    float nota2;
    float nota3;
} estudante;

int main() {
    FILE *file = fopen("../estudantes047.b", "rb");
    estudante v[3];
    fread(v, sizeof(estudante), 3, file);
    int i;
    for(i=0; i<3; i++){
        float media = (v[i].nota1 + v[i].nota2 + v[i].nota3)/3;
        printf("%s: %2.f\n", v[i].nome, media);
    }

    fclose(file);
}