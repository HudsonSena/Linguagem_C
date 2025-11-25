#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int particao(int e, int d, int v[]) {
    srand(time(NULL));
    int idx = e + (rand() % (d-e));
    printf("Pivor: %d \n", idx);
    int  temp = v[idx];
    v[idx] = v[d];
    v[d] = temp;
    int j = e - 1;
    int i;
    int pivo = v[d];
    for(i=e; i<d; i++) {
        if(v[i] <= pivo) {
            j++;
            temp = v[j];
            v[j] = v[i];
            v[i] = temp;
        }
    }
    temp = v[j+1];
    v[j+1] = v[d];
    v[d] = temp;
    return j + 1;
}

void quicksort(int i, int f, int v[]) {
    if(i<f) {
        int p = particao(i, f, v);
        quicksort(i, p -1, v);
        quicksort(p+1, f, v);
    }
}

int main() {
    int n;
    printf("Informe o valor de n\n");
    scanf("%d", &n);
    int v[n];
    int i;
    for(i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    quicksort(0, n-1, v);
    printf("Imprimindo o vetor\n");
    for(i=0; i<n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}