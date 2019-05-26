#include<stdio.h>

#define VERDADE 1
#define FALSO 0

int verificarGanhador(char simbolo);
int veriricarEmpate();
void imprimirTabuleiro();
void realizarJogada(int jogador, char simbolo);

char tabuleiro[5][5]; // Matriz global para exibir a situação do jogo

int main(){

	int gameOver=FALSO, ganhador=0; // Variáveis para controlar o fluxo do jogo
	int i, j;

	// Inicializa tabuleiro:
	tabuleiro[0][1] = tabuleiro[0][3] = '|';
	tabuleiro[1][0] = tabuleiro[1][2] = '_'; tabuleiro[1][4] = '_';
	tabuleiro[2][1] = tabuleiro[2][3] = '|';
	tabuleiro[3][0] = tabuleiro[3][2] = '_'; tabuleiro[3][4] = '_';
	tabuleiro[4][1] = tabuleiro[4][3] = '|';
	tabuleiro[1][1] = tabuleiro[1][3] = tabuleiro[3][1] = tabuleiro[3][3] = '.';

	tabuleiro[0][0] = tabuleiro[0][2] = tabuleiro[0][4] = ' ';
	tabuleiro[2][0] = tabuleiro[2][2] = tabuleiro[2][4] = ' ';
	tabuleiro[4][0] = tabuleiro[4][2] = tabuleiro[4][4] = ' ';

	// Imprime tabuleiro:
	printf("    JOGO DA VELHA\n\n");
	imprimirTabuleiro(tabuleiro);

	// Inicia o jogo:
	do{

		// Jogador 1:
		if(gameOver==FALSO){

           	realizarJogada(1, 'X');

            printf("\n");

            imprimirTabuleiro(); // Imprime situação do tabuleiro

			if(verificarGanhador('X')==VERDADE){ // Verifica se o jogador 1 ganhou

				ganhador = 1;
				gameOver = 1;
			}
			else
			if(verificarEmpate()==VERDADE){ // Verifica se a partida empatou

				ganhador=0;
				gameOver=VERDADE;
			}
		}

        // Jogador 2:
		if(gameOver==FALSO){

            realizarJogada(2, 'O');

            printf("\n");

            // Imprime situação do tabuleiro:
            imprimirTabuleiro();

			if(verificarGanhador('O')==VERDADE){ // Verifica se o jogador 2 ganhou:

				ganhador = 2;
				gameOver = VERDADE;
			}
			else
			if(verificarEmpate()==VERDADE){ // Verifica se a partida empatou

				ganhador=0;
				gameOver=VERDADE;
			}
		}
		
	}while(gameOver==FALSO);

	// Imprime resultado final:
	if(ganhador==1) {

		printf("\nO ganhador e o Jogador 1!\n");
	}
	else
	if(ganhador==2){

		printf("\nO ganhador e o Jogador 2!\n");
	}
	else {

		printf("\nA partida terminou empatada!\n");
	}

	return 0;
}

void imprimirTabuleiro(){

    int i, j;

	for(i=0; i<5; i++){

		printf("\t");

		for(j=0; j<5; j++){

			printf("%c", tabuleiro[i][j]);
		}

		printf("\n");
	}
}

int verificarGanhador(char simbolo){

	int contLinha=0, contColuna=0;
	int contDiagonalPrincipal=0, contDiagonalSecundaria=0;
	int i, j;

	for(i=0; i<5; i++){

		contLinha = 0;
		contColuna = 0;

		for(j=0; j<5; j++){

			if(tabuleiro[i][j]==simbolo) {

				++contLinha;
			}

			if(tabuleiro[j][i]==simbolo) {

				++contColuna;
			}

			if((i==j)) {

				if(tabuleiro[i][j]==simbolo) {

					++contDiagonalPrincipal;
				}
			}

			if((i+j==4)) {

				if(tabuleiro[i][j]==simbolo) {

					++contDiagonalSecundaria;
				}
			}
		}

		if(contLinha==3 || contColuna==3 || contDiagonalPrincipal==3 || contDiagonalSecundaria==3) {

			return 1;
		}
	}

	return 0;
}

int verificarEmpate(){

    int totalJogadas=0;
    int i, j;

	for(i=0; i<5; i++) {

		for(j=0; j<5; j++) {

			if(tabuleiro[i][j]!=' ') {

				++totalJogadas;
			}
		}
	}

	if(totalJogadas==25){

		return 1;
	}
	else{

		return 0;
	}
}

void realizarJogada(int jogador, char simbolo){

    // Variáveis referentes às jogadas:
	int linha=0, coluna=0, linhaJogada=0, colunaJogada=0, jogadaValida=FALSO;

    do{

        printf("\nJOGADOR %d (%c)\n", jogador, simbolo);
        printf("Digite a posicao (linha/coluna): ");
        scanf("%d %d", &linhaJogada, &colunaJogada);
        
        // Fazendo a conversão dos valores digitados para analisar a posição na matriz:
        if(linhaJogada==1 && colunaJogada==1) {

            linha=0; coluna=0;
        }
        else
        if(linhaJogada==1 && colunaJogada==2) {

            linha=0; coluna=2;
        }
        else
        if(linhaJogada==1 && colunaJogada==3) {

            linha=0; coluna=4;
        }
        else
        if(linhaJogada==2 && colunaJogada==1) {

            linha=2; coluna=0;
        }
        else
        if(linhaJogada==2 && colunaJogada==2) {

            linha=2; coluna=2;
        }
        else
        if(linhaJogada==2 && colunaJogada==3) {

            linha=2; coluna=4;
        }
        else
        if(linhaJogada==3 && colunaJogada==1) {

            linha=4; coluna=0;
        }
        else
        if(linhaJogada==3 && colunaJogada==2) {

            linha=4; coluna=2;
        }
        else
        if(linhaJogada==3 && colunaJogada==3) {

            linha=4; coluna=4;
        }

        // Verificando se a jogada é válida:
        if(tabuleiro[linha][coluna]!=' ' || linhaJogada<1 || linhaJogada>3 || colunaJogada<1 || colunaJogada>3) {

            printf("\nJogada invalida!\n");

            jogadaValida=FALSO;
        }
        else {

            tabuleiro[linha][coluna] = simbolo;

            jogadaValida=VERDADE;
        }

    }while(jogadaValida==FALSO);
}
