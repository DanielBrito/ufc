#include<stdio.h>
#include<stdlib.h>

/*

Um amigo decidiu abrir uma pequena lanchonete e pediu sua ajuda para desenvolver um programa 
para calcular o pedido de cada cliente e, no final do dia, exibir o total que foi recebido 
para que ele possa verificar o seu lucro.

Seu programa deverá receber vários pedidos, onde cada um deles poderá ser composto por vários 
lanches em quantidades específicas. Assim, cada entrada será composta pelo nome do cliente, 
o código e a quantidade dos lanches desejados. No final, deverá ser exibido o recibo do pedido 
do cliente, contendo o valor total e o seu nome. O código 0 finaliza cada pedido.

Antes de sair do programa, exiba o valor total que foi recebido durante o dia.

*/

int main(){
	
	int cod, qtd, novoPedido, novoLanche, codInvalido, qtdInvalida;
	char nome[20];
	float saldoDia=0, totalPedido;
	
	do{ // Laço de repetição para controlar a quantidade de pedidos em um determinado dia
		
		printf("NOVO PEDIDO\n\n");
		
		totalPedido=0; // Sempre que um novo pedido se inicia, precisamos zerar o valor total do mesmo
		
		printf("Nome do cliente: ");
		scanf("%[^\n]s", nome); // Recebe uma string composta, ou seja, juntamente com espaço. Por exemplo: Daniel Brito
		
		do{ // Laço de repetição para controlar os lanches desejados por um determinado cliente
			
			do{ // Laço de repetição para verificar uma possível entrada inválida referente ao código do lanche

                printf("\n\tTABELA DE PRECOS\n\n");
                printf("Codigo   Lanche         Preco\n");
                printf("1        Pastel         2.00\n");
                printf("2        Mini pizza     2.50\n");
                printf("3        Sanduiche      4.00\n");
                printf("4        Suco           3.50\n");
                printf("5        Refrigerante   3.00\n\n");
				
				printf("Codigo do lanche: ");
				scanf("%d", &cod);
				
				if(cod!=1 && cod!=2 && cod!=3 && cod!=4 && cod!=5){
					
					codInvalido = 1;
					printf("\nCodigo invalido!\n\n");
				}
				else{
					
					codInvalido = 0;
				}
				
			}while(codInvalido==1);
			
			do{ // Laço de repetição para verificar uma possível entrada inválida referente à quantidade

				printf("Digite a quantidade: ");
				scanf("%d", &qtd);
				
				if(qtd<1){
					
					qtdInvalida = 1;
					printf("\nQuantidade invalida!\n\n");
				}
				else{
					
					qtdInvalida = 0;
				}
				
			}while(qtdInvalida==1);

            // Indexando o código do pedido do cliente para realizar o cálculo do total baseado na tabela de preços:
						
			switch(cod){
				
				case 1: totalPedido = totalPedido + (2.00*qtd); break;
				case 2: totalPedido = totalPedido + (2.50*qtd); break;
				case 3: totalPedido = totalPedido + (4.00*qtd); break;
				case 4: totalPedido = totalPedido + (3.50*qtd); break;
				case 5: totalPedido = totalPedido + (3.00*qtd); break;
			}
			
			printf("\n");
			
			do{ // Laço de repetição para controlar a quantidade de diferentes lanches que um cliente pode pedir
				
				printf("Deseja pedir outro lanche?\n");
				printf("1 - Sim\n");
				printf("0 - Nao\n\n");
				
				printf("Opcao: ");
				scanf("%d", &novoLanche);
				
				if(novoLanche!=0 && novoLanche!=1){
					
					printf("\nOpcao invalida!\n\n");
				}
				
			}while(novoLanche!=0 && novoLanche!=1);

			printf("\n");
			
		}while(novoLanche==1);

        // Exibição do recibo de um determinado cliente após ele fechar sua conta, ou seja, não desejar mais nenhum lanche:
		
		printf("RECIBO\n");
		printf("Nome do cliente: %s\n", nome);
		printf("Total a pagar: R$ %.2f\n", totalPedido);
		
		saldoDia += totalPedido; // Adicionando o valor total de cada pedido ao saldo do dia
		
		printf("\n");

		do{ // Laço de repetição para verificar se o administrador deseja atender outro cliente ou sair do sistema
			
			printf("O que deseja fazer?\n");
			printf("1 - Atender novo cliente\n");
			printf("0 - Sair do sistema\n\n");
			
			printf("Opcao: ");
			scanf("%d", &novoPedido);
			
			if(novoPedido!=0 && novoPedido!=1){
				
				printf("\nOpcao invalida!\n\n");
			}
			
		}while(novoPedido!=0 && novoPedido!=1);
		
		printf("\n");
		
	}while(novoPedido==1);
	
	printf("SALDO DO DIA:\nR$ %.2f\n", saldoDia); // Exibição do somatório de todos os pedidos realizados no dia
	
	return 0;
}
