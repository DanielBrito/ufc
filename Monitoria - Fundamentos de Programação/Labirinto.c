#include<stdio.h>
#include<stdlib.h>
#include<conio.h> // Contém a função getch()

// Constante que delimita a dimensão de um labirinto quadrado (DIMENSAO x DIMENSAO)
#define DIMENSAO 20

// Renomeando as teclas de movimento para tornar o código mais legível
#define SUBIR 'w'
#define DESCER 's'
#define ESQUERDA 'a'
#define DIREITA 'd'

// Assinatura das funções auxiliares que serão utilizadas no fluxo básico do jogo
void inicializarLabirinto();
void imprimirLabirinto();
void movimentarJogador(char movimento);

// Variável global que será vista em todo o escopo do código, não sendo necessário manipular ponteiros
char labirinto[DIMENSAO][DIMENSAO];

// Variáveis para posicionar o jogador na matriz
int posicaoJogadorLinha, posicaoJogadorColuna;

int main(){
	
	// Chamada de função para definir os limites do labirinto
	inicializarLabirinto();

    // Define as coordenadas da posição inicial do jogador
    posicaoJogadorLinha=1;
    posicaoJogadorColuna=1;
	
	// Posiciona o jogador (asterisco) no labirinto
	labirinto[posicaoJogadorLinha][posicaoJogadorColuna]='*';
	
    // Variável para armazenar os movimentos (a = esquerda | s = descer | d = direita | w = subir)
	char movimento;

	do{ // Executar o corpo do laço...
		
		//system("clear"); // Limpar a tela no Linux
        system("cls"); // Limpar a tela no Windows
		
		imprimirLabirinto(); // Antes de cada jogada, exibir a situação atual do labirinto
		
        // Digitar o movimento a ser realizado e depois teclar ENTER:
        // printf("\nDigite o movimento: ");
		// scanf("%c", &movimento);
        
        // Lê um carectere do teclado, mas não mostra na tela:
		printf("\nDigite o movimento: ");
		movimento = getch(); 
		
		movimentarJogador(movimento); // Chamada de função passando o movimento recebido por parâmetro
		
	}while(movimento!='x'); // ... Enquanto 'x' não for pressionado
	
	printf("\nAte a proxima!\n\n");
	
	return 0; // Mensagem para o compilador de que o programa executou corretamente
}

// Função para delimitar os limites externos do labirinto
void inicializarLabirinto(){
	
	int i, j;
	
	for(i=0; i<DIMENSAO; i++){
		
		for(j=0; j<DIMENSAO; j++){
			
			if(i==0 || j==0 || i==DIMENSAO-1 || j==DIMENSAO-1){ // Índices (i, j) que definem os limites do labirinto, ou seja, suas bordas
				
				labirinto[i][j] = '#';
			}
            else{
                
                labirinto[i][j] = ' '; // Índices (i, j) que definem as posições internas do labirinto, ou seja, onde o jogador irá se movimentar
            }
		}
	}
}

// Função para imprimir a situção do labirinto
void imprimirLabirinto(){
	
	int i, j;
	
	for(i=0; i<DIMENSAO; i++){
        
        printf("\t"); // Tabulação para centralizar o labirinto na tela
		
		for(j=0; j<DIMENSAO; j++){
			
			printf("%c", labirinto[i][j]);
		}
		
		printf("\n");
	}
}

// Função para realizar o movimento do jogador no labirinto
void movimentarJogador(char movimento){

    // Se a tecla digitada não cair em nenhuma das condições abaixo o jogador não se movimentará
    // Se a tecla digitada realizar um movimento inválido ("entrar na parede") o jogador não se movimentará
	
	if(movimento==SUBIR){ // w
		
		if(posicaoJogadorLinha!=1){ // Pois na posição acima da linha 1 (ou seja, na linha 0) haverá uma parede
			
			labirinto[posicaoJogadorLinha][posicaoJogadorColuna]=' '; // Coloca um espaço vazio na posição atual
			labirinto[--posicaoJogadorLinha][posicaoJogadorColuna]='*'; // Move o jogador para a nova posição decrementando a linha
		}
	}
	
	if(movimento==DESCER){ // s
		
		if(posicaoJogadorLinha!=DIMENSAO-2){ // Pois na posição abaixo da linha DIMENSAO-2 (ou seja, na linha DIMENSAO-1) haverá uma parede
			
			labirinto[posicaoJogadorLinha][posicaoJogadorColuna]=' '; // Coloca um espaço vazio na posição atual
			labirinto[++posicaoJogadorLinha][posicaoJogadorColuna]='*'; // Move o jogador para a nova posição incrementando a linha
		}
	}
	
	if(movimento==ESQUERDA){ // a
		
		if(posicaoJogadorColuna!=1){ // Pois na posição à esquerda da coluna 1 (ou seja, na coluna 0) haverá uma parede
			
			labirinto[posicaoJogadorLinha][posicaoJogadorColuna]=' '; // Coloca um espaço vazio na posição atual
			labirinto[posicaoJogadorLinha][--posicaoJogadorColuna]='*'; // Move o jogador para a nova posição decrementando a coluna
		}
	}
	
	if(movimento==DIREITA){ // d
		
		if(posicaoJogadorColuna!=DIMENSAO-2){ // Pois na posição à direita da coluna DIMENSAO-2 (ou seja, na coluna DIMENSAO-1) haverá uma parede
			
			labirinto[posicaoJogadorLinha][posicaoJogadorColuna]=' '; // Coloca um espaço vazio na posição atual
			labirinto[posicaoJogadorLinha][++posicaoJogadorColuna]='*'; // Move o jogador para a nova posição incrementando a coluna
		}
	}
}
