typedef struct lista Lista;

Lista* criaPolinomio();

Lista* insereElementoNoPolinomio(Lista* l, int c, int e);

void imprimePolinomio(Lista* l);

void liberaPolinomio(Lista* l);

Lista* somaPolinomios(Lista* polX, Lista* polY);

int ordemDosPolinomios(Lista* polX, Lista* polY);