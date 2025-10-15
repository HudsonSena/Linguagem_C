#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("../naoexiste.b", "rb");
    if(file == NULL) {
        printf("Ocorreu um erro ao abrir o arquivo\n");
        perror(file);
        system("pause");
        exit(1);
    }
}