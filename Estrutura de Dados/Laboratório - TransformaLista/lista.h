typedef struct lista Lista;

Lista* listaCria();
Lista* listaInsere(Lista* l, char ch);
Lista* listaRemoveInicio(Lista* l);
char listaRetornaInicio(Lista* l);
int listaVazia(Lista* l);
void setProx(Lista* l, Lista* p);
void listaLibera(Lista* l);
void listaImprime(Lista* l);