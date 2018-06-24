/* TAD LISTA */

typedef struct lista Lista;

Lista* criar();
Lista* inserir(Lista* l, int v);
void liberar(Lista* l);
void imprimir(Lista* l);
int testar(Lista* l);

/* TAD ORDENACAO */

Lista* bubbleSort(Lista* l);
Lista* insertionSort(Lista* l);
Lista* selectionSort(Lista* l);