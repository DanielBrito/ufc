#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int maiorValor(int (*mat)[4][3]);
void atualizaMatriz(int (*mat)[4][3]);
void mediaQuartaLinha(int mat[4][3]);

int main(){
	
	int matriz[4][3] = {{8,4,12},{9,10,7},{6,1,3},{11,5,2}};
	int i, j;
	
	printf("MATRIZ ORIGINAL\n\n");
	
	for(i=0; i<4; i++){
		
		for(j=0; j<3; j++){
			
			printf("%4d  ", matriz[i][j]);
		}
		
		printf("\n");
	}
	
	printf("\n\nMaior valor: %d\n\n\n", maiorValor(&matriz));
	
	atualizaMatriz(&matriz);
	
	printf("MATRIZ ATUALIZADA\n\n");
	
	for(i=0; i<4; i++){
		
		for(j=0; j<3; j++){
			
			printf("%4d  ", matriz[i][j]);
		}
		
		printf("\n");
	}
	
	printf("\n\nMedia aritmetica da quarta linha: ");
	
	mediaQuartaLinha(matriz);
	
	printf("\n\n");
	
	return 0;
}


int maiorValor(int (*mat)[4][3]){
	
	int i, j, maior=INT_MIN;
	
	for(i=0; i<4; i++){
		
		for(j=0; j<3; j++){
			
			if((*mat)[i][j]>maior){
				
				maior = (*mat)[i][j];
			}
		}
	}
	
	return maior;
}


void atualizaMatriz(int (*mat)[4][3]){
	
	int maior = maiorValor(mat);
	int i, j;
	
	for(i=0; i<4; i++){
		
		for(j=0; j<3; j++){
			
			(*mat)[i][j] *= maior;
		}
	}
}


void mediaQuartaLinha(int mat[4][3]){
	
	int i, soma=0;
	
	for(i=0; i<3; i++){
		
		soma += mat[3][i];
	}
	
	printf("%.2f", (float)soma/3);
}
