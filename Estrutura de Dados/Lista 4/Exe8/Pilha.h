typedef struct pilha Pilha;

Pilha* p_cria(void);
void p_push(Pilha* p, float v);
float p_pop(Pilha* p);
int p_vazia(Pilha* p);
void p_libera(Pilha* p);
int compara(Pilha* p1, Pilha* p2);
Pilha* inverte(Pilha* p);