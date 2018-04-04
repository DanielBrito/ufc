#include <stdio.h>
#include <math.h>

int fatExp(int n);

int main(){
	
	int num = 3;

	printf("O fatorial exponencial de %d = %d", num, fatExp(num));

	printf("\n");

	return 0;
}

int fatExp(int n){

	if(n==1){

		return 1;
	}

	return pow(n, fatExp(n-1));
}