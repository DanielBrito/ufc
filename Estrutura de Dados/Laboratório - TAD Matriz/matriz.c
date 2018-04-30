#include <stdlib.h>
#include <stdio.h>
#include "matriz.h"

struct matriz{

	int lin;
	int col;
	float* v;
};

void libera(Matriz* mat){

	free(mat->v);
	free(mat);
}

Matriz* cria(int m, int n){

	Matriz* mat = (Matriz*) malloc(sizeof(Matriz));

	if(mat == NULL) {

		printf("Memória insuficiente!\n");
		exit(1);
	}

	mat->lin = m;
	mat->col = n;
	mat->v = (float*) malloc(m*n*sizeof(float));

	return mat;
}

float acessa(Matriz* mat, int i, int j){

	int k;

	if(i<0 ||i>= mat->lin|| j<0 || j>= mat->col) {

		printf("Acesso inválido!\n");
		exit(1);
	}

	k = i*mat->col+ j;

	return mat->v[k];
}

int linhas(Matriz* mat) {

	return mat->lin;
}

void atribui(Matriz* mat, int i, int j, float v){

	int k;

	if(i<0 || i>=mat->lin || j<0 || j>=mat->col) {

		printf("Atribuição inválida!\n");
		printf("i = %d, j = %d\n", i,j);

		exit(1);
	}

	k = i*mat->col + j;
	mat->v[k] = v;
}

int colunas(Matriz* mat){

	return mat->col;
}

void imprime(Matriz* mat){

    int t,i;

    if((mat->lin < 0) || (mat->col <0)){

        printf("A matriz não está definida\n");
	    exit(1);
    }

    t = mat->lin * mat->col;

    for(i=0;i<t;i++){
      
        if(i%mat->col==0){

            printf("\n");
        }
    
        printf("%.2f ", mat->v[i]);
    }

    printf("\n");
}