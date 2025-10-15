#include <stdio.h>

typedef struct {
    char nome[50];
    int vida;
    int ataque;
} campeao;

int main(){
    FILE *file = fopen("../squad048.dat", "rb");
    //4 Campeoes, ta tinha o arquivo pronto
    campeao v[4];
    fread(v, sizeof(campeao), 4, file);
    fclose(file);
    int i;
    campeao maior = v[0];
    for(i=0; i<3; i++) {
        if(v[i].vida>maior.vida) {
            maior = v[i];
        }
    }
    printf("\n%s: Tanque do esquadrao", maior.nome);
}