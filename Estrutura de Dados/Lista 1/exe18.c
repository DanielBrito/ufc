#include<stdio.h>
#include<stdlib.h>

int** permutaLinhas(int** mat, int** matPermutada, int tam, int x, int y);

int main(){
	
	int i, j, tamanho, lnX, lnY;
	int** matriz;
	int** matrizPermutada;
	
	do{
		
		system("cls");
		
		printf("Digite o tamanho da matriz [N]x[N]: ");
		scanf("%d", &tamanho);
		
	}while(tamanho>30);
	
	printf("\n");
	
	// Alocação de memória para "matriz":
	
	matriz = (int**)malloc(tamanho*sizeof(int*));
	
	for(i=0; i<tamanho; i++){
		
		matriz[i] = (int*)malloc(tamanho*sizeof(int));
	}
	
  	// Alocação de memória para "matrizPermutada":
   
   	matrizPermutada = (int**)malloc(tamanho*sizeof(int*));
	
	for(i=0; i<tamanho; i++){
		
		matrizPermutada[i] = (int*)malloc(tamanho*sizeof(int));
	}	
	
	for(i=0; i<tamanho; i++){
		
		for(j=0; j<tamanho; j++){
			
			printf("Valor da posicao [%d][%d]: ", i, j);
			scanf("%d", &matriz[i][j]);
		}
	}
	
	printf("\n");
	
	printf("Digite as linhas que serao permutadas: ");
	scanf("%d %d", &lnX, &lnY);
	
	printf("\n");
	
	printf("MATRIZ DIGITADA\n");
	
	for(i=0; i<tamanho; i++){
		
		for(j=0; j<tamanho; j++){
			
			printf("%d ", matriz[i][j]);
		}
		
		printf("\n");
	}
	
	printf("\n");
	
	printf("MATRIZ PERMUTADA\n");
	
	permutaLinhas(matriz, matrizPermutada, tamanho, lnX, lnY);
	
	for(i=0; i<tamanho; i++){
		
		for(j=0; j<tamanho; j++){
			
			printf("%d ", matrizPermutada[i][j]);
		}
		
		printf("\n");
	}
	
	// Liberando espaço de memória
	
	for(i=0; i<tamanho; i++)
		
		free(matriz[i]);
		
	free(matriz);
	
	
	for(i=0; i<tamanho; i++)
		
		free(matrizPermutada[i]);
		
	free(matrizPermutada);
		
	
	printf("\n\n");
	
	return 0;
}


int** permutaLinhas(int** mat, int** matPermutada, int tam, int x, int y){
	
	int i, j;

	for(i=0; i<tam; i++){
		
		for(j=0; j<tam; j++){
			
			if(i==x){
				
				matPermutada[i][j] = mat[y][j];
			}
			else
			if(i==y){
				
				matPermutada[i][j] = mat[x][j];
			}
			else{
				
				matPermutada[i][j] = mat[i][j];
			}
		}
	}
}
