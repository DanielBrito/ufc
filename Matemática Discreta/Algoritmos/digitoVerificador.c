#include<stdio.h>
#include<stdlib.h>

#define TAM 13

/*
	Dada uma sequencia valida de digitos do codigo de barras (EAN-13),
	o seguinte algoritmo gera o digito verificador, um mecanismo de
	controle e seguranca utilizada nesta tecnologia.
*/

int main(){

    int vetorY[TAM] = {1,3,1,3,1,3,1,3,1,3,1,3,1}; // Vetor de pesos
    int vetorA[TAM];
    int i, resultado=0, digito=0;

     //Entrada de valores:

    for(i=0; i<TAM-1; i++){

        scanf("%d", &vetorA[i]);
    }

    for(i=0; i<TAM-1; i++){

        if(i%2==0){

            resultado += vetorA[i]*vetorY[i];
        }
        else{

            resultado += vetorA[i]*vetorY[i];
        }
    }

    int proxDivisivel = resultado;

    while((proxDivisivel%10)!=0){

        ++proxDivisivel;
    }

    digito = proxDivisivel-resultado;

    vetorA[12] = digito;

    printf("\n");

    printf("CODIGO DE BARRAS:\n");

    for(i=0; i<TAM; i++){

        printf("%d", vetorA[i]);
    }

    printf("\n\n");

    return 0;
}
