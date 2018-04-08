typedef struct lista Lista;

Lista* cria();
void libera(Lista* l);
Lista* insere(Lista* l, int i);
Lista* insereFinal(Lista* l, int i);
Lista* insereFinalRec(Lista* l, int i);
Lista* retira(Lista* l, int v);
int vazia(Lista* l);
Lista* busca(Lista* l, int v);
void imprime(Lista* l);
void imprimeNo(Lista* l);
Lista* somaListas(Lista* l1, Lista* l2);
int somaPrimos(Lista* l);
Lista* removeKEsimaCelula(Lista* l, int v);
Lista* intercala(Lista* l1, Lista* l2);

/* FUNÇÕES AUXILIARES */

int testaPrimo(int n);

/* CORREÇÃO */

Lista* retiraK(Lista* l, int k);
Lista* intercala(Lista* l1, Lista* l2);