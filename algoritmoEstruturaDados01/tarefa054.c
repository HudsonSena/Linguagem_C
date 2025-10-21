#include <stdio.h>

typedef struct {
    int id;
    char nome[50];
    int forca;
    int agi;
    int inte;
} personagem;

void ler(personagem *per) {
    printf("Digite: Id, nome, forca, agilidade e inteligencia.\n");
        scanf("%d %s %d %d %d", &per->id, per->nome, &per->forca, &per->agi, &per->inte);
}

void menu() {
    printf("\n==== Menu de opcoes =====\n");
    printf("= 1 - Buscar personagem =\n");
    printf("= 2 - Sair              =\n");
    printf("=========================\n");
}

int pesquisar(int id, int n, personagem v[]) {
    int i;
    for(i=0; i<n; i++) {
        if(v[i].id == id) {
            return i;
        }
    }
    printf("Personagem nao exite!\n");
    return -1;
}

int main() {
    int n;
    printf("Quantos personagens:\n");
    scanf("%d", &n);
    personagem v[n];
    int i;
    for(i=0; i<n; i++){
        ler(&v[i]);
        
    }
    int op;
    menu();
    scanf("%d", &op);
    while(op != 2) {
        if(op == 1) {
            int id;
            printf("Digite o id\n");
            scanf("%d", &id);
            int idp = pesquisar(id, n, v);
            if(idp != -1) {
                float media = (v[idp].forca + v[idp].agi + v[idp].inte)/3;
                printf("%s - Media de Atributos: %.2f\n", v[idp].nome, media);
            }
        }
        menu();
        scanf("%d", &op);
    }
    printf("Programda finalizado!\n");
}