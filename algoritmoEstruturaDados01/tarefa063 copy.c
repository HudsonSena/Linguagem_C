#include <stdio.h>

int main() {
    int n;
    printf("Informe o valor de n\n");
    scanf("%d", &n);
    int i;
    int v[n+1];
    printf("Valores:\n");
    for(i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    int x;
    printf("Valor de x:\n");
    scanf("%d", &x);
    for(i= n-1; i>=0 && x<v[i]; i--) {
        v[i+1] = v[i];
    }
    v[i+1] = x;
    printf("Imprimindo o vetor\n");
    for(i=0; i<n+1; i++) {
        printf("%d ", v[i]);
    }
}