#include <stdio.h>

typedef struct {
    int resolucao_x;
    int resolucao_y;
    float volume_som;
} configuracao;

int main() {
    FILE *file = fopen("../config.txt", "r");
    if(file == NULL) {
        printf("Erro: Arquivo config.txt nao encontrado\n");
        exit(1);
    }
    configuracao c;
    fscanf(file, "%d %d %f", &c.resolucao_x, &c.resolucao_y, &c.volume_som);
    printf("\nResolucao: %d x %d\nVolume: %.1f\n", c.resolucao_x, c.resolucao_y, c.volume_som);
    fclose(file);
}