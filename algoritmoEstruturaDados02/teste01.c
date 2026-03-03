#include <stdio.h>

void im(int x) {
    if(x > 0) {
        im(x - 1);
        printf("%d ", x);
    } else {
        printf("%d ", x);
    }
}

int main() {
    int n;
    printf("Digite um valor maior que 0: ");
    scanf("%d", &n);

    im(n);

    return 0;
}