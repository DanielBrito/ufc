#include<stdio.h>

float potencia(float a, int b);

int main(){

	int i, j;

	for(i=2; i<=10; i++){

		for(j=0; j<=10; j++){

			printf("%.2f ", potencia(i, j));
		}

		printf("\n");
	}

	printf("\n\n");

	return 0;
	
}


float potencia(float b, int e){

	int i;
	float resultado;

	resultado = b;

	if(e==0){

		return 1;
	}
	else{

		for(i=0; i<e-1; i++){

			resultado *= b;
		}
	}

	return resultado;
}