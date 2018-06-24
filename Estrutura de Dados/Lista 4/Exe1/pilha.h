typedef struct pilha Pilha;

Pilha* inicializaPilhas();

void empilhaP1(Pilha* p, int n);
void empilhaP2(Pilha* p, int n);

int desempilhaP1(Pilha* p);
int desempilhaP2(Pilha* p);

int pilha1Vazia(Pilha* p);
int pilha2Vazia(Pilha* p);

int pilha1Cheia(Pilha* p);
int pilha2Cheia(Pilha* p);

void libera(Pilha* p);