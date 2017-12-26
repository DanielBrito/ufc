#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int i;
	float produto=1;
	
	printf("Produto dos numeros divisiveis por 3 e por 5 entre 356 e 450:\n");
	
	for(i=356; i<=450; i++){
		
		if(i%3==0 && i%5==0){
			
			produto *= i;
		}
	}
	
	printf("%.0f", produto);

	printf("\n\n");
	
	return 0;
}
