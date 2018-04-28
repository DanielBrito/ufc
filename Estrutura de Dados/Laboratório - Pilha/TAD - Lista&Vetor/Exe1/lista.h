typedef struct lista Lista;

Lista* listaCria();
Lista* listaInsereIni(Lista* l, char ch);
void listaLibera(Lista* l);
Lista* listaRemovePrim(Lista* l);
int listaVazia(Lista* l);
char listaPrimeiro(Lista* l);