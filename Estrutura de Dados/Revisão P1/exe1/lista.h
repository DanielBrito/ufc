typedef struct lista Lista;

Lista* cria();
void libera(Lista* l);
Lista* insere(Lista* l, int v);
Lista* retira(Lista* l, int v);
int vazia(Lista* l);
Lista* busca(Lista* l, int v);
void imprime(Lista *l);
void imprimeNo(Lista* l);
Lista* insereOrdenado(Lista* l, int v);
Lista* listaImpares(Lista*l, Lista** par);
Lista* insereFinal(Lista*l, int v);
