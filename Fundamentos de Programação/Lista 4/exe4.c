#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int i, soma=0;
	
	printf("Soma dos numeros impares entre 2100 e 2158:\n");
	
	for(i=2101; i<2158; i++){
		
		if(i%2==1){
			
			soma += i;
		}
	}
	
	printf("%d", soma);

	printf("\n\n");
	
	return 0;
}
