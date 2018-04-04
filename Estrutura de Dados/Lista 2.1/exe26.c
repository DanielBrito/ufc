#include <stdio.h>
#include <math.h>

int hiperFat(int n);

int main(){
	
	int num = 4;

	printf("Hiperfatorial de %d = %d", num, hiperFat(num));

	printf("\n");

	return 0;
}

int hiperFat(int n){

	if(n==0){

		return 1;
	}

	return (pow(n,n)) * (hiperFat(n-1));
}