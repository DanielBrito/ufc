/* Análogo ao Tabela Verdade.c, porém, utilizando laço de repetição */

#include<stdio.h>

int main(){
	
	int P, Q, R; // Como existem 3 átomos, temos 2^3 possíveis combinações de valores possíveis, ou seja, 8 linhas
	
	printf("P  Q  R  (P && R)  (Q || R)  (P && R) || (Q || R)\n\n"); // Cabeçalho da tabela com as proposições lógicas

    // Laço de repetição para verificar o valor lógico de cada uma das combinações possíveis:
	
	for(P=0; P<=1; P++){
		
		for(Q=0; Q<=1; Q++){
			
			for(R=0; R<=1; R++){
				
				printf("%d  %d  %d     %d         %d               %d\n", P, Q, R, P&&R, Q||R, (P&&Q)||(Q||R));
			}
		}
	}
	
	return 0;
}
