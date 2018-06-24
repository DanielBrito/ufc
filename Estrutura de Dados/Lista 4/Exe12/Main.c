#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include"Pilha.h"

int main(){

    Pilha* p = p_cria();
    Pilha* pC = p_cria();
   	int i;

    for(i=1; i<=5; i++){
        
        p_push(p, i);
    }

    pC = inverte(p);

    printf("Pilha original:\n");
    p_imprime(p);

    printf("Copia da pilha:\n");
    p_imprime(pC);    

    p_libera(p);
    p_libera(pC);

    return 0;
}