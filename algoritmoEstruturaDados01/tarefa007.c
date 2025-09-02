#include <stdio.h>

void ler_cenario(int n, int* c) {
    for(int i = 0; i<n; i++){
        printf("0 ou 1: ");
        scanf("%d", c + i);
    }
}

int main() {
    int n;
    printf("Numero de blocos: ");
    scanf("%d", &n);
    int c[n];
    int *pc = &c;
    ler_cenario(n, pc);    

    for(int a=0; a<n; a++){
        if(c[a]==1){
            c[a]=2;
            printf("\nO 1 esta aqui na posicao: %d", a);
            printf("\nO valor agora eh: %d\n", c[a]);
            break;
        }
    }

    for(int i=0; i<n; i++){
        printf("%d ", c[i]);
    }

    return 0;
}