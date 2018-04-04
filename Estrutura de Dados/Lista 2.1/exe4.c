#include <stdio.h>

int testaPrimos(int n);
void primos(int n);

int main(){

	int num;

	printf("Digite um número: ");
	scanf("%d", &num);

	printf("\n");

	primos(num);	

	printf("\n");

	return 0;

}

int testaPrimos(int n){

	int i, cont=0;

	if(n<1){

		return 0;
	}

	for(i=1; i<=n; i++){

		if(n%i==0){

			++cont;

			if(cont>2){

				return 0;
			}
		}
	}

	return 1;
}

void primos(int n){

	if(n<0){

		return;
	}

	if(testaPrimos(n)){

		printf("%d\n", n);
	}

	primos(n-1);
}