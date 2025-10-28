#include <stdio.h>

int energia(int i, int n, int v[]) {
    if(i == n){
        return 0;
    }
    if(v[i] > 0){
        return 1 + energia(i + 1, n, v);
    }
    return energia(i + 1, n, v);
}

int main() {
    int n;
    printf("Quantidade de Cristais:\n");
    scanf("%d", &n);
    int v[n];
    int i;
    for(i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    int r = energia(0, n, v);
    printf("%d cristais com energia", r);
}