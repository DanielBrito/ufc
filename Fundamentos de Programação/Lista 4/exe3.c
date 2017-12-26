#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int i;
	
	printf("Numeros pares de 200 a 250:\n");
	
	for(i=200; i<=250; i++){
		
		if(i%2==0){
			
			printf("%d\n", i);
		}
	}

	printf("\n\n");
	
	return 0;
}
