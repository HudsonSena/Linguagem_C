#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spellbook.h"

struct Spell {
    int id;
    char name[50];
    int mana_cost;
};

struct no {
    spell dado;
    struct no* prox;
};

struct spellbook {
    No* inicio;
};

void menu() {
    printf("===== Menu de Opcoes =====\n");
    printf("1 - Criar grimorio\n");
    printf("2 - Adicionar novo feitico\n");
    printf("3 - Mostrar feiticos\n");
    printf("4 - Destruir grimorio\n");    
    printf("5 - Sair\n");
    printf("==========================\n");
}

void ler(spell *pe) {
    printf("Digite o ID, name e mana const do spell: ");
    scanf("%d %s %d", &pe->id, pe->name, &pe->mana_cost);
}

void add_spell(Spellbook *pspellbook, spell dado) {
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = NULL;
    if (pspellbook->inicio == NULL) {
        pspellbook->inicio = novo;
    } else {
        No* pi = pspellbook->inicio;
        while (pi->prox != NULL) {
            pi = pi->prox;
        }
        pi->prox = novo;
    }
}

void display_spellbook(Spellbook spellbook) {
    No * pi;
    for(pi=spellbook.inicio; pi!=NULL; pi=pi->prox){ printf("ID: %d, Name: %s, Mana Costa:\n", pi->dado.id, pi->dado.name, pi->dado.mana_cost); }
}

void destroy_spellbook(Spellbook *spellbook) {
    No * pi;
    while(spellbook->inicio != NULL) {
        pi = spellbook->inicio;
        spellbook->inicio = pi->prox;
        free(pi);
    }    
}

Spellbook create_spellbook(int n) {
    Spellbook spellbook;
    spellbook.inicio = NULL;
    int i;
    for(i=0; i<n; i++) {
        spell e;
        ler(&e);
        add_spell(&spellbook, e);            
    }
    return spellbook;    
}

void main_spellbook() {
    Spellbook spellbook;
    spellbook.inicio = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while(op!=5) {
        if(op==1) {
            int n;
            printf("Informe a quantidade de feiticos:\n");
            scanf("%d", &n);
            spellbook = create_spellbook(n);
        }
        if(op==2) {
            spell e;
            ler(&e);
            add_spell(&spellbook, e);            
        }
        if(op==3) {
            display_spellbook(spellbook);            
        }
        if(op==4) {
            destroy_spellbook(&spellbook);
        }
        
        menu();
        scanf("%d", &op);
    }
}
