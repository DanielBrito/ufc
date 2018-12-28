#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int n=0, i, resultado=1;
	
	while(n<1 || n>100){
		
		printf("Digite o tamanho dos vetores: ");
		scanf("%d", &n);
		
		printf("\n");
	}
	
	int* vetX = (int*)malloc(sizeof(int)*n);
	int* vetY = (int*)malloc(sizeof(int)*n);
	
	for(i=0; i<n; i++){
		
		printf("vetX[%d] = ", i);
		scanf("%d", &vetX[i]);
	}
	
	printf("\n");
	
	for(i=0; i<n; i++){
		
		printf("vetY[%d] = ", i);
		scanf("%d", &vetY[i]);
	}
	
	for(i=0; i<n; i++){
		
		resultado += vetX[i]*vetY[i];
	}
	
	printf("\nResultado: %d\n", resultado);
}
