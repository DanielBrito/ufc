#include <stdio.h>

int fatDuplo(int n);

int main(){
	
	int n = 9;

	printf("Fatorial duplo de %d = %d", n, fatDuplo(n));

	printf("\n");

	return 0;
}

int fatDuplo(int n){

	if(n==1 || n==0){

		return 1;
	}
	
	if((n%2)==1){

		return n * fatDuplo(n-2);
	}
}