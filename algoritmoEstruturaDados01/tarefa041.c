#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
} evento;

void menu() {
    printf("===== Menu =====\n");
    printf("1 - Registrar novo evento\n");
    printf("2 - Sair\n");
    printf("================\n");    
}

int main() {
    FILE *file = fopen("../game_log.txt", "a");
    int op;
    menu();
    scanf("%d", &op);
    while(op != 2){
        if(op == 1){
            evento e;
            scanf("%s", e.nome);
            fprintf(file, "\n%s", e.nome);
            fflush(file);
        }
        menu();
        scanf("%d", &op);
    }
    printf("Programa Encerrado!");
}