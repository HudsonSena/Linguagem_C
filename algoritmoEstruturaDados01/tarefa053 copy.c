#include <stdio.h>

int main() {
    int n;
    printf("Informe o valor de n\n");
    scanf("%d", &n);
    int i;
    for(i=n; i>1; i=i/2) {
        printf("%d\n", i);
    }
}