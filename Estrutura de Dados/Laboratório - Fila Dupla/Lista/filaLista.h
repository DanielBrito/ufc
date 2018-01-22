typedef struct lista2 Lista2;
typedef struct fila2 Fila2;

Fila2* fila2_cria();

void fila2_insere_ini(Fila2* f, float v);
void fila2_insere_fim(Fila2* f, float v);
float fila2_retira_ini(Fila2* f);
float fila2_retira_fim(Fila2* f);
int fila2_vazia(Fila2* f);


// Funções auxiliares:

Lista2* insere2_ini(Lista2* ini, float v);
Lista2* insere2_fim(Lista2* fim, float v);
Lista2* retira2_ini(Lista2* ini);
Lista2* retira2_fim(Lista2* fim);
