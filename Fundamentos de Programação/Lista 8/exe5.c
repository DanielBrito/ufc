#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int num, i;
	int vetorNum[6];
	int quociente, divisor=100000;
	
	printf("Digite um inteiro de 6 digitos: ");
	scanf("%d", &num);
	
	printf("\n");
	
	for(i=0; i<6; i++){
		
		quociente = num/divisor;
		vetorNum[i] = quociente;
		
		num %= divisor;
		divisor /= 10;
	}
	
	printf("Vetor: ");

	for(i=0; i<6; i++){
		
		printf("[%d] ", vetorNum[i]);
	}

	printf("\n\n");
	
	return 0;
}
