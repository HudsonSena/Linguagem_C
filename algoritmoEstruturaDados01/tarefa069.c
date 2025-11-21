#include <stdio.h>

void intercalacao(int n, int m, int v1[], int v2[], int v3[]) {
    int i = 0;
    int j = 0;
    int k = 0;
    while(i<n && j<m) {
        if(v1[i] < v2[j]) {
            v3[k] = v1[i];
            i++;
        }
        else {
            v3[k] = v2[j];
            j++;
        }
        k++;
    }
    while(i<n) {
        v3[k] = v1[i];
        i++;
        k++;
    }
    while(j<m) {
        v3[k] = v2[j];
        j++;
        k++;
    }

}

int main() {
    int n;
    printf("numero de inimigos Portal Alfa:\n");
    scanf("%d", &n);
    int v1[n];
    printf("Niveis de ameaca Alfas:\n");
    int i;
    for(i=0; i<n; i++) {
        scanf("%d", &v1[i]);
    }

    int m;
    printf("numero de inimigo Portal Beta:\n");
    scanf("%d", &m);
    int v2[m];
    printf("Niveis de ameaca Betas:\n");
    for(i=0; i<m; i++) {
        scanf("%d", &v2[i]);
    }

    int v3[n+m];

    intercalacao(n, m, v1, v2, v3);

    for(i=0; i<n+m; i++) {
        printf("| %d ", v3[i]);
    }
    printf("\n");
}