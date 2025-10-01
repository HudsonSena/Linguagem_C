#include <stdio.h>

typedef struct {
    char sala[2];
    float notas[3];
    float frequencia;
} boletim;

/*typedef struct {
    int matricula;
    char nome[50];
    boletim;
} aluno;

void media(float n1, float n2, float n3){
    float media = (n1+n2+n3)/3;
    if(media >= 7.0) {
        printf("Aprovado com media: %.2f", media);
    } else {
        printf("Reprovado com media: %.2f", media);
    }
}*/

int main(){
    float n1=8.0;
    float n2=9.0;
    float n3=5.0;
    float media = (n1+n2+n3)/3;
    if(media >= 7.0) {
        printf("Aprovado com media: %.2f", media);
    } else {
        printf("Reprovado com media: %.2f", media);
    }
    boletim salaA;
    scanf("%s", salaA.sala);
    printf("******");
    printf("\n%s", salaA.sala);
    return 0;
}