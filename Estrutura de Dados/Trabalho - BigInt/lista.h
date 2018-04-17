typedef struct lista Lista;
typedef struct no No;

Lista* cria();
Lista* insereInicio(Lista* l, char ch);
Lista* insereFinal(Lista* l, char ch);
void imprime(Lista* l);
void libera(Lista *l);
int acessaDigito(No* no);
No* acessaProx(No* no);
No* acessaAnt(No* no);
No* acessaNo(Lista* l);
No* acessaIni(Lista* l);
No* acessaFim(Lista* l);
Lista* removeZeroInicio(Lista *l);
int contaDigitos(Lista *l);
int converteInt(char ch);
char converteChar(int v);
Lista* alteraNo(Lista *l, Lista *novo);