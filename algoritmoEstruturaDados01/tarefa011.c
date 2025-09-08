#include <stdio.h>
int main(){
    int balas[2] = {30, 50};
    int granadas[2] = {5, 12};
    int foguetes[2] = {2, 7};
    int *inventario[3];
    inventario[0] = balas;
    inventario[1] = granadas;
    inventario[2] = foguetes;
    printf("\nInventario Inicial:");
    printf("\nBalas: %d", *(*(inventario)));
    printf("\nGranadas: %d", *(*(inventario + 1)));
    printf("\nFoguetes: %d", *(*(inventario + 2)));
    for(int i=0; i<3; i++){
        *(*(inventario + i)) = *(*(inventario + i)) -1;
    }
    printf("\nInventario Apos o Uso:");
    printf("\nBalas: %d", *(*(inventario)));
    printf("\nGranadas: %d", *(*(inventario + 1)));
    printf("\nFoguetes: %d", *(*(inventario + 2)));
    return 0;
}