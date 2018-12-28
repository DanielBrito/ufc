#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int n, m, i, j, soma=0, max=0;
	
	printf("Linhas x Colunas: ");
	scanf("%d %d", &n, &m);
	
	printf("\n");
	
	int** campo = (int**)malloc(sizeof(int**)*n);
	
	for(i=0; i<n; i++){
		
		campo[i] = (int*)malloc(sizeof(int)*m);
	}
	
	for(i=0; i<n; i++){
		
		for(j=0; j<m; j++){
			
			printf("Celula[%d][%d]: ", i, j);
			scanf("%d", &campo[i][j]);
		}
	}
	
	for(i=0; i<n; i++){
		
		for(j=0; j<m; j++){
			
			soma += campo[i][j];
		}
		
		if(soma>max){
			
			max = soma;
		}
		
		soma = 0;
	}
	
	for(i=0; i<m; i++){
		
		for(j=0; j<n; j++){
			
			soma += campo[j][i];
		}
		
		if(soma>max){
			
			max = soma;
		}
		
		soma = 0;
	}
	
	printf("\nResultado: %d\n", max);
	
	return 0;
}
