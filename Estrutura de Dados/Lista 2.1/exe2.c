#include <stdio.h>

int multiplica(int k, int n);

int main(){
	
	int k=2, n=10;

	printf("%d^%d = %d", k, n, multiplica(k, n));

	printf("\n");

	return 0;
}

int multiplica(int k, int n){

	if(n==0){

		return 1;
	}

	return k * multiplica(k, n-1);
}
