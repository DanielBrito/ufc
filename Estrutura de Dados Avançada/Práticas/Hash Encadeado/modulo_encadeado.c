#include"libHashEnc.h"

int criar(TLista *L){
	int i;
	for(i=0;i<MAX;i++){
		L->elemento[i] = NULL;
	}
	L->n=0;
}

int inserir(TLista *L, int hash, Tdado dado){
	Tno novo;
    novo = (Tno *) malloc (sizeof(Tno));
    novo->dado =dado;
		if(L->elemento[hash]==NULL){
			novo->proximo = NULL;
			L->elemento[hash] = novo;
			L->n=1;
		}
		else{
			novo->proximo = L->elemento[hash];
			L->elemento[hash]= novo;
			L->n +=1;
		}
		
	}
void exibir(TLista L){
	Tno aux;
	int i;
	if(L.n!=0){
		for(i=0;i<MAX;i++){
			if(L.elemento[i]!=NULL){
				printf("-------------i = %d --------------\n", i);
				aux =L.elemento[i];
				while(aux!=NULL){
					printf("Chave = %d\n", L.elemento[i]->dado.chave);
					printf("Valor = %d\n\n", L.elemento[i]->dado.valor);
					aux = aux->proximo;
				}
			}
		}
	}
	else
		printf("tabela vazia");
}

int hashing(int chave){
	return (chave % MAX);
}
