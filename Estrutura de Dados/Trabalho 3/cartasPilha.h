typedef struct pilha Pilha;

typedef struct carta Carta;

/* Pilha */

Pilha * p_cria();

void p_push(Pilha *p, Carta* carta);

void p_pop(Pilha* p);

Carta* p_pop_aux(Pilha *p);

int p_vazia(Pilha *p);

void p_libera(Pilha *p);

char getTopo(Pilha *p);


/* Cartas */

Carta* cria_Carta();

void preencherCarta(Carta* *card, char *nome, int id);

void dados_carta(Carta* carta);

void imprime(Pilha *p);


