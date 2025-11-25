#include <stdio.h>

void particao(int n, int v[]) {
    int s[n];
    //9 8 7 6 5 3 2 1 0 4
    //3 2 1 0 5 6 7 8 9
    int e = 0;
    int d = n-1;
    int pivo = v[n-1];
    int i;
    for(i=0; i<n; i++) {
        if(v[i] <= pivo) {
            s[e] = v[i];
            e++;
        }
        else {
            s[d] = v[i];
            d--;
        }
    }
    for(i=0; i<n; i++) {
        v[i] = s[i];
    }
}

int main() {
    int n;
    printf("Quantidade de itens:\n");
    scanf("%d", &n);
    int i;
    int v[n];
    for(i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    particao(n, v);
    printf("Itens particionados por nivel de poder\n");
    for(i=0; i<n; i++) {
        printf("| %d ", v[i]);
    }
    printf("\n");
}