#include <stdio.h>
#include "hash.h"
#include "bloom_filter.h"

int main() {
    /*Hash hash;
    inicializarTabelaHash(&hash);

    inserir(&hash, "Alice123");
    inserir(&hash, "Bob");
    inserir(&hash, "Charlie");

    if (buscar(&hash, "Alice122")) {
        printf("Usuario encontrado!\n");
    } else {
        printf("Usuario não encontrado!\n");
    }

    liberar(&hash);*/

    BloomFilter bloom;
    
    inicializarBloomFilter(&bloom);
    
    inserirBloom(&bloom, "Alice123");

    if(buscarBloom(&bloom, "Alice123")) {
        printf("Usuario possivelmente encontrado!\n");
    }

    if(buscarBloom(&bloom, "Bob")) {
        printf("Usuario possivelmente encontrado!\n");
    }

    if(buscarBloom(&bloom, "Charlie")) {
        printf("Usuario possivelmente encontrado!\n");
    } else {
        printf("Usuario não encontrado!\n");
    }

    return 0;

}