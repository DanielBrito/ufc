#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int totalProdutosVendidos(int mat[4][4]);
char* produtoMaisVendido(int mat[4][4]);
int maiorComprador(int mat[4][4]);
int maiorCompradorShow(int mat[4][4]);

int main(){

	int tabela[4][4] = {{1101,0,2,5},{2293,2,0,1},{4121,0,4,1},{9245,8,2,3}};
	int i, j;
	
	printf("Usuario\t\tLivro\t\tFilme\t\tShow\n\n");
	
	for(i=0; i<4; i++){
		
		for(j=0; j<4; j++){
			
			if(j==0){
				
				printf("%d", tabela[i][j]);
			}
			else{
				
				printf("\t\t%d", tabela[i][j]);
			}
		}
		
		printf("\n");
	}
	
	printf("\n\n");
	
	printf("RELATORIO\n\n");
	
	printf("a) Total de produtos vendidos: %d\n", totalProdutosVendidos(tabela));
	printf("b) Produto mais vendido: %s\n", produtoMaisVendido(tabela));
	printf("c) Usuario que comprou mais produtos: %d\n", maiorComprador(tabela));
	printf("d) Usuario que comprou mais show: %d", maiorCompradorShow(tabela));
	
	printf("\n\n");
	
	return 0;
}

int totalProdutosVendidos(int mat[4][4]){
	
	int i, j, cont=0;
	
	for(i=0; i<4; i++){
		
		for(j=1; j<4; j++){
			
			cont += mat[i][j];
		}		
	}
	
	return cont;
}

char* produtoMaisVendido(int mat[4][4]){
	
	int maior = INT_MIN;
	int i, j, produto;
	
	for(i=0; i<4; i++){
		
		for(j=1; j<4; j++){
			
			if(mat[i][j]>maior){
				
				maior = mat[i][j];				
				produto = j;
			}
		}
	}
	
	if(produto==1){
		
		return "Livro";
	}
	
	if(produto==2){
		
		return "Filme";
	}
	
	if(produto==3){
		
		return "Show";
	}
}

int maiorComprador(int mat[4][4]){
	
	int soma=0, maior=INT_MIN;
	int i, j, comprador;
	
	for(i=0; i<4; i++){
		
		soma = 0;
		
		for(j=1; j<4; j++){
			
			soma += mat[i][j];
		}
		
		if(soma>maior){
			
			maior = soma;
			comprador = mat[i][0];
		}
	}
	
	return comprador;
}

int maiorCompradorShow(int mat[4][4]){
	
	int comprador, maior=INT_MIN;
	int i, j;
	
	for(i=0; i<4; i++){
		
		if(mat[i][3]>maior){
			
			maior = mat[i][3];
			comprador = mat[i][0];
		}
	}
	
	return comprador;
}
