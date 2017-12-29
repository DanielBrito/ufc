#include<stdio.h>
#include<string.h>
#include<limits.h>

/* void funcao(int vetor[][100]); == void funcao(int vetor[100][100]); */

void mostraSegundaLinha(int mat[4][4]); 
void mostraTerceiracoluna(int mat[4][4]);
void somaQuartaLinha(int mat[4][4]);
void produtoPrimeiraColuna(int mat[4][4]);
int maiorSegundaColuna(int mat[4][4]);
int menorPrimeiraLinha(int mat[4][4]);
int maiorElementoMatriz(int mat[4][4]);
int menorElementoMatriz(int mat[4][4]);
int valorMedioElementos(int mat[4][4]);

int main(){
	
	int matriz[4][4]={{4,6,8,12},{1,9,4,3},{8,6,11,13},{3,7,5,2}};
	int i, j;
	
	printf("     MATRIZ\n\n");
	
	for(i=0; i<4; i++){
		
		for(j=0; j<4; j++){
			
			printf("%2d   ", matriz[i][j]);
		}
		
		printf("\n");
	}
	
	printf("\n\n     RELATORIO\n\n");
	
	printf("a) Mostra os elementos da segunda linha da matriz\n");
	mostraSegundaLinha(matriz);
	printf("\n\n");
	
	printf("b) Mostra os elementos da terceira coluna da matriz\n");
	mostraTerceiracoluna(matriz);
	printf("\n");
	
	printf("c) Calcula e mostra a soma dos elementos da quarta linha da matriz\n");
	somaQuartaLinha(matriz);
	printf("\n\n");
	
	printf("d) Calcula e mostra o produto dos elementos da primeira coluna\n");
	produtoPrimeiraColuna(matriz);
	printf("\n\n");
	
	printf("e) Retorna o maior elemento da segunda coluna\n");
	int maiorSegCol = maiorSegundaColuna(matriz);
	printf("%d\n\n", maiorSegCol);
	
	printf("f) Retorna o menor elemento da primeira linha\n");
	int menorPriLin = menorPrimeiraLinha(matriz);
	printf("%d\n\n", menorPriLin);
	
	printf("g) Retorna o maior elemento da matriz\n");
	int maiorElemMat = maiorElementoMatriz(matriz);
	printf("%d\n\n", maiorElemMat);
	
	printf("h) Retorna o menor elemento da matriz\n");
	int menorElemMat = menorElementoMatriz(matriz);
	printf("%d\n\n", menorElemMat);
	
	printf("i) Retorna o valor medio dos elementos da matriz\n");
	float valorMedio = valorMedioElementos(matriz);
	printf("%.2f", valorMedio);
	
	printf("\n\n");
	
	return 0;
}

void mostraSegundaLinha(int mat[4][4]){
	
	int i=1, j;
		
	for(j=0; j<4; j++){
		
		printf("%d ", mat[i][j]);
	}
}

void mostraTerceiracoluna(int mat[4][4]){
	
	int i, j=2;
	
	for(i=0; i<4; i++){
		
		printf("%d\n", mat[i][j]);
	}
}

void somaQuartaLinha(int mat[4][4]){
	
	int i=3, j, soma=0;
	
	for(j=0; j<4; j++){
		
		soma += mat[i][j];
	}
	
	printf("%d", soma);
}

void produtoPrimeiraColuna(int mat[4][4]){
	
	int j=0, i, produto=1;
	
	for(i=0; i<4; i++){
		
		produto *= mat[i][j];
	}
	
	printf("%d", produto);	
}

int maiorSegundaColuna(int mat[4][4]){
	
	int j=1, i, maior=INT_MIN;
	
	for(i=0; i<4; i++){
		
		if(mat[i][j]>maior){
			
			maior = mat[i][j];
		}
	}
	
	return maior;
}

int menorPrimeiraLinha(int mat[4][4]){
	
	int j, i=0, menor=INT_MAX;
	
	for(j=0; j<4; j++){
		
		if(mat[i][j]<menor){
			
			menor = mat[i][j];
		}
	}
	
	return menor;
}

int maiorElementoMatriz(int mat[4][4]){
	
	int i, j, maior=INT_MIN;
	
	for(i=0; i<4; i++){
		
		for(j=0; j<4; j++){
			
			if(mat[i][j]>maior){
				
				maior = mat[i][j];
			}
		}
	}
	
	return maior;
}

int menorElementoMatriz(int mat[4][4]){
	
	int i, j, menor=INT_MAX;
	
	for(i=0; i<4; i++){
		
		for(j=0; j<4; j++){
			
			if(mat[i][j]<menor){
				
				menor = mat[i][j];
			}
		}
	}
	
	return menor;
}

int valorMedioElementos(int mat[4][4]){
	
	int i, j, soma=0;
	float media=0;
	
	for(i=0; i<4; i++){
		
		for(j=0; j<4; j++){
			
			soma += mat[i][j];
		}
	}
	
	media = soma/(4*4);
	
	return media;
}
