#include "lib.h"

int main(void) {
	int op, valor, maximo_elementos;
	
	//--------- iniciando a estrutura --------------------//
    puts("Informe o numero maximo de elementos do heap: ");
    scanf("%d", &maximo_elementos);
    heap *h = criar(maximo_elementos);
    
    do{    
    //--------------- Exibir menu ---------------------//
        system("cls");
        puts("\n\t\t\t\tHEAP\n");
        puts("\t1  - INSERIR ELEMENTO\n \t2  - RETIRAR ELEMENTO\n \t3  - MOSTRAR TODA ESTRUTURA\n\t4 - LIBERAR TODA ESTRUTURA\n\t0  - SAIR");
        printf("\nINFORME SUA OPCAO:\n");
        scanf("%d", &op);//Escolha da Opção
        
        switch(op)
        {
        //Opção de exibir lista
    		case 1:{
    			printf("Informe um elemento: ");
    			scanf("%d", &valor);
    			heap_insere(h,valor);
    			mostrar(h);
				break;
			}
    		
    		case 2:{
    			puts("Voce escolheu tirar o topo \n");
    			valor = heap_retira(h);
    			printf("Elemento %d  foi removido\n", valor);
    			mostrar(h);
				break;
			}
    			
    		case 3:mostrar(h); break;
    			
    		case 4: heap_libera(h); break;
	    	default:
	    			puts("OPCAO INCORRETA,TENTAR NOVAMENTE.");break;
	      
	        }
		getch();
	    }while(op!=0);

  system("PAUSE");	
  return 0;
}
