typedef struct fila2 Fila2;

Fila2* f2_cria();
void f2_insere_ini(Fila2* f, float v);
void f2_insere_fim(Fila2* f, float v);
float f2_retira_ini(Fila2* f);
float f2_retira_fim(Fila2* f);
int f2_vazia(Fila2* f);
void f2_libera(Fila2* f);
int f2_quantidade(Fila2* f);
void f2_imprime(Fila2* f);
