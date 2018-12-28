#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int n=0, i, j;
	int max=0, coletadas=0;
	
	while(n<2 || n>100){
		
		printf("Dimensao do tabuleiro: ");
		scanf("%d", &n);
	}
	
	char** tabuleiro = (char**)malloc(sizeof(char*)*n);
	
	for(i=0; i<n; i++){
		
		tabuleiro[i] = (char*)malloc(sizeof(char)*n);
	}
	
	printf("\n");
	
	for(i=0; i<n; i++){
		
		for(j=0; j<n; j++){
			
			printf("Tabuleiro[%d][%d]: ", i, j);
			scanf(" %c", &tabuleiro[i][j]);
		}
	}
	
	for(i=0; i<n; i++){
		
		if(i%2==0){
			
			for(j=0; j<n; j++){
				
				if(tabuleiro[i][j]=='o'){
					
					++coletadas;
				}
				else{
					
					if(tabuleiro[i][j]=='A'){
						
						if(coletadas>max){
							
							max = coletadas;
						}
						
						coletadas = 0;
					}
				}
			}
		}
		else{
			
			for(j=n-1; j>=0; j--){
				
				if(tabuleiro[i][j]=='o'){
					
					++coletadas;
				}
				else{
					
					if(tabuleiro[i][j]=='A'){
						
						if(coletadas>max){
							
							max = coletadas;
						}
						
						coletadas = 0;
					}
				}
			}
		}
	}
	
	coletadas>max ? printf("\nResultado: %d\n", coletadas) : printf("\nResultado: %d\n", max);
	
	return 0;
}
