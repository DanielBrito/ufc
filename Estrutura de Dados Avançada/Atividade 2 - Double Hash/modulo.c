#include"modulo.h"

void inicializarBanco(Banco* B){

	memset(B->cartoes, 0, sizeof(B->cartoes));
	B->qtdCartoes = 0;
}

void inicializarCartao(Cartao* C){

	memset(C->transacoes, 0, sizeof(C->transacoes));
	C->qtdTransacoes = 0;
	C->numeroCartao = 0;
}

int buscarCartao(Banco B, int pos, Cartao* C){
	
	if(pos<0 || pos>MAX_CARTOES) return 0;

	*C = B.cartoes[pos];
	
	return 1;
}

void listarTransacoes(Banco B){

	Cartao c;
	int i, j;

	if(B.qtdCartoes!=0){

		for(i=0; i<MAX_CARTOES; i++){

			c = B.cartoes[i];

			if(c.numeroCartao!=0){

				printf("\n> TRANSACOES DO CARTAO (#%d) @ [INDEX = %d]\n\n", c.numeroCartao, i);

				printf("   Nome do cliente: %s\n", c.nomeCliente);
				printf("   Bandeira do cartao: %s\n", c.bandeira);

				for(j=0; j<c.qtdTransacoes; j++){

					printf("\n   TRANSACAO #%d\n", j+1);
					printf("   Codigo do boleto: %d\n", c.transacoes[j].codigoBoleto);
				}
			}
		}
	}
	else{

		printf("\nNao existem transacoes cadastradas.\n");
	}
}

float taxaDeOcupacao(Banco B){

	return (B.qtdCartoes*100)/MAX_CARTOES;
}

int hash1(int chave){
	
	return ((chave*((chave-1)%9+1))%MAX_CARTOES); // Multiplicando a chave pela sua raiz digital.
}

int hash2(int chave){

	return (PRIMO-(chave%PRIMO));
}

int doubleHashInserir(Banco B, int index1, int chave){

	int index2 = hash2(chave);
	int novoIndex, i=1;

	// É garantida a existência de pelo menos um espaço disponível:

	while (1) {

		novoIndex = (index1+i*index2)%MAX_CARTOES;

		if (B.cartoes[novoIndex].numeroCartao==0) { 

			return novoIndex;
		} 

		i++; 
	}

	return 1;
}

int doubleHashBuscar(Banco B, int index1, int chave, Cartao* C){

	int index2 = hash2(chave);
	int novoIndex, i=1, n=MAX_CARTOES;

	while (n--) {

		novoIndex = (index1+i*index2)%MAX_CARTOES;

		if (B.cartoes[novoIndex].numeroCartao==chave) { 

			*C = B.cartoes[novoIndex];

			return novoIndex;
		} 

		i++; 
	}

	return -1;
}

void subMenu(){

	int opcao;
	bool opInvalida = false;
		
	printf("\n\nO que deseja fazer? \n\n");
	
	printf("1 - Retornar ao menu\n");
	printf("0 - Sair\n\n");

	do{

		printf("- > ");
		scanf("%d", &opcao);
		
		if(opcao!=0 && opcao!=1){
			
			printf("\nOpcao invalida!\n\n");
			
			opInvalida = true;
		}
		else{
			
			opInvalida = false;
		}	

	}while(opInvalida==true);
		
	if(opcao==0){
		
		system("clear");
		
		printf("Sistema encerrado.\n");
		
		exit(0);
	}
}