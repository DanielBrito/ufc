#include<stdio.h>

int main(){
	
	int P, Q, R; // Como existem 3 átomos, temos 2^3 possíveis combinações de valores possíveis, ou seja, 8 linhas
	
	printf("P  Q  R  (P && R)  (Q || R)  (P && R) || (Q || R)\n\n"); // Cabeçalho da tabela com as proposições lógicas
	
	// Verificando o valor lógico de cada uma das combinações possíveis:
	
	P=1; Q=1; R=1;
	printf("%d  %d  %d     %d         %d               %d\n", P, Q, R, P&&R, Q||R, (P&&Q)||(Q||R));
	
	P=1; Q=1; R=0;
	printf("%d  %d  %d     %d         %d               %d\n", P, Q, R, P&&R, Q||R, (P&&Q)||(Q||R));
	
	P=1; Q=0; R=1;
	printf("%d  %d  %d     %d         %d               %d\n", P, Q, R, P&&R, Q||R, (P&&Q)||(Q||R));
	
	P=1; Q=0; R=0;
	printf("%d  %d  %d     %d         %d               %d\n", P, Q, R, P&&R, Q||R, (P&&Q)||(Q||R));
	
	P=0; Q=1; R=1;
	printf("%d  %d  %d     %d         %d               %d\n", P, Q, R, P&&R, Q||R, (P&&Q)||(Q||R));
	
	P=0; Q=1; R=0;
	printf("%d  %d  %d     %d         %d               %d\n", P, Q, R, P&&R, Q||R, (P&&Q)||(Q||R));
	
	P=0; Q=0; R=1;
	printf("%d  %d  %d     %d         %d               %d\n", P, Q, R, P&&R, Q||R, (P&&Q)||(Q||R));
	
	P=0; Q=0; R=0;
	printf("%d  %d  %d     %d         %d               %d\n", P, Q, R, P&&R, Q||R, (P&&Q)||(Q||R));
	
	return 0;
}
