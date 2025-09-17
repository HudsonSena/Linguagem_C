#include <stdio.h>
int main(){
    int n;
    printf("tamanho matriz:\n");
    scanf("%d", &n);
    int m[n][n], cont=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(m[i-1][j-1] == i || m[i-1][j-1] == 0){
                m[i][j] = m[i-1][j-1] + 1;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    return 0;
}