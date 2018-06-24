typedef struct lista Lista;

Lista* listaCria();
Lista* listaInsere(Lista* l, int v);
Lista* listaRemoveInicio(Lista* l);
int listaRetornaInicio(Lista* l);
int listaVazia(Lista* l);
void setProx(Lista* l, Lista* p);
void listaLibera(Lista* l);