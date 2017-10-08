typedef struct lista Lista;

Lista* cria();

Lista* insere(Lista* l, int i);

void libera(Lista* l);

void imprime(Lista* l);

Lista* separa(Lista* lA, int v);