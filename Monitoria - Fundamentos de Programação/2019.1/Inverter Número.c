#include<stdio.h>

int main(){
	
	int num, aux, invertido=0;
	
	printf("Digite um numero: ");
	scanf("%d", &num);
	
	while(num>0){
		
		aux = num%10;
		invertido = invertido*10+aux;
		num /= 10;
	}
	
	printf("\nNumero invertido: %d\n", invertido);
	
	return 0;
}
