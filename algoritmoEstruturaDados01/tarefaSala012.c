#include <stdio.h>

typedef struct {
    char sala[2];
    float notas[3];
    float frequencia;
} boletim;

typedef struct {
    int matricula;
    char nome[50];
    boletim notas;
} alunos;
/*
void media(float n1, float n2, float n3){
    float media = (n1+n2+n3)/3;
    if(media >= 7.0) {
        printf("Aprovado com media: %.2f", media);
    } else {
        printf("Reprovado com media: %.2f", media);
    }
}*/

int main(){
    int n, i, j;
    int escola[n];
    alunos aluno;
    printf("\nQuantidade de alunos: ");
    scanf("%i", &n);
    for(i=0; i<n; i++){
        printf("Matricula: ");
        scanf("%i %s %s %f %f", escola[i].aluno.matricula, escola[i].aluno.nome, 
        escola[i].aluno.notas.sala);
    }
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