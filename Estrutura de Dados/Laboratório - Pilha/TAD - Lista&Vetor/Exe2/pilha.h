typedef struct pilha Pilha;

Pilha* inicializaPilha1();
Pilha* inicializaPilha2();

void empilhaP1(Pilha* p1, Pilha* p2, int n);
void empilhaP2(Pilha* p2, Pilha* p1, int n);

int desempilhaP1(Pilha* p);
int desempilhaP2(Pilha* p);

int pilha1Vazia(Pilha* p);
int pilha2Vazia(Pilha* p);

int pilha1Cheia(Pilha* p1, Pilha* p2);
int pilha2Cheia(Pilha* p1, Pilha* p2);

void libera(Pilha* p);