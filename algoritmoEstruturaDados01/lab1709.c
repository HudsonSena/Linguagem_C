#include <stdio.h>

int main() {
    int n;
    printf("tamanho matriz:\n");
    scanf("%d", &n);
    int m[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cima = i;
            int esquerda = j;
            int baixo = n - 1 - i;
            int direita = n - 1 - j;

            int min = cima;
            if (esquerda < min) min = esquerda;
            if (baixo < min) min = baixo;
            if (direita < min) min = direita;

            m[i][j] = min + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}