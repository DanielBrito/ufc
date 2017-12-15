#include<stdio.h>

int main(){
	
	int num, i, cont=0;
	
	printf("Digite um numero (n > 1): ");
	scanf("%d", &num);
	
	printf("\n");
	
	for(i=1; i<=num; i++){
		
		if((num%i)==0){
					
			cont++;
			
			// printf("Divisor = %d\n", i);
		}
		
		if(cont>2){
				
			printf("\nO numero nao e primo.\n\n");
				
			system("PAUSE");
			return 0;				
		}
	}
	
	printf("\nO numero e primo.\n\n");
	
	system("PAUSE");
	return 0;
}
