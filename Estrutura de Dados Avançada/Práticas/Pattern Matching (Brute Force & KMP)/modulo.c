#include "lib.h"

void pausar(){

    char p; scanf("%c", &p);
}

void menu(){

	int op, i;
	
    TipoTexto texto;
    TipoPadrao padrao;

    do{    

        system("clear");
        puts("\n\t\t CASAMENTO DE PADROES\n");
        puts("\t1 - FORCA BRUTA\n \t2 - KMP\n \t0 - SAIR");
        printf("\nINFORME SUA OPCAO: ");
        scanf("%d", &op);

        setbuf(stdin, NULL);
        
        switch(op){
        
    		case 1:{
    			printf("\nInforme um texto: ");
    			scanf("%[^\n]s", texto);
    			setbuf(stdin, NULL);
    			
    			printf("\nInforme um padrao: ");
    			scanf("%[^\n]s", padrao);
    			setbuf(stdin, NULL);

    			forca_bruta(texto, strlen(texto), padrao, strlen(padrao));

                pausar();
    			
				break;
			}
    			
    		case 2: {
    			printf("\nInforme um texto: ");
    			scanf("%[^\n]s", texto);
    			setbuf(stdin, NULL);

    			printf("\nInforme um padrao: ");
    			scanf("%[^\n]s", padrao);
    			setbuf(stdin, NULL);

    			kmp(texto, strlen(texto), padrao, strlen(padrao));

                pausar();
    			
				break;
    		}

	    	case 0: exit(0);
        }
	
	}while(op!=0);
}

void forca_bruta(TipoTexto T, int n, TipoPadrao P, int m){
	
    int i, j, k;

    for(i=1; i<=n-m+1; i++){

        k = i;
        j = 1;

        while(T[k-1]==P[j-1]){

            ++j;
            ++k;
        }

        if(j>m){

            printf("\nCasamento na posicao: %d\n", i);
        }
    }
}

void mapearPrefixo(TipoPadrao P, int m, int* prefixo){
	
    int comprimentoPrefixo = 0; 
  
    prefixo[0] = 0;
  
    int i = 1; 

    while(i<m) { 

        if(P[i]==P[comprimentoPrefixo]){ 
            comprimentoPrefixo++; 
            prefixo[i] = comprimentoPrefixo; 
            i++; 
        } 
        else{ 

            if(comprimentoPrefixo!=0){ 

                comprimentoPrefixo = prefixo[comprimentoPrefixo-1]; 
            } 
            else{

                prefixo[i] = 0; 
                i++; 
            } 
        } 
    } 
}

void kmp(TipoTexto T, int n, TipoPadrao P, int m){ 
    
    int lps[m]; 
  
    mapearPrefixo(P, m, lps); 
  
    int i = 0;
    int j = 0;

    while (i<n) { 

        if (P[j] == T[i]) { 

            j++; 
            i++; 
        } 
  
        if (j==m) { 

            printf("\nCasamento na posicao: %d\n", (i-j)+1);

            j = lps[j-1]; 
        } 
        else 
        if (i<n && P[j] != T[i]) {

            if (j!=0) {

                j = lps[j-1]; 
            }
            else{

                ++i;
            }
        } 
    }
} 
