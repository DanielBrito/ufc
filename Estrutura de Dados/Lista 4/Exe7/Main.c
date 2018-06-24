#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"

#define N 5

int ttt(int* x, int n);
int tttP(Pilha* p);

int main(){

    int v[N], i;
    Pilha* p = p_cria();

    for(i=0; i<N; i++){

        printf("v[%d] = ", i);
        scanf("%d", &v[i]);

        p_push(p, v[i]);
    }

    printf("\nResultado da funcao: %d \n", ttt(v, N));

    printf("Resultado da pilha: %d\n", tttP(p));

    p_libera(p);
    
    return 0;
}

int ttt(int* x, int n){

    if(n==-1) return 0;
    if(x[n-1]>0) return x[n-1] + ttt(x, n-1);
    else return ttt(x, n-1);
}

int tttP(Pilha* p){

    int soma = 0, num;

    while(!p_vazia(p)){

        num = p_pop(p);

        if(num>0){

            soma += num;
        }
    }

    return soma;
}