#include <stdio.h>

int main() {
    FILE *file = fopen("../level_1_map.dat", "rb");
    if(file == NULL) {
        printf("ERRO CRITICO: Nao foi possivel carregar os dados do mapa\n");
        perror(file);
        exit(1);
    }
}