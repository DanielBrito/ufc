#include<stdio.h>
#include<stdlib.h>
#include"fila.h"

int main(){

     Fila2* f = f2_cria();

     f2_insere_ini(f, 10.0);
     f2_insere_fim(f, 20.0);

     f2_insere_ini(f, 30.0);
     f2_insere_fim(f, 40.0);

     int qtd = f2_quantidade(f); printf("QTD: %d\n", qtd);

     f2_retira_ini(f);
     qtd = f2_quantidade(f); printf("QTD: %d\n", qtd);

     f2_retira_ini(f);
     qtd = f2_quantidade(f); printf("QTD: %d\n", qtd);

     f2_retira_ini(f);
     qtd = f2_quantidade(f); printf("QTD: %d\n", qtd);

     f2_retira_ini(f);
     qtd = f2_quantidade(f); printf("QTD: %d\n", qtd);

     f2_retira_ini(f);

     printf("\n\n");

     f2_libera(f);

     return 0;
}
