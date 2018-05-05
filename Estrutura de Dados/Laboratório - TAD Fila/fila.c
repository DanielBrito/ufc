#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "lista.h"

struct fila{

    struct lista* ini;
    struct lista* fim;
};

Fila* filaCria(){

    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->ini = listaCria();
    f->fim = listaCria();

    return f;
}

void filaInsere(Fila* f, float v){

    Lista* aux = listaCria();
    aux = listaInsere(aux, v);

    if(listaVazia(f->ini)){

        f->ini = aux;
    }
    else{

        setProx(f->fim, aux);
    }

    f->fim = aux;
}

float filaRetira(Fila* f){

    if(filaVazia(f)){

        printf("Nao foi possivel remover. Fila vazia!\n");
        exit(1);
    }

    float n;
    n = listaRetornaInicio(f->ini);
    f->ini = listaRemoveInicio(f->ini);

    return n;
}

int filaVazia(Fila* f){

    return listaVazia(f->ini);
}

void filaLibera(Fila* f){

    listaLibera(f->ini);
    free(f);
}

void filaImprime(Fila* f){

    if(filaVazia(f)){

        printf("Nao foi possivel imprimir. Fila Vazia!\n");
        exit(1);
    }

    Fila* aux = filaCria();
    float n;

    while(!filaVazia(f)){

        n = filaRetira(f);
        printf("%.2f  ", n);
        filaInsere(aux, n);
    }

    while(!filaVazia(aux)){

        filaInsere(f, filaRetira(aux));
    }

    printf("\n");
}