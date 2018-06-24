typedef struct lista Lista;

Lista* cria();
Lista* insere(Lista* l, int i);
Lista* retira(Lista* l, int v);
void libera(Lista* l);
void imprime(Lista* l);
void imprimeUmElemento(Lista* l);
Lista* insereOrdenado(Lista* l, int v);
Lista* fusaoDeListasOrdenadas(Lista* lA, Lista* lB);
Lista* uniaoDeConjuntos(Lista* lA, Lista* lB);
Lista* intersecaoDeConjuntos(Lista* lA, Lista* lB);
Lista* diferencaEntreConjuntos(Lista* lA, Lista* lB);
int pertinencia(Lista* l, int v);