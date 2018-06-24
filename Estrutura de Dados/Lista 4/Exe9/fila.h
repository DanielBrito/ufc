typedef struct fila Fila;

Fila* filaCria();
void filaInsere(Fila* f, float v);
float filaRetira(Fila* f);
int filaVazia(Fila* f);
void filaLibera(Fila* f);
void filaImprime(Fila* f);
void inverteFila(Fila* f);