#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include"Pilha.h"

int main(){

    Pilha* p = p_cria();
    float* v;
    int qtd, i;

    p_push(p, 5);
    p_push(p, 19);
    p_push(p, -4);
    p_push(p, 10);
    p_push(p, 0);

    printf("Quantidade de numeros a serem desempilhados: ");
    scanf("%d", &qtd);

    if(qtd>contaElementos(p)){

        printf("A quantidade digitada excede o tamanho da pilha.\n");
        return 0;
    }

    v = (float*)malloc(sizeof(float)*qtd);

    v = retornaValores(p, v, qtd);

    printf("\nElementos desempilhados:\n");

    for(i=0; i<qtd; i++){

        printf("%.0f  ", v[i]);
    }

    printf("\n");

    p_libera(p);
    free(v);

    return 0;
}