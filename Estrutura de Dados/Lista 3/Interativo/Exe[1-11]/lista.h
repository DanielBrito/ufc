typedef struct lista Lista;

Lista* cria();

Lista* insere(Lista* l, int i);

Lista* insereFinal(Lista* l, int i);

Lista* insereFinalRec(Lista* l, int i)

Lista* retira(Lista* l, int v);

void libera(Lista* l);

void imprime(Lista* l);

void imprimeUmElemento(Lista* l);

Lista* buscaMenorElemento(Lista* l);

Lista* retiraValorMaximo(Lista* l);

int contaCelulas(Lista* l);

Lista* concatenaListas(Lista* lA, Lista* lB);

Lista* removeKEsimaCelula(Lista*, int v);

Lista* removeElementoX(Lista* l, int x);

Lista* removeElementosRepetidos(Lista* l);

int contaElemento(Lista* l, int x);

int verificaPrimo(int n);

int contaPrimos(Lista* l);

int somaPrimos(Lista* l);

Lista* somaListas(Lista* lA, Lista* lB);