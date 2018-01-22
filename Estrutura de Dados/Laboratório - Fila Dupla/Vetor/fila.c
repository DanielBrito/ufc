#include<stdio.h>
#include<stdlib.h>
#include"fila.h"

#define MAX 50

struct fila2{

     int n;
     int ini;
     float v[MAX];
};

Fila2* f2_cria(){

     Fila2* f = (Fila2*)malloc(sizeof(Fila2));

     f->n = 0;
     f->ini = 0;

     return f;
}

void f2_insere_ini(Fila2* f, float v){

     int prec;

     if(f->n == MAX){

          printf("Fila cheia!\n");
          exit(1);
     }

     prec = (f->ini-1 + MAX) % MAX;

     f->v[prec] = v;
     f->ini = prec;

     f->n++;
}


void f2_insere_fim(Fila2* f, float v){

     int fim;

     if(f2_quantidade(f)==MAX){

          printf("Fila cheia!\n");
          exit(1);
     }

     fim = (f->ini + f->n) % MAX;
     f->v[fim] = v;
     f->n++;
}


float f2_retira_ini(Fila2* f){

     float v;

     if(f2_vazia(f)){

          printf("Fila vazia!\n");
          exit(1);
     }

     v = f->v[f->ini];
     f->ini = (f->ini + 1) % MAX;
     f->n--;

     return v;
}


float f2_retira_fim(Fila2* f){

     int ult;
     float v;

     if(f2_vazia(f)){

          printf("Fila vazia!\n");
          exit(1);
     }

     ult = (f->ini + f->n - 1) % MAX;
     v = f->v[ult];
     f->n--;

     return v;
}


int f2_vazia(Fila2* f){

     return f->n == 0;
}


void f2_libera(Fila2* f){

     free(f);
}


int f2_quantidade(Fila2* f){

     return f->n;
}
