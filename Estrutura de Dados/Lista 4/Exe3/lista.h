typedef struct lista Lista;

Lista* listaCria();
Lista* listaInsere(Lista* l, float v);
Lista* listaRemoveInicio(Lista* l);
float listaRetornaInicio(Lista* l);
int listaVazia(Lista* l);
void setProx(Lista* l, Lista* p);
void listaLibera(Lista* l);