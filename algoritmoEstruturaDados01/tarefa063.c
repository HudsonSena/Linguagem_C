#include <stdio.h>

int main() {
    int v[] = { 120, 125, 130, 142, 150 };
    int novo_tempo;
    printf("novo tempo:\n");
    scanf("%d", &novo_tempo);
    int i;
    for(i=4; i>=0 && novo_tempo<v[i]; i--) {
        v[i+1] = v[i];
    }
    v[i+1] = novo_tempo;
    printf("Vetor completo:\n");
    for(i=0; i<5; i++) {
        printf("%d", v[i]);
    }
    return 0;
}