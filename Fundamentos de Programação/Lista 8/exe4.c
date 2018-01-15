#include<stdio.h>
#include<stdlib.h>

void verificaDivisiveis(int matriz[5][5]);

int main(){
	
	int matriz[5][5];
	int i, j;
	
	for(i=0; i<5; i++){
		
		for(j=0; j<5; j++){
			
			matriz[i][j] = i+j;
		}
	}
	
	for(i=0; i<5; i++){
		
		for(j=0; j<5; j++){
			
			printf("%2d ", matriz[i][j]);
		}
		
		printf("\n");
	}
	
	printf("\n");
	
	printf("Numeros divisiveis por 2 e por 3:\n");
	
	verificaDivisiveis(matriz);
	
	printf("\n\n");
	
	return 0;
}


void verificaDivisiveis(int matriz[5][5]){
	
	int i, j;
	
	for(i=0; i<5; i++){
		
		for(j=0; j<5; j++){
			
			if(matriz[i][j]%2==0 && matriz[i][j]%3==0){
				
				printf("%2d ");
			}
		}
	}
}
