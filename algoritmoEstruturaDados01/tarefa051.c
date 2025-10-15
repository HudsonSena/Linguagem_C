#include <stdio.h>

struct inimigo {
    char tipo[50];
    int hp;
};

int main() {
    int n;
    printf("O valor de N:\n");
    scanf("%d", &n);
    int i;
    for(i=0; i<n; i++){
        struct inimigo e;
        printf("Informe o inimigo: e status:\n");
        scanf("%s %d", e.tipo, &e.hp);
        printf("Inimigo: %s, hp: %d\n", e.tipo, e.hp);
    }
}