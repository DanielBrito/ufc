#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int n=1, i, j=0;
	int resultado[100];
	
	while(n!=0){
		
		printf("Numero de participantes: ");
		scanf("%d", &n);
		
		int* ingressos = (int*)malloc(sizeof(int)*n);
		
		printf("\n");
		
		for(i=0; i<n; i++){
			
			printf("Ingresso do %do da fila: ", i+1);
			scanf("%d", &ingressos[i]);
			
			if((i+1)==ingressos[i]){
				
				resultado[j++] = ingressos[i];
			}
		}
		
		printf("\n");
	}
	
	for(i=0; i<j; i++){
		
		printf("Teste %d\n", i+1);
		printf("%d\n", resultado[i]);
	}
	
	return 0;
}
