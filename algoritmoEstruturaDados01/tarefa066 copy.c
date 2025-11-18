#include <stdio.h>

int main() {
    int n, i, j;
    printf("Informe o valor de n\n");
    scanf("%d", &n);
    int v[n];
    for(i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(v[j] > v[j+1]) {
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
    printf("Imprimindo vetor\n");
    for(i=0; i<n; i++) {
        printf("| %d ", v[i]);
    }
    printf("|");
    printf("\n");
}