#include <stdio.h>

typedef struct {
    char nome[50];
    float hp;
    float atk;
} inimigo;

int main() {
    inimigo ini01;
    inimigo ini02;
    inimigo ini03;
    inimigo vi[3] = {ini01, ini02, ini03};
    FILE *file = fopen("../inimigos.txt", "r");
    int i=0;
    for(i=0; i<3; i++) {
        fscanf(file, "%s %f %f", vi[i].nome, &vi[i].hp, &vi[i].atk);
    }
    for(i=0; i<3; i++) {
        float s = vi[i].hp + vi[i].atk;
        if(s>200) {
            printf("\nInimigo elite: %s. Nivel de ameaca: %.2f", vi[i].nome, s);
        } else {
            printf("\nInimigo comum: %s. Nivel de ameaca: %.2f", vi[i].nome, s);
        }
    }
    fclose(file);
}