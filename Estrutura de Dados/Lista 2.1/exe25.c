#include <stdio.h>

int fatorial(int n);
int superFat(int x);

int main(){
	
	int num = 4;

	printf("Superfatorial de %d = %d", num, superFat(num));

	printf("\n");

	return 0;
}

int fatorial(int n){

	if(n==0 || n==1){

		return 1;
	}

	return n * fatorial(n-1);
}

int superFat(int x){

	if(x==1){

		return 1;
	}

	int aux = fatorial(x);

	return aux * superFat(x-1);
}