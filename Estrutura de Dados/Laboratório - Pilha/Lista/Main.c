#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include"Pilha.h"

#define for(a,b) for(a=0; a<b; a++)

int main(){

    Pilha* p;
    int j;

    p = p_cria();

    for(j, 10){
        
        p_push(p, j);
    }

    while(!p_vazia(p)){

        printf("%.2f\n", p_pop(p));
    }

    p_libera(p);

    return 0;
}