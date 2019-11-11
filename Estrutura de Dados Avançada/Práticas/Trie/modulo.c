#include "modulo.h"

void menu(){

	int op, i;
	
    char valor[50];
    Tno* raiz = constroi();

    do{    

        system("clear");

        printf("\n\t\tTRIE\n");
        printf("\t1 - INSERIR ELEMENTO\n\t2 - BUSCAR\n\t0 - SAIR");
        printf("\n\nINFORME SUA OPCAO: ");
        scanf("%d", &op);

		setbuf(stdin, NULL);
        
        switch(op){

    		case 1:{

    			printf("\nInforme um elemento: ");
    			scanf("%s", valor);

				setbuf(stdin, NULL);

    			inserir(raiz, valor, strlen(valor));

				break;
			}

    		case 2: {

    			printf("\nInforme um elemento: ");
    			scanf("%s", valor);

				setbuf(stdin, NULL);

    			if(busca(raiz, valor, strlen(valor)))
    				puts("\nEncontrado!\n");
    			else
    				puts("\nNao encontrado!\n");

				char pausar; scanf("%c", &pausar);

			 	break;
    		}
			
	    	case 0: exit(0);
	    }

	}while(op!=0);
}

// Retorna uma trie vazia
Tno* constroi(void) { 

    Tno* no = (Tno*) malloc(sizeof(struct TrieNo)) ;
	no->fimPalavra = false;

	int i;
	
	for(i=0; i<max_alfabeto; i++){

		no->filhos[i] = NULL;
	}
		
	return no;
}

void inserir(Tno* raiz, char *chave, int tamanho) { 

    Tno* aux = raiz;
	int i;
    
    for(i=0; i<tamanho; i++){

    	int index = chave[i]-'a';

    	if(!aux->filhos[index]){

			aux->filhos[index] = constroi();
		}
    		
    	aux = aux->filhos[index];
	}

	aux->fimPalavra = true;
} 

bool busca(Tno* raiz, char *chave, int tamanho) {

   Tno* aux = raiz;
   int i;

   for(i=0; i<tamanho; i++){

    	int index = chave[i]-'a';

    	if(!aux->filhos[index]){

			return false;
		}
    		
    	aux = aux->filhos[index];
	}
	
	return (aux!=NULL && aux->fimPalavra);
} 










