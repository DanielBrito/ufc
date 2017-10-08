typedef struct lista Lista;

Lista* cria();

Lista* insere(Lista* l, int i);

void libera(Lista* l);

void imprime(Lista* l);

Lista* constroi(int* v, int n);