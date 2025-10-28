#include <stdio.h>

int nivel(int n) {
    if(n==1){
        return 1;
    }
    return n + nivel(n - 1);
}

int main() {
    int n;
    printf("Nivel do Mago:\n");
    scanf("%d", &n);
    int r = nivel(n);
    printf("O mago de nivel %d\nDano total do Atque em Cascata: %d", n, r);
}