#include <stdio.h>

typedef struct {
    int id;
    char nickname[50];
    int pontos;
} jogador;

void menu() {
    printf("======== Menu de opcoes =======\n");
    printf("1 - Adicionar Reputacao\n");
    printf("2 - Sair\n");
    printf("===============================\n");
}

void ler(jogador *jo) {
    scanf("%d %s %d", &jo->id, jo->nickname, &jo->pontos);
}

int buscabinaria(int id, int n, jogador v[]) {
    int i = 0;
    int f = n - 1;
    while(i<= f) {
        int meio = (i+f)/2;
        if(v[meio].id == id) {
            return meio;
        }
        else if(v[meio].id < id) {
            i = meio +1;            
        }
        else {
            f = meio -1;
        }
    }
    return -1;
}

int main(){
    int n;
    printf("Informe o numero de jogadores\n");
    scanf("%d", &n);
    jogador v[n];
    int i;
    for(i=0; i<n; i++){
        ler(&v[i]);
    }
    int op;
    menu();
    scanf("%d", &op);
    while(op != 2){
        if(op == 1){
            int id;
            printf("Id do jogador:\n");
            scanf("%d", &id);
            int idx = buscabinaria(id, n, v);
            if(idx != -1){
                v[idx].pontos = v[idx].pontos + 100;
                printf("Nickname: %s\nNova reputacao: %d\n", v[idx].nickname, v[idx].pontos); 
            } else {
                printf("Jogador com ID %d, nao encontrado\n", id);
            }
        }
        menu();
        scanf("%d", &op);
    }
    printf("Programa finalizado");
}