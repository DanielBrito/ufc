typedef struct fila Fila;

Fila* filaCria();
void filaInsere(Fila* f, int v);
int filaRetira(Fila* f);
int filaVazia(Fila* f);
void filaLibera(Fila* f);
void filaImprime(Fila* f);
void removeNegativos(Fila* f);