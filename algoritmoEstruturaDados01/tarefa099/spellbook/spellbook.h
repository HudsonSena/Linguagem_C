
typedef struct Spell spell;

typedef struct no No;

typedef struct spellbook Spellbook;

void menu();

void ler(spell *pe);

void add_spell(Spellbook *pspellbook, spell dado);

void inserir_fim(Spellbook *pspellbook, spell dado);

void destroy_spellbook(Spellbook *pspellbook);

void display_spellbook(Spellbook spellbook);

Spellbook create_spellbook(int n);

void main_spellbook();