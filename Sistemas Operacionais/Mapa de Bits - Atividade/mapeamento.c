#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "mapeamento.h"

#define MAX 256


void inicializarVetor(char* vet){

	int i;

	for(i=0; i<MAX; i++){

		vet[i] = '-';
	}
}


void inicializarPosicoesOcupadas(char* vet){

	vet[4] = '#';   vet[8] = '#';   vet[15] = '#';
	vet[25] = '#';  vet[33] = '#';  vet[40]  = '#';
	vet[50] = '#';  vet[52] = '#';  vet[60] = '#';
	vet[64] = '#';  vet[75] = '#';  vet[88]  = '#';
	vet[92] = '#';  vet[98] = '#';  vet[100] = '#';
	vet[115] = '#'; vet[121] = '#'; vet[130]  = '#';
	vet[142] = '#'; vet[153] = '#'; vet[160] = '#';
	vet[169] = '#'; vet[178] = '#'; vet[189]  = '#';
	vet[200] = '#'; vet[206] = '#'; vet[209] = '#';
	vet[215] = '#'; vet[223] = '#'; vet[230]  = '#';
	vet[244] = '#'; vet[250] = '#'; vet[255] = '#';
}


void imprimir(char* v){

	int i, j=16;

	for(i=0; i<MAX; i++){

		printf("%c ", v[i]);

		if(i == j-1){

			printf("\n");

			j+=16;
		}
	}

	printf("\n");
}


void menu(char* vet, int* nextFitAuxP){
	
	char string[MAX];
	int op, status;

	printf("Digite uma palavra: ");
	scanf("%s", string);

	status = verificarEspacoDisponivel(vet, string);

	if(status==0){

		printf("Não há espaço para alocar esta palavra!\n\n");

		menu(vet, nextFitAuxP);
	}
	
	printf("\n");

	printf("Escolha a operação:\n");
	printf("1 - First fit\n");
	printf("2 - Best fit\n");
	printf("3 - Worst fit\n");
	printf("4 - Next fit\n\n");

	printf("Opção: "); scanf("%d", &op);
	
	printf("\n");
	
	switch(op){

		case 1: 

			system("clear");

			printf("      Antes da inserção:\n"); 
			imprimir(vet);

			printf("      Depois da inserção:\n"); 
			imprimir(firstFit(vet, string, nextFitAuxP));

			menu(vet, nextFitAuxP);
				
		case 2: 

			system("clear");

			printf("      Antes da inserção:\n"); 
			imprimir(vet);

			printf("      Depois da inserção:\n"); 
			imprimir(bestFit(vet, string, nextFitAuxP)); 

			menu(vet, nextFitAuxP);
		
		case 3: 

			system("clear");

			printf("      Antes da inserção:\n"); 
			imprimir(vet);

			printf("      Depois da inserção:\n"); 
			imprimir(worstFit(vet, string, nextFitAuxP)); 

			menu(vet, nextFitAuxP);
		
		case 4: 

			system("clear");

			printf("      Antes da inserção:\n"); 
			imprimir(vet);

			printf("      Depois da inserção:\n"); 
			imprimir(nextFit(vet, string, nextFitAuxP));

			menu(vet, nextFitAuxP);
		
		default: 

			printf("Opção inválida!\n\n"); 

			menu(vet, nextFitAuxP);
	}
}


int verificarEspacoDisponivel(char* vet, char* str){

	int tamStr, i, espacoDisponivel=0, cont=0;

	tamStr = strlen(str);

	for(i=0; i<MAX; i++){

		if(vet[i]=='-'){

			++cont;
		}
	}

	if(cont==0){

		printf("Não há mais espaço disponível para alocação!\n");
		exit(1);
	}
	
	if(tamStr>MAX){

    	return 0;
    }
    else{

    	for(i=0; i<MAX; i++){

			if(vet[i]=='-'){

				++espacoDisponivel;

				if(espacoDisponivel>=tamStr){

					return 1;
				}
			}
			else{

				espacoDisponivel = 0;
			}
	    }

		if(espacoDisponivel==0){

			return 0;
		}
    }
}


int verificarEspacoDisponivel_NextFit(char* vet, char* str, int* nextFitAuxP){

	int tamStr, i, espacoDisponivel=0, cont=0;

	tamStr = strlen(str);

	for(i=*nextFitAuxP; i<MAX; i++){

		if(vet[i]=='-'){

			++cont;
		}
	}

	if(cont==0){

		printf("Não é possível alocar esta palavra com o Next Fit!\n\n");
		
		menu(vet, nextFitAuxP);
	}
	
	if(tamStr>MAX){

    	return 0;
    }
    else{

    	for(i=*nextFitAuxP; i<MAX; i++){

			if(vet[i]=='-'){

				++espacoDisponivel;

				if(espacoDisponivel>=tamStr){

					return 1;
				}
			}
			else{

				espacoDisponivel = 0;
			}
	    }

		if(espacoDisponivel==0){

			return 0;
		}
    }
}


char* firstFit(char* vet, char* str, int* nextFitAuxP){
	
	int tamStr, cont=0, posicao=0, p, k, i;

	tamStr = strlen(str);
	
	for(i=0; i<MAX; i++){

		if(vet[i]=='-'){

			++cont;
		}
		else{

			cont = 0;
		}

		if(cont==tamStr){

			posicao = i-(cont-1);

			for(p=posicao, k=0; k<tamStr; p++, k++){

				vet[p] = str[k];
			}

			*nextFitAuxP = posicao+tamStr;

			return vet; 
		}
	}
}


char* bestFit(char* vet, char* str, int* nextFitAuxP){

	int min = 9999, i, posicao=0, j, k, l, resto=0, vazio=0, tamStr;

	tamStr = strlen(str);

	for(i=0; i<MAX; i++){

		if(vet[i]=='-'){

			++vazio;

			if(vazio==tamStr && vet[i+1]!='-'){

				posicao = i-(vazio-1);

				for(k=posicao, l=0; l<tamStr; k++, l++){

					vet[k] = str[l];
				}

				*nextFitAuxP = posicao+tamStr;

				return vet;
			}
		}
		else{

			vazio = 0;
		}
	}

	for(j=0; j<MAX; j++){

		if(vet[j]=='-'){

			++vazio;
		}
		else
		if(vet[j] != '-' && vazio<tamStr){

			vazio = 0;
		}
		
		if(vazio>tamStr && (vet[j+1] != '-' || vet[j+1] == '\0')){

			resto = vazio-tamStr;

			if(resto<min){

				min = resto;
				posicao = j-(vazio-1);
			}

			vazio = 0;
		}
	}

	for(k=posicao, l=0; l<tamStr; k++, l++){

		vet[k] = str[l];
	}

	*nextFitAuxP = posicao+tamStr;

	return vet;
}


char* worstFit(char* vet, char* str, int* nextFitAuxP){

	int maior=0, i, posicao=0, j, k, l, resto=0, vazio=0, tamStr;

	tamStr = strlen(str);

	for(j=0; j<MAX; j++){

		if(vet[j]=='-'){

			++vazio;
		}
		else{

			vazio = 0;
		}
		
		if(vazio>tamStr && (vet[j+1] != '-' || vet[j+1] == '\0')){

			resto = vazio-tamStr;

			if(resto>maior){

				maior = resto;
				posicao = j-(vazio-1);
			}

			vazio = 0;
		}
	}

	for(k=posicao, l=0; l<tamStr; k++, l++){

		vet[k] = str[l];
	}

	*nextFitAuxP = posicao+tamStr;

	return vet;
}


char* nextFit(char* vet, char*str, int* nextFitAuxP){

	int tamStr, cont=0, posicao, p, k, i, status;

	tamStr = strlen(str);

	status = verificarEspacoDisponivel_NextFit(vet, str, nextFitAuxP);

	if(status==0){

		printf("Não é possível alocar esta palavra com o Next Fit!\n\n");

		menu(vet, nextFitAuxP);
	}
	
	for(i=*nextFitAuxP; i<MAX; i++){

		if(vet[i]=='-'){

			++cont;
		}
		else{

			cont = 0;
		}

		if(cont==tamStr){

			posicao = i-(cont-1);

			for(p=posicao, k=0; k<tamStr; p++, k++){

				vet[p] = str[k];
			}

			*nextFitAuxP = posicao+tamStr;

			return vet; 
		}
	}
}
