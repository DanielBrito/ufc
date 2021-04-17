#include<stdio.h>

// O grande insight desse exercício é pegar o resto da divisão por 10 e somar com 10 vezes a soma anterior.

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
