typedef struct pilha Pilha;

Pilha* p_cria(void);
void p_push(Pilha* p, float v);
float p_pop(Pilha* p);
int p_vazia(Pilha* p);
void p_libera(Pilha* p);
int contaElementos(Pilha* p);
Pilha* copia(Pilha* p);
Pilha* inverte(Pilha* p);
float* retornaValores(Pilha* p, float* vet, int n);