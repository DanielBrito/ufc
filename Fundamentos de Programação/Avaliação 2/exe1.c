#include<stdio.h>
#include<stdlib.h>

void calculaNota(int* gab, int resp[5][4]);
void porcentagemAprovacao(int* gab, int resp[5][4]);

int main(){
	
	int gabarito[4];
	int respostas[5][4];
	int i, j;
	
	printf("GABARITO\n\n");
	
	for(i=0; i<4; i++){
		
		printf("Questao %d: ", i+1);
		scanf("%d", &gabarito[i]);
	}
	
	for(i=0; i<5; i++){
		
		printf("\nRESPOSTAS DO ALUNO %d\n", i+1);
		
		for(j=0; j<4; j++){
			
			printf("Questao %d: ", j+1);
			scanf("%d", &respostas[i][j]);
		}
	}
	
	printf("\n\n");
	
	printf("RELATORIO\n");
	
	calculaNota(gabarito, respostas);
	
	porcentagemAprovacao(gabarito, respostas);
	
	printf("\n\n");
	
	return 0;
}


void calculaNota(int* gab, int resp[5][4]){
	
	int a, g, r; // [a]luno - [g]ab - [r]esp
	float nota=0;
	
	for(a=0; a<5; a++){
		
		nota = 0;
		
		for(g=0, r=0; g<4, r<4; g++, r++){
			
			if(gab[g]==resp[a][r]){
				
				nota += 2.5;
			}
		}
		
		printf("\nNota do aluno %d: %.2f", a+1, nota);
	}
}


void porcentagemAprovacao(int* gab, int resp[5][4]){
	
	int a, g, r; // [a]luno - [g]ab - [r]esp
	float nota=0, percentual=0;
	
	for(a=0; a<5; a++){
		
		nota = 0;
		
		for(g=0, r=0; g<4, r<4; g++, r++){
			
			if(gab[g]==resp[a][r]){
				
				nota += 2.5;
			}
		}
		
		if(nota>=7){
			
			percentual += 20;
		}
	}
	
	printf("\n\nPercentual de aprovacao: %.2f%%", percentual);
}
