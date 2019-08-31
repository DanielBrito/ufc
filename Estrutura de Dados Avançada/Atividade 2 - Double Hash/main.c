#include"modulo.h"

int main() {

	int index1=0, novoIndex=0, numeroCartao=0, j, opcao;
	bool opInvalida = false;
	Banco b;

	inicializarBanco(&b);
	
	do{

		system("clear");
			
		printf("\t# LOJA VIRTUAL #\n\n");
	
		printf("1 - Cadastrar transacao\n");
		printf("2 - Buscar transacao\n");
		printf("3 - Listar transacoes\n");
		printf("4 - Taxa de ocupacao\n");
		printf("0 - Sair\n\n");

		do{

			printf("- > ");
			scanf("%d", &opcao);

			if(opcao<0 || opcao>4){
			
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

			inicializarCartao(&c);

			printf("\t# CADASTRAR TRANSACAO #\n\n");

			printf("Digite o numero do cartao: ");
			scanf("%d", &numeroCartao);

			index1 = hash1(numeroCartao);

			fflush(stdin);

			buscarCartao(b, index1, &c); // Verificar se o cartão já foi cadastrado.

			if(c.numeroCartao==numeroCartao){

				// Melhor caso.

				// O index retornado por hash1() corresponde ao cartão que possui número igual à numeroCartao.
				// Ou seja, o cartão já foi cadastrado no sistema, restando apenas adicionar nova transação:

				printf("\n(Cartao ja cadastrado: %s)\n\n", c.nomeCliente);

				printf("Digite o codigo do boleto: ");
				scanf("%d", &t.codigoBoleto);

				c.transacoes[c.qtdTransacoes] = t;
				c.qtdTransacoes = (c.qtdTransacoes)+1;

				b.cartoes[index1] = c;
			}
			else{

				// O index retornado por hash1() não corresponde a um cartão cujo número é igual à numeroCartao.

				if(b.qtdCartoes!=MAX_CARTOES){ // Verificar se existe espaço disponível para cadastro.

					// Se o index retornado por hash1() referenciar uma posição cujo número de cartão é igual à 0,
					// Significa que a posição está disponível para o cadastro:

					if(c.numeroCartao==0){

						printf("\n(Cartao nao cadastrado no sistema)\n\n");

						// Inicializa dados do novo cartão e cadastra primeira transação:

						c.numeroCartao = numeroCartao;

						printf("Digite o nome do cliente: ");
						scanf("%s", c.nomeCliente);

						printf("Digite a bandeira do cartao: ");
						scanf("%s", c.bandeira);

						printf("Digite o codigo de seguranca: ");
						scanf("%d", &c.codigoSeguranca);

						printf("Digite o codigo do boleto: ");
						scanf("%d", &t.codigoBoleto);

						c.transacoes[c.qtdTransacoes] = t;
						c.qtdTransacoes = (c.qtdTransacoes)+1;

						b.cartoes[index1] = c;
						b.qtdCartoes = (b.qtdCartoes)+1;
					}

					// O index retornado por hash1() referencia uma posição que já está ocupada:

					else{

						Cartao c;

						inicializarCartao(&c);

						// Procurar por um registro que possui número igual a numeroCartao em outra possível posição:

						novoIndex = doubleHashBuscar(b, index1, numeroCartao, &c);

						if(novoIndex==-1){ // Não encontrou registro do cartão cujo número é igual a numeroCartao.

							printf("\n(Cartao nao cadastrado no sistema)\n\n");

							// Recalculando uma posição válida para realizar o novo cadastro:

							novoIndex = doubleHashInserir(b, index1, numeroCartao);

							// Inicializa dados do novo cartão e cadastra primeira transação:

							c.numeroCartao = numeroCartao;

							printf("Digite o nome do cliente: ");
							scanf("%s", c.nomeCliente);

							printf("Digite a bandeira do cartao: ");
							scanf("%s", c.bandeira);

							printf("Digite o codigo de seguranca: ");
							scanf("%d", &c.codigoSeguranca);

							printf("Digite o codigo do boleto: ");
							scanf("%d", &t.codigoBoleto);

							c.transacoes[c.qtdTransacoes] = t;
							c.qtdTransacoes = (c.qtdTransacoes)+1;

							b.cartoes[novoIndex] = c;
							b.qtdCartoes = (b.qtdCartoes)+1;
						}
						else
						if(c.numeroCartao==numeroCartao){

							// Encontrou um registro de cartão cujo número é igual a numeroCartao.
							// Adicionar nova transação:

							printf("\n(Cartao ja cadastrado: %s)\n\n", c.nomeCliente);

							printf("Digite o codigo do boleto: ");
							scanf("%d", &t.codigoBoleto);

							c.transacoes[c.qtdTransacoes] = t;
							c.qtdTransacoes = (c.qtdTransacoes)+1;

							b.cartoes[novoIndex] = c;
						}
					}
					
				}else{

					printf("\nA quantidade de cartoes cadastrados atingiu o limite.\n");
				}
			}

			subMenu();
		}
		else
		if(opcao==2){

			system("clear");

			Cartao c;
			
			printf("\t# BUSCAR TRANSACAO #\n\n");

			printf("Digite o numero do cartao: ");
			scanf("%d", &numeroCartao);

			index1 = hash1(numeroCartao);

			buscarCartao(b, index1, &c);

			if(b.qtdCartoes==0){ // Nenhum cartão foi cadastrado no sistema.

				printf("\nNao existem transacoes referentes a este cartao.\n");
			}
			else
			if(c.numeroCartao==numeroCartao){

				// Melhor caso. 

				// O cartão cadastrado no index retornado por hash1() possui número igual a numeroCartao.

				printf("\n   Nome do cliente: %s\n", c.nomeCliente);
				printf("   Bandeira do cartao: %s\n\n", c.bandeira);

				printf("> TRANSACOES DO CARTAO (#%d) @ [INDEX = %d]\n", c.numeroCartao, index1);
				
				for(j=0; j<c.qtdTransacoes; j++){

					printf("\n   TRANSACAO #%d\n", j+1);
					printf("   Codigo do boleto: %d\n", c.transacoes[j].codigoBoleto);
				}
			}
			else
			if(c.numeroCartao!=numeroCartao){

				// Se o cartão cadastrado no index retornado por hash1() não possuir número igual a numeroCartao,
				// Procurar por um cartão que possui número igual a numeroCartao em outra possível posição:

				novoIndex = doubleHashBuscar(b, index1, numeroCartao, &c);

				if(novoIndex==-1){ // Não encontrou registro do cartão cujo número é igual a numeroCartao.

					printf("\nNao existem transacoes referentes a este cartao.\n");
				}
				else{ // Encontrou registro do cartão cujo número é igual a numeroCartao.

					printf("\n   Nome do cliente: %s\n", c.nomeCliente);
					printf("   Bandeira do cartao: %s\n\n", c.bandeira);

					printf("> TRANSACOES DO CARTAO (#%d) @ [INDEX = %d]\n", c.numeroCartao, novoIndex);
				
					for(j=0; j<c.qtdTransacoes; j++){

						printf("\n   TRANSACAO #%d\n", j+1);
						printf("   Codigo do boleto: %d\n", c.transacoes[j].codigoBoleto);
					}
				}	
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
		else
		if(opcao==4){

			system("clear");
			
			printf("\t# TAXA DE OCUPACAO #\n\n");

			printf("Espaco livre: %d\n", MAX_CARTOES-b.qtdCartoes);
			printf("Espaco ocupado: %d\n", b.qtdCartoes);
			printf("Taxa de ocupacao: %.2f%%\n", taxaDeOcupacao(b));
			
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