typedef struct pilha Pilha;

Pilha* p_cria(void);
void p_push(Pilha* p, char ch);
char p_pop(Pilha* p);
int p_vazia(Pilha* p);
void p_libera(Pilha* p);
void p_imprime(Pilha* p);