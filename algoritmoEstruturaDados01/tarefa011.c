#include <stdio.h>
int main(){
    int balas[2] = {30, 30};
    int granadas[2] = {5, 5};
    int foguetes[2] = {2, 2};
    int *inventario[3];
    inventario[0] = balas;
    inventario[1] = granadas;
    inventario[2] = foguetes;
    printf("\nInventario Inicial:");
    printf("\nBalas: %d/%d", *(*inventario), *((*inventario)+1));
    printf("\nGranadas: %d/%d", *(*(inventario + 1)), *(*(inventario + 1)+1));
    printf("\nFoguetes: %d/%d", *(*(inventario + 2)), *(*(inventario + 2)+1));
    for(int i=0; i<3; i++){
        *(*(inventario + i)) = *(*(inventario + i)) -1;
    }
    printf("\nInventario Apos o Uso:");
    printf("\nBalas: %d/%d", *(*inventario), *((*inventario)+1));
    printf("\nGranadas: %d/%d", *(*(inventario + 1)), *(*(inventario + 1)+1));
    printf("\nFoguetes: %d/%d", *(*(inventario + 2)), *(*(inventario + 2)+1));
    return 0;
}