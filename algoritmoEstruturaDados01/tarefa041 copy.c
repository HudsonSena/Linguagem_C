#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[100];
    float nota1;
    float nota2;
    float nota3;
} estudante;

void menu() {
    printf("========== Digite a opcao ==========\n");
    printf("1 - Cadastrar novo aluno\n");
    printf("2 - Sair\n");
    printf("====================================\n");
}

int main() {
    FILE *file = fopen("../estudantes02.txt", "a");
    int op;
    menu();
    scanf("%d", &op);
    while(op != 2){
        if(op == 1){
            estudante e;
            scanf("%s %f %f %f", e.nome, &e.nota1, &e.nota2, &e.nota3);
            fprintf(file, "\n%s %f %f %f", e.nome, e.nota1, e.nota2, e.nota3);
            fflush(file);
        }
        menu();
        scanf("%d", &op);
    }
    printf("Programa finalizado\n");

}