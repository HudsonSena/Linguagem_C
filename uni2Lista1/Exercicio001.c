#include <stdio.h>

int main(){
    int id;
    char ti;
    printf("Qual a sua idade? ");
    scanf("%d", &id);
    printf("Você tem Título de Eleitor (N/S)? ");
    scanf("%c", &ti);
    if(id>=18){
        if(ti == 'N'){
            printf("Faça seu título de eleitor!");
        } else {
            printf("Está apto a votar!");
        }
    } else {
        printf("Não possui idade!");
    }

    return 0;
}