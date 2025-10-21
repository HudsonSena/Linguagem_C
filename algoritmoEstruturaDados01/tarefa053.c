#include <stdio.h>

int main() {
    int n;
    printf("Energia do Golem:\n");
    scanf("%d", &n);
    int i;
    for(i=n; i>1; i=i/2) {
        printf("Energia: %d\n", i);
    }
}