#include"modulo.h"

#define SAIR 0

void subMenu();

int opcao;
bool opInvalida = false;

int main() {

	int hash, i;
	Banco b;

	iniciarBanco(&b);
	
	do{

		system("clear");
			
		printf("\t# LOJA VIRTUAL #\n\n");
	
		printf("1 - Cadastrar transacao\n");
		printf("2 - Buscar transacao\n");
		printf("3 - Listar transacoes\n");
		printf("0 - Sair\n\n");

		do{

			printf("- > ");
			scanf("%d", &opcao);

			if(opcao<0 || opcao>3){
			
				printf("\nOpcao invalida!\n\n");
				
				opInvalida = true;
			}
			else{
				
				opInvalida = false;
			}

		}while(opInvalida==true);		
		
		if(opcao==1){

			system("clear");

			Cartao c;
			Transacao t;

			printf("\t# CADASTRAR TRANSACAO #\n\n");

			printf("Digite o nome do cliente: ");
			scanf("%s", c.nomeCliente);

			fflush(stdin);

			printf("Digite o numero do cartao: ");
			scanf("%d", &c.numeroCartao);

			fflush(stdin);

			printf("Digite a bandeira do cartao: ");
			scanf("%s", c.bandeira);

			printf("Digite o codigo de seguranca: ");
			scanf("%d", &c.codigoSeguranca);

			t.cartao = c;

			printf("Digite o codigo do boleto: ");
			scanf("%d", &t.codigoBoleto);

			hash = hashing(c.numeroCartao);

			b.transacoes[hash] = t;
			b.n = (b.n)+1;
			
			subMenu();
		}
		else
		if(opcao==2){

			system("clear");

			Transacao t;
			int numeroCartao;
			
			printf("\t# BUSCAR TRANSACAO #\n\n");

			printf("Digite o numero do cartao: ");
			scanf("%d", &numeroCartao);

			hash = hashing(numeroCartao);

			buscarPagamento(b, hash, &t);

			if(t.cartao.numeroCartao!=0 && tamanho(b)!=0){

				printf("\nNome do cliente: %s\n", t.cartao.nomeCliente);
				printf("Numero do cartao: %d\n", t.cartao.numeroCartao);
				printf("Bandeira do cartao: %s\n", t.cartao.bandeira);
				printf("Codigo do boleto: %d\n", t.codigoBoleto);
			}
			else{

				printf("\nNao existem transacoes referentes a este cartao.\n");
			}
			
			subMenu();
		}
		else
		if(opcao==3){

			system("clear");
			
			printf("\t# LISTAR TRANSACOES #\n");

			listarTransacoes(b);
			
			subMenu();
		}
		else{
			
			opcao = SAIR;
		}
		
	}while(opcao!=SAIR);
	
	system("clear");
		
	printf("Sistema encerrado.\n");
		
	exit(0);	
}

void subMenu(){
		
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