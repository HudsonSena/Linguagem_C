#include <stdio.h>

int fatorial(int n){
    int f = 1;

    while(n>=1){
        f = f*n;
        n--;
    }
    
    return f;
}

int main(){
    int a, b;
    printf("Digite um número: ");
    scanf("%d", &a);
    b = fatorial(a);
    printf("O fatorial de %d eh %d \n", a, b);
    return -1;
}
