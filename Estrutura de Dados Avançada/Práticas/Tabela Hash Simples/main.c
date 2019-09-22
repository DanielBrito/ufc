#include "libsequ.h"


//Programa principal
int main()
{   
    int op, hash, i, pos;
    Tlista L;
	Telemento dado;
	
    criar(&L);
    
    do{    
    //Exibir menu
        system("cls");
        puts("\n\t\t\t\tEDITOR DE LISTAS\n");
        puts("\t1  - EXIBIR LISTA\n \t2  - INSERIR UM ELEMENTO\n \t3  - ENCONTRAR UM ELEMENTO\n0  - SAIR");
        printf("\nINFORME SUA OPCAO:\n");
        scanf("%d", &op);//Escolha da Opção
        
        switch(op)
        {
        //Opção de exibir lista
    		case 1:
            {
    			 exibir(L);
    		}break;
    	//Opção de Inserir um elemento	
    		case 2:
            {
                printf("Informe uma chave: ");
                scanf("%d", &dado.chave);
                hash = hashing(dado.chave);
                printf("HASH = %d", hash);
                	printf("Informe o valor do elemento: ");
                	scanf("%d", &dado.valor);
                	L.elemento[hash] = dado;
                	L.n = (L.n)+1;
            }break; 
            

           
            //Buscar um elemento 
            case 3:
            {
                 
				 printf("Informe a chave para o elemento:");
				 scanf("%d", &dado.chave);
				 hash = hashing(dado.chave);
				 printf("Hash = %d\n", hash);
				 if(elemento(L, hash, &dado)==1){
				 	printf("Chave: %d - Valor = %d", dado.chave, dado.valor);
				 	
				 }
            }break;
            
            
            //Opção de sair do sistema     
    		case 0:
            {
    		     printf("ENCERRANDO PROGRAMA");
    		     return 0;
    		}break;
    		
    		// Outra opção nao oferecida
    		default:
    			puts("OPCAO INCORRETA,TENTAR NOVAMENTE.");break;
      
        }
	getch();
    }while(op!=0);
  
  system("PAUSE");	
  return 0;
}
