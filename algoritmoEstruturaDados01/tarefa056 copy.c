#include <stdio.h>

int soma(int n) {
    if(n == 1){
        return 1;
    }
    return n + soma(n -1);
}

int main() {
    int n;
    printf("Informe o valor de N\n");
    scanf("%d", &n);
    int r = soma(n);
    printf("%d\n", r);
}