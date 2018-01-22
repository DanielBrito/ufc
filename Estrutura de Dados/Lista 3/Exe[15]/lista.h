typedef struct lista Lista;

Lista* criaPolinomio();

Lista* insereElementoNoPolinomio(Lista* l, int c, int e);

void imprimePolinomio(Lista* l);

void liberaPolinomio(Lista* l);

Lista* somaPolinomios(Lista* polX, Lista* polY);

int ordemDosPolinomios(Lista* polX, Lista* polY);


// OUTRAS FUNÇÕES:

// Lista* retira(Lista* l, int v);

// void imprimeUmElemento(Lista* l);

// Lista* buscaMenorElemento(Lista* l);

// Lista* retiraValorMaximo(Lista* l);

// int contaCelulas(Lista* l);

// Lista* concatenaListas(Lista* lA, Lista* lB);

// Lista* removeKEsimaCelula(Lista*, int v);

// Lista* removeElementoX(Lista* l, int x);

// Lista* removeElementosRepetidos(Lista* l);

// int contaElemento(Lista* l, int x);

// int verificaPrimo(int n);

// int contaPrimos(Lista* l);

// int somaPrimos(Lista* l);

// int igualdadeMesmaOrdem(Lista* lA, Lista* lB);

// Lista* inverteLista(Lista* l);

// Lista* insereOrdenado(Lista* l, int v);

// Lista* fusaoDeListasOrdenadas(Lista* lA, Lista* lB);
