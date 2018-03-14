#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*Exemplo:
3  4 8
10 5 0
2  6 7 
é um quadrado mágico
*/

int quadradoMagico(int ** mat, int n){

	int i, j;
	int somaPadrao=0;
	int somaLinha=0, somaColuna=0, somaDiagonal=0;

	for(i=0; i<n; i++){

		somaPadrao += mat[0][i];
	}

	// Verificar linhas:

	for(i=1; i<n; i++){

		somaLinha = 0;

		for(j=0; j<n; j++){

			somaLinha += mat[i][j];
		}

		if(somaLinha!=somaPadrao){

			return 0;
		}
	}

	// Verificar colunas:

	for(i=0; i<n; i++){

		somaColuna=0;

		for(j=0; j<n; j++){

			somaColuna += mat[j][i];
		}

		if(somaColuna!=somaPadrao){

			return 0;
		}
	}

	// Verificar diagonal principal:

	for(i=0; i<n; i++){

		for(j=0; j<n; j++){

			if(i==j){

				somaDiagonal += mat[i][j];
			}
		}
	}

	if(somaDiagonal!=somaPadrao){

		return 0;
	}

	// Verificar diagonal secundária:

	somaDiagonal = 0;

	for(i=0; i<n; i++){

		for(j=0; j<n; j++){

			if((i+j)==(n-1)){

				somaDiagonal += mat[i][j];
			}
		}
	}

	if(somaDiagonal!=somaPadrao){

		return 0;
	}

	return 1;
}


int main(){

	int n,i,j;
	int **mat;

	printf("Entre com a dimensão da matriz quadrada\n");
	scanf("%d", &n);

	mat = (int**)malloc(sizeof(int*)*n);

	for (i = 0; i < n; ++i){

		mat[i] = (int*)malloc(sizeof(int)*n);
	}

	printf("Entre com os dados da matriz\n");

	for (i = 0; i < n; ++i){

		for (j = 0; j < n; ++j){

			scanf("%d", &mat[i][j]);
		}
	}

	for (i = 0; i < n; ++i){

		for (j = 0; j < n; ++j){

			printf("%2d  ", mat[i][j]);
		}

		printf("\n");
	}
	
	if(quadradoMagico(mat,n)){

		printf("É um quadrado mágico\n");
	}
	else{

		printf("Não é um quadrado mágico\n");
	}

	for (i = 0; i < n; ++i){

		free(mat[i]);
	}

	free(mat);

	return 0;
}