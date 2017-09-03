#include<stdio.h>
#include<stdlib.h> // Contém a função malloc

float** matrizTransposta(int linha, int coluna, float** mat);

int main(){
	
	int i, j;
	float** matriz;
	int linha=0, coluna=0;
	float** transposta;
	
	printf("Digite as dimensoes da matriz [LINHA]x[COLUNA]: ");
	scanf("%d%d", &linha, &coluna);
	
	matriz = (float**)malloc(linha*sizeof(float*));
	
	for(i=0; i<linha; i++){
		
		matriz[i] = (float*)malloc(coluna*sizeof(float));
	}
	
	printf("\n");	
	
	for(i=0; i<linha; i++){
		
		for(j=0; j<coluna; j++){
			
			printf("Digite o elemento [%d][%d]: ", i, j);
			scanf("%f", &matriz[i][j]);
		}
	}
	
	printf("\n");
	
	printf("MATRIZ DIGITADA\n");
	
	for(i=0; i<linha; i++){
		
		for(j=0; j<coluna; j++){
			
			printf("%.0f ", matriz[i][j]);
		}
		
		printf("\n");
	}
	
	transposta = matrizTransposta(linha, coluna, matriz);
	
	printf("\n\n");
	
	printf("MATRIZ TRANSPOSTA\n");
	
	for(i=0; i<coluna; i++){
		
		for(j=0; j<linha; j++){
			
			printf("%.0f ", transposta[i][j]);
		}
		
		printf("\n");
	}
	
	printf("\n\n");
	
	
	// Liberação do espaço de memória
	
	for(i=0; i<linha; i++)
		
		free(matriz[i]);
		
	free(matriz);
	
	for(i=0; i<linha; i++)
		
		free(transposta[i]);
		
	free(transposta);
	
	return 0;
}


float** matrizTransposta(int ln, int col, float** mat){
	
	int i, j;
	float** transposta;
	
	transposta = (float**)malloc(ln*sizeof(float*));
	
	for(i=0; i<ln; i++){
		
		transposta[i] = (float*)malloc(col*sizeof(float));
	}
	
	for(i=0; i<ln; i++){
		
		for(j=0; j<col; j++){
			
			transposta[j][i] = mat[i][j];
		}
	}
	
	return transposta;
}
