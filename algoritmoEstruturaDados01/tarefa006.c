#include <stdio.h>

int main() {
    int p[5] = {10, 20, 5, 15, 30};
    int *ponteiro_plataforma;
    int altura_total = 0;
    ponteiro_plataforma = &altura_total;
    for(int i=0; i<5; i++){
        *ponteiro_plataforma = *ponteiro_plataforma + *(p + i);
        printf("Altura a cada salto: %d\n", altura_total);
    }
    printf("Altura total do salto: %d", altura_total);
}