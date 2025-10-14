#include <stdio.h>

typedef struct {
    char nome[100];
    float nota1;
    float nota2;
    float nota3;
} estudante;

int main() {
    FILE *file = fopen("../estudantes046.b", "rb");
    estudante e;
    while(fread(&e, sizeof(estudante), 1, file)) {
        float media = (e.nota1 + e.nota2 + e.nota3)/3;
        if(media>=7.0) {
            printf("%s: Aprovado\n", e.nome);
        } else if(media < 5.0) {
            printf("%s: Reprovado\n", e.nome);
        } else {
            float precisa = 10.0 - media;
            printf("%s: final  -%f\n", e.nome, precisa);
        }
    }
    printf("Programa finalizado!");
    fclose(file);
}