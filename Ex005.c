#include <stdio.h>

int main(){
    int id;
    char ti;
    printf("Qual a sua idade? ");    
    scanf("%d", &id);

    getchar();

    printf("Voce tem Titulo de Eleitor (N/S)? ");
    scanf("%c", &ti);
    
    if(id>=16){
        if(ti == 'N'){
            printf("Faca seu titulo de eleitor");
        } else {
            printf("Esta apto a votar!");
        }
    } else {
        printf("Nao possui idade!");
    }

    return 0;
}