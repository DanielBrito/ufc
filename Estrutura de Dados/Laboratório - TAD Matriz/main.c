#include <stdio.h>
#include <stdlib.h>
#include "matrizOperacoes.h"

int main(){

	int i,j;
	Matriz *mat1, *mat2, *op,*so,*su,*mu,*tr;
	int n, m, valor;

	printf("Entre com os valores N e M: ");
	scanf("%d", &n);
	scanf("%d", &m);
	
	printf("\n");

	mat1 = cria(n,m);
	mat2 = cria(m,n);
	
	printf("Populando matriz 1:\n");
	
	for(i=0;i<n;i++){
	
	    for(j=0;j<m;j++){
	    
	      printf("Posicao [%d][%d]: ", i, j);
	      scanf("%d", &valor);
	      
	      atribui(mat1,i,j,valor);
	    }
	}
	
	printf("\n");
	
	printf("Populando matriz 2:\n");
	
	for(i=0;i<n;i++){
	
	    for(j=0;j<m;j++){
	    
	      printf("Posicao [%d][%d]: ", i, j);
	      scanf("%d", &valor);
	      
	      atribui(mat2,i,j,valor);
	    }
	}
	
	printf("\n");
	
	printf("Matriz 01");
	imprime(mat1);
	
	printf("\n");
	
	printf("Matriz 02");
	imprime(mat2);
	
	iguais(mat1,mat2) ? printf("\nAs matrizes são iguais \n") : printf("\nAs matrizes são diferentes \n");
	printf("\n");
	
	printf("Oposta");
	op = oposta(mat1);
	imprime(op);

	printf("\nTransposta");
	tr = transposta(mat1);
	imprime(tr);
	
	printf("\nSoma");
	so = soma(mat1,mat2);
	imprime(so);
		
	printf("\n");

	printf("\nSubtração");
	su = subtracao(mat1,mat2);
	imprime(su);
		
	printf("\n");

	printf("\nMultiplicação");
	mu = multiplica(mat1,mat2);
	imprime(mu);
		
	printf("\n");
	
	if(op!=NULL)
		libera(op); 
		
	if(so!=NULL)
		libera(so); 
		
	if(su!=NULL)
		libera(su); 
		
	if(mu!=NULL)
		libera(mu); 
		
	if(mat1!=NULL)
 		libera(mat1); 
 		
 	if(mat2!=NULL)
 		libera(mat2); 
 		
 	if(tr!=NULL)
 		libera(tr); 
 	
	return 0;
}