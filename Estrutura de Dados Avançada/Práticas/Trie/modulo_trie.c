#include "lib_trie.h"

void menu(){

	int op, i;
	
    char valor[50];
    Tno* raiz = constuir();
    char pausar;

    do{    
    
        system("clear");
        puts("\n\t\tTRIE'S\n");
        puts("\t1 - INSERIR ELEMENTO\n \t2 - BUSCAR\n \t0 - SAIR");
        printf("\nINFORME SUA OPCAO: ");
        scanf("%d", &op);

        setbuf(stdin, NULL);
        
        switch(op){
        
    		case 1:{
    			printf("\nElemento a ser inserido: ");
    			scanf("%s",valor);

                setbuf(stdin, NULL);

    			inserir(raiz, valor, strlen(valor));
				break;
			}
    			
    		case 2: {

    			printf("\nElemento a ser buscado: ");
    			scanf("%s",valor);

                setbuf(stdin, NULL);

    			if(buscar(raiz, valor, strlen(valor))){

    				puts("\nEncontrado\n");
                    scanf("%c", &pausar);

                    setbuf(stdin, NULL);
                }
                else{

    				puts("\nNao encontrado\n");
                    scanf("%c", &pausar);

                    setbuf(stdin, NULL);
                }
			    break;
    		}

			case 0: exit(1);
	      
	    }

	}while(op!=0);
}

Tno* constuir(void) { 

   Tno* no = (Tno*)malloc(sizeof(Tno));
   no->fimPalavra = false;

   int i;

   // memset(no->filhos, NULL, sizeof(no->filhos));

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

            aux->filhos[index] = constuir();
        }

        aux = aux->filhos[index];
    }

    aux->fimPalavra = true;
} 

bool buscar(Tno* raiz, char *chave, int tamanho) {

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