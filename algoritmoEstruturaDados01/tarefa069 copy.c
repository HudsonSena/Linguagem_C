#include <stdio.h>

void intercala(int n, int v1[], int m, int v2[], int r[]) {
    int i = 0;
    int j = 0;
    int k = 0;
    while(i<n && j<m) {
        if(v1[i] < v2[j]) {
            r[k] = v1[i];
            i++;
        }
        else {
            r[k] = v2[j];
            j++;
        }
        k++;        
    }
    while (i<n) {
        r[k] = v1[i];
        i++;
        k++;
    }
    while (j<m) {
        r[k] = v2[j];
        j++;
        k++;
    }
}

int main() {
    int n;
    printf("Informe o valor de n\n");
    scanf("%d", &n);
    int v1[n];
    int i;
    for(i=0; i<n; i++) {
        scanf("%d", &v1[i]);
    }

    int m;
    printf("Informe o valor de m\n");
    scanf("%d", &m);
    int v2[m];
    for(i=0; i<m; i++) {
        scanf("%d", &v2[i]);
    }
    int r[n + m];
    intercala(n, v1, m, v2, r);
    printf("Imprimindo resultado:\n");
    for(i=0; i<n+m; i++) {
        printf("| %d ", r[i]);
    }
    printf("\n");
    // 1 3 5 7 9
    // 0 2 4 6 8
}