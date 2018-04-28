typedef struct pilha Pilha;

Pilha* inicializaPilha();
void empilha(Pilha* p, char ch);
char desempilha(Pilha* p);
int pilhaVazia(Pilha* p);
int pilhaCheia(Pilha* p);
void libera(Pilha* p);
void imprimePilha(Pilha* p);

/* Operações */

void imprimeReversa(Pilha* p);
int palindrome(Pilha* p);
void elimina(Pilha*, char ch);
void maiusculoMinusculo(Pilha* p);

/* Funções auxiliares */

Pilha* copiaPilhaV(Pilha* p);
Pilha* invertePilhaV(Pilha* p);

Pilha* copiaPilhaL(Pilha* p);
Pilha* invertePilhaL(Pilha* p);