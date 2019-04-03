// DESAFIO AUTORAL:

// Dado um cavalo em alguma posição X do tabuleiro de xadrez, após N movimentos quaisquer, 
// informar a cor da casa em que o cavalo estará posicionado.

#include<stdio.h>

int main(){
	
	int linha, l, c, mov;
	char coluna;

    // Entrada dos dados da posição atual do cavalo, por exemplo: a6
	
	printf("Digite a posicao atual do cavalo: ");
	scanf("%c%d", &coluna, &linha);
	
	l = linha;
	
	printf("Digite a quantidade de movimentos: ");
	scanf("%d", &mov);

    // Transformando o valores literais das colunas em valores numéricos para facilitar no descobrimento da cor da casa atual:
	
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

    // Verificando as propriedades do tabuleiro de xadrez, podemos observar que as casas pretas só ocorrem em duas situações:
    // I - Quando a linha é par e a coluna é par
    // II - Quando a linha é ímpar e a coluna ímpar
	
	if((l%2==1 && c%2==1) || (l%2==0 && c%2==0)){ // Se I e II acontecerem, temos que o cavalo estará numa casa preta
		
		if(mov%2==0){ // Se a quantidade de movimentos for par, permanecemos na mesma cor:
			
			printf("\nO cavalo estara numa casa preta.\n");
		}
		else{ // Caso contrário, se a quantidade de movimentos for ímpar, trocamos de cor:
			
			printf("\nO cavalo estara numa casa branca.\n");
		}	
	}
	else{ // Caso contrário, ele estará posicionado numa casa da cor branca

        if(mov%2==0){ // Se a quantidade de movimentos for par, permanecemos na mesma cor:

            printf("\nO cavalo estara numa casa branca.\n");
        }
        else{ // Caso contrário, se a quantidade de movimentos for ímpar, trocamos de cor:

            printf("\nO cavalo estara numa casa preta.\n");
        }
	}
}
