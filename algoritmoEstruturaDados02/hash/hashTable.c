#include <stdio.h>
#include "aluno.c"
#include "hashFunction.c"

typedef struct hashTable {
    Aluno *tabela;
} HashTable;

void intHashtable(HashTable *ht) {
    ht->tabela = malloc(sizeof(Aluno) * 100);
    for(int i=0; i<100; i++) {
        ht->tabela[i].matricula = -1;
    }
}
void inserir(HashTable *ht, Aluno A) {
    int x = hashFunction(A);
    int o = x;
    while(ht->tabela[x].matricula != -1) {
        x = (x + 1) % 100;
        if(x == o) {
            printf("HashTable cheia\n");
            return;
        }
    }
    ht->tabela[x] = A;
}

void printHashTable(HashTable *ht) {
    for(int i=0; i<100; i++) {
        if(ht->tabela[i].matricula != -1) {
            printf("Posicao: %d\n", i);
            mostrarAluno(ht->tabela[i]);
        }
    }
}

