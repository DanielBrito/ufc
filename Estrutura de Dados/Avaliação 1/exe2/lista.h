typedef struct lista Lista;

Lista* cria();

Lista* insere(Lista* l, int i);

void libera(Lista* l);

void imprime(Lista* l);

Lista* insereOrdenado(Lista* l, int v);

Lista* intercala(Lista* lA, Lista* lB);