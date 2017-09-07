#include<stdio.h>
#include<stdlib.h>

int verificaQuadradoMagico(int** mat, int tam);

int main(){
	
	int i, j, tamanho;
	int** matriz;
	
	printf("Digite o tamanho da matriz [N]x[N]: ");
	scanf("%d", &tamanho);
	
	printf("\n");
	
	matriz = (int**)malloc(tamanho*sizeof(int*));
	
	for(i=0; i<tamanho; i++){
		
		matriz[i] = (int*)malloc(tamanho*sizeof(int));
	}
	
	for(i=0; i<tamanho; i++){
		
		for(j=0; j<tamanho; j++){
			
			printf("Digite o valor da posicao [%d][%d]: ", i, j);
			scanf("%d", &matriz[i][j]);
		}
	}
	
	printf("\n");
	
	printf("MATRIZ DIGITADA\n");
	
	for(i=0; i<tamanho; i++){
		
		for(j=0; j<tamanho; j++){
			
			printf("%2d ", matriz[i][j]);
		}
		
		printf("\n");
	}
	
	printf("\n");
	
	if(verificaQuadradoMagico(matriz, tamanho)){
		
		printf("A matriz digitada e um quadrado magico!");
	}
	else{
		
		printf("A matriz digitada nao e um quadrado magico!");
	}
	
	// Liberando espaço de memória
	
	for(i=0; i<tamanho; i++)
		
		free(matriz[i]);
	
	free(matriz);
	
	
	printf("\n\n");
	
	system("PAUSE");	
	return 0;
}


int verificaQuadradoMagico(int** mat, int tam){
	
	int i, j;
	int somaInicial=0;
	int contLinhasIguais=0;
	int contColunasIguais=0;
	int somaDiagonalPrincipal=0;
	int somaDiagonalSecundaria=0;
	int somaLinha=0, somaColuna=0;
	
	for(j=0; j<tam; j++){
		
		somaInicial += mat[0][j];
	}
	
	// Verifica linhas:
                
	for(i=0; i<tam; i++){
 
        somaLinha=0;
        
        for(j=0; j<tam; j++){
            
            somaLinha += mat[i][j];     
        }
        
        if(somaLinha==somaInicial){
                                   
            contLinhasIguais++;                        
        }    
    }
    
    // Verifica colunas:
    
    for(j=0; j<tam; j++){
    
        somaColuna=0;
        
        for(i=0; i<tam; i++){
             
             somaColuna += mat[i][j];        
        }
        
        if(somaColuna==somaInicial){
                                   
            contColunasIguais++;                     
        }  
    }
    
    // Verifica diagonal principal:
    
    for(i=0; i<tam; i++){
        
        for(j=0; j<tam; j++){
             
             if(i==j){
             
                  somaDiagonalPrincipal += mat[i][j];                      
             }        
        }
    }
    
    // Verifica diagonal secundaria:

    for(i=0; i<tam; i++){
             
         for(j=0; j<tam; j++){
                 
              if(i+j==2){
                         
                   somaDiagonalSecundaria += mat[i][j];    
              }   
                 
         }    
    }
	
	if(contLinhasIguais==tam && contColunasIguais==tam && somaDiagonalPrincipal==somaInicial && somaDiagonalSecundaria==somaInicial){
      
         return 1;                       
    }
    else{
         
         return 0;   
    }
	
	printf("\n\n");
}
