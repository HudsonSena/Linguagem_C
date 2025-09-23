#include <stdio.h>

enum EstadoPersonagem {
    PARADO, CORRENDO, PULANDO
};

int main(){
    enum EstadoPersonagem estado_atual;
    printf("DIgite o estado do personagem (0 para PARADO, 1 para CORRENDO, ou 2 para PULANDO))");
    scanf("%d", &estado_atual);
    if(estado_atual==PARADO){
        printf("O persongem esta parado");
    }
    else if(estado_atual==CORRENDO){
        printf("O persongem esta correndo");
    }
    else if(estado_atual==PULANDO){
        printf("O persongem esta pulando no ar");
    }
    else {
        printf("Estado invalido");
    }
}