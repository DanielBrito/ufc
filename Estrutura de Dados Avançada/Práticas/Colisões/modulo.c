#include "libsequ.h"

void criar(Tlista *L){	
	memset(L->elemento, 0, (sizeof(L->elemento)));
	L->n=0;
	
     }
    
    
int tamanho(Tlista L){
    return (L.n);
}


int elemento(Tlista L, int pos, Telemento *valor){
    if(pos<1 || pos> MAX)//Verifica antes se estar vazia
    return 0;
    *valor = L.elemento[pos];
	return 1;
}


//Funcao exibir
void exibir(Tlista L){
    Telemento elem;
     int i;
     if (tamanho(L)!=0)
         for (i=0; i<MAX; i++){
             elemento(L, i, &elem);
             if(elem.valor != 0){
				printf("indice: %d\n", i);
	            printf("chave: %d \n", elem.chave);
	            printf("valor: %d \n\n", elem.valor);
         		}
             }
     else
         puts("Nao ha elementos na lista");
}  

int hashing(int chave){
	return (chave % MAX);
}
//-----------TRATAMENTO PARA COLIS�ES --------------//
float taxaOcupacao(Tlista L){
	return (L.n/100);
}
int sondagemLinear(Tlista *L, Telemento dado){

    int hash = hashing(dado.chave);
    int i;
    Telemento aux;

    if(L->n!=MAX){

        if(L->elemento[hash].valor == 0){

            L->elemento[hash] = dado;
            L->n+=1;

            return hash;
        }
        else{

            for(i=hash+1; i<MAX; i++){

                elemento(L, i, aux);

                if(aux.valor==0){

                    L->elemento[i] = dado;
                    L->n+=1;

                    return i;
                }
            }

            for(i=0; i<has-1; i++){

                elemento(L, i, aux);

                if(aux.valor==0){

                    L->elemento[i] = dado;
                    L->n+=1;

                    return i;
                }
            }
        }
    }
	
}
int rehashing(Tlista L, Telemento dado){

    int hash = hashing(dado.chave);
    int i=1;

    if(L->n!=MAX){

        if(L->elemento[hash].valor==0){

            L->elemento[hash] = dado;
            L->n+=1;
            return hash;
        }
        else{

            do{

                hash = hashing(hash+i);

                if(L->elemento[hash].valor==0){

                    L->elemento[hash] = dado;
                    L->n+=1;
                    return hash;
                }

                ++i;

            }while(1);
        }
    }
	
}

int doubleHashing(Tlista L, Telemento dado){
	
}