typedef struct lista Lista;

Lista* cria();
Lista* insere(Lista* l, int i);
Lista* retira(Lista* l, int v);
void libera(Lista* l);
void imprime(Lista* l);
void imprimeUmElemento(Lista* l);
int verificaPrimo(int n);
Lista* removeNulos(Lista* l);
int igualdade(Lista* lA, Lista* lB);
int conta(Lista* l, int v);
Lista* encontraPrimos(Lista* l);
Lista* insereOrdenado(Lista* l, int v);