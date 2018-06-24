#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include"Pilha.h"

int main(){

    Pilha* p1 = p_cria();
    Pilha* p2 = p_cria();
    int i, x;

    for(i=1; i<=5; i++){
        
        p_push(p1, i);
    }

    for(i=1; i<=5; i++){
        
        p_push(p2, i);
    }

    printf("Teste 1: ");

    if(compara(p1, p2)==1){

    	printf("Pilhas iguais.\n");
    }
    else{

    	printf("Pilhas diferentes.\n");
    }

    p1 = p_cria();
    p2 = p_cria();

    x=1;

    for(i=0; i<5; i++){
        
        p_push(p1, x);
        ++x;
    }

    x=1;

    for(i=0; i<9; i++){
        
        p_push(p2, x);
        ++x;
    }

    printf("\nTeste 2: ");

    if(compara(p1, p2)==1){

    	printf("Pilhas iguais.\n");
    }
    else{

    	printf("Pilhas diferentes.\n");
    }

    p_libera(p1);
    p_libera(p2);

    return 0;
}