#include <stdio.h>

void particao(int n, int v[]) {
    //Entrada: 30 80 100 90 40 20 10 70 60 50
    //Saída: 30 40 20 10 50 100 90 70 60 80 
    int pivo = v[n-1];
    int j = -1;
    int i;
    for(i=0; i<n-1; i++) {
        if(v[i] < pivo) {
            j++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    int temp = v[j+1];
    v[j+1] = v[n-1];
    v[n-1] = temp;
}

int main() {
    int n;
    printf("Numero de unidades mecha:\n");
    scanf("%d", &n);
    int v[n];
    int i;
    for(i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    particao(n, v);
    printf("Vidas das unidades:\n");
    for(i=0; i<n; i++) {
        printf("| %d ", v[i]);
    }
    printf("\n");
}