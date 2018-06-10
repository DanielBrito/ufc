typedef struct lista Lista;

Lista* cria();
void libera(Lista* l);
Lista* insere(Lista* l, int i);
Lista* insereFinal(Lista* l, int i);
Lista* retira(Lista* l, int v);
int vazia(Lista* l);
void imprime(Lista* l);