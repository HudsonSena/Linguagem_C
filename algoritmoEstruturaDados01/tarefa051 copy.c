#include <stdio.h>

struct estudante {
    char nome[100];
    float nota1;
    float nota2;
    float nota3;
};

int main(){
    int n;
    printf("Informe o valor de n\n");
    scanf("%d", &n);
    int i;
    for(i=0; i<n; i++){
        struct estudante e;
        scanf("%s %f %f %f", e.nome, &e.nota1, &e.nota2, &e.nota3);
        float media = (e.nota1 + e.nota2 + e.nota3)/3;
        printf("%s: %2.f\n", e.nome, media);
    }
}