typedef struct fila Fila;

Fila* filaCria();
void filaInsere(Fila* f, char ch);
char filaRetira(Fila* f);
int filaVazia(Fila* f);
void filaLibera(Fila* f);
void filaImprime(Fila* f);