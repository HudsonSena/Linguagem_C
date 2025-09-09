#include <stdio.h>
#include <stdlib.h>
int main(){
    float *ponteiro_altura_salto_duplo = NULL;
    printf("\nJogador ainda nao possui o Salto Duplo");
    ponteiro_altura_salto_duplo = (float*) malloc(sizeof(float));
    
    if(ponteiro_altura_salto_duplo == NULL){
        printf("Error");
        return 0;
    } else {
        *ponteiro_altura_salto_duplo = 15.5;
        printf("\nPena Dourada coletada! Altura so Salto Duplo: %.2f", *ponteiro_altura_salto_duplo);
        free(ponteiro_altura_salto_duplo);//Linha liberada
    }
}