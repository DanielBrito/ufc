#include <stdlib.h>
#include "matrizOperacoes.h"


Matriz* oposta(Matriz *mat1){

	int i,j;

	Matriz* m = cria(linhas(mat1),colunas(mat1));

	for(i=0; i<linhas(mat1);i++){

		for(j=0; j<colunas(mat1); j++){

			atribui(m,i,j,(acessa(mat1,i,j)*(-1)));
		}
	}
	
	return m;
}


Matriz* transposta(Matriz *mat1){

    int i,j;

	Matriz* trans = cria(colunas(mat1),linhas(mat1));

		for(i=0; i< linhas(mat1);i++){

			for(j=0; j<colunas(mat1); j++){

				atribui(trans,j,i,acessa(mat1,i,j));
			}
		}
	
	return trans;	
}

Matriz* soma(Matriz *mat1, Matriz* mat2){

	int i,j;

	if(linhas(mat1) != linhas(mat2) || colunas(mat1) != colunas(mat2)){

		return NULL;
	}
		
	Matriz *m = cria(linhas(mat1),colunas(mat2));

	for(i=0; i<linhas(mat1); i++){

		for(j=0; j<colunas(mat2); j++){

			atribui(m,i,j,acessa(mat1,i,j)+acessa(mat2,i,j));
		}
	}
		
	return m;
}

Matriz* subtracao(Matriz *mat1, Matriz* mat2){

	int i,j;

	if(linhas(mat1) != linhas(mat2) || colunas(mat1) != colunas(mat2)){

		return NULL;
	}
		
	Matriz *m = cria(linhas(mat1),colunas(mat2));

	for(i=0; i<linhas(mat1); i++){

		for(j=0; j<colunas(mat2); j++){

			atribui(m,i,j,acessa(mat1,i,j)-acessa(mat2,i,j));
		}
	}
		
	return m;
}

Matriz* multiplica(Matriz *mat1, Matriz* mat2){

	Matriz *m = cria(linhas(mat1),colunas(mat2));
	int i,j,c;
	float somatorio = 0;
	
	if(colunas(mat1) == linhas(mat2)){
	
		for(i=0; i<linhas(mat1); i++){
		
			for(j=0; j< colunas(mat2); j++){
			
				for(c=0; c<colunas(mat1); c++){
				
					somatorio += acessa(mat1,i,c)*acessa(mat2,c,j);
				}

				atribui(m,i,j,somatorio);
				somatorio = 0;
			}
			
		}
		
		return m;
	}

	return NULL;
}

int iguais(Matriz *mat1, Matriz* mat2){

	int i,j;

	if(linhas(mat1) != linhas(mat2) || colunas(mat1) != colunas(mat2)){

		return 0;
	}

	for(i=0; i<linhas(mat1); i++){

		for(j=0; j<colunas(mat1);j++){

			if(acessa(mat1,i,j) != acessa(mat2,i,j)){

				return 0;
			}
		}
	}

	return 1;
}
