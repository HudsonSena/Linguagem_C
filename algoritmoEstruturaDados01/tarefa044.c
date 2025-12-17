#include <stdio.h>

typedef struct {
    int id;
    int pontos;
} exp;

int main() {
    FILE *file = fopen("../player_log.txt", "r+");
    int n;
    fscanf(file, "%d", &n);
    int i;
    int soma;
    soma = 0;
    exp e;
    for(i=0; i<n; i++) {
        fscanf(file, "%d %d", &e.id, &e.pontos);
        soma += e.pontos;
    }
    printf("Pontos ganhos: %d", soma);
    fseek(file, 0, SEEK_CUR);
    fprintf(file, "\n--- SESSION CONCLUDED Video ---\n");
}