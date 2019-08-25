#include"modulo.h"

int hashing(int chave){
	
	return ((chave*((chave-1)%9+1))%MAX); // Multiplicando a chave pela sua raiz digital
}

void iniciarBanco(Banco* B){

	memset(B->transacoes, 0, sizeof(B->transacoes));
	B->n = 0;
}

int tamanho(Banco B){
	
	return (B.n);
}

int buscarPagamento(Banco B, int pos, Transacao* T){
	
	if(pos<1 || pos>MAX) return 0;
	
	*T = B.transacoes[pos];
	
	return 1;
}

void listarTransacoes(Banco B){

	Transacao t;
	int i;

	if(tamanho(B)!=0){

		for(i=0; i<MAX; i++){

			buscarPagamento(B, i, &t);

			if(t.cartao.numeroCartao!=0){

				printf("\nNome do cliente: %s\n", t.cartao.nomeCliente);
				printf("Numero do cartao: %d\n", t.cartao.numeroCartao);
				printf("Bandeira do cartao: %s\n", t.cartao.bandeira);
				printf("Codigo do boleto: %d\n", t.codigoBoleto);
			}
		}
	}
	else{

		printf("\nNao existem transacoes cadastradas.\n");
	}
}