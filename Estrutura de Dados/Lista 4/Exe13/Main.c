#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include"Pilha.h"

int main(){

    int num, d, resto;
    Pilha* bin = p_cria();

    printf("Digite um numero: ");
    scanf("%d", &num);

    d = num;

    while(d!=0){

        resto = d%2;
        d = d/2;        
        p_push(bin, resto);
    }

    printf("\nNumero %d em binario: ", num);
    p_imprime(bin);

    p_libera(bin);

    return 0;
}