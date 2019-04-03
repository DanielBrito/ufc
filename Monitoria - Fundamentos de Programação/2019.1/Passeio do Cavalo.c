// DESAFIO AUTORAL:
// Dado um cavalo em alguma posição X do tabuleiro de xadrez, após N movimentos quaisquer, 
// informar a cor da casa em que o cavalo estará posicionado.

#include<stdio.h>

int main(){
	
	int linha, l, c, mov;
	char coluna;
	
	printf("Digite a posicao atual do cavalo: ");
	scanf("%c%d", &coluna, &linha);
	
	l = linha;
	
	printf("Digite a quantidade de movimentos: ");
	scanf("%d", &mov);
	
	switch(coluna){
		
		case 'a': c = 1; break;
		case 'b': c = 2; break;
		case 'c': c = 3; break;
		case 'd': c = 4; break;
		case 'e': c = 5; break;
		case 'f': c = 6; break;
		case 'g': c = 7; break;
		case 'h': c = 8; break;
	}
	
	if((l%2==1 && c%2==1) || (l%2==0 && c%2==0)){
		
		if(mov%2==0){
			
			printf("\nO cavalo estara numa casa preta.\n");
		}
		else{
			
			printf("\nO cavalo estara numa casa branca.\n");
		}	
	}
	else{
		
		printf("\nO cavalo estara numa casa branca.\n");
	}
}
