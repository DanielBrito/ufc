#include "lib.h"


void menu(){
	int op, i;
	
	//--------- iniciando a estrutura --------------------//
    TipoTexto texto;
    TipoPadrao padrao;
    do{    
    //--------------- Exibir menu ---------------------//
        system("cls");
        puts("\n\t\t\t\t CASAMENTO DE PADRÕES\n");
        puts("\t1 - FORÇA BRUTA\n \t2  - KMP\n\t3  - BMH\n\t3  - BMHS\n \t0  - SAIR");
        printf("\nINFORME SUA OPCAO:\n");
        scanf("%d", &op);//Escolha da Opção
        getchar();
        switch(op){
        
    		case 1:{
    			printf("Informe um texto: ");
    			scanf("%[^\n]s", texto);
    			getchar();
    			printf("Informe um padrao: ");
    			scanf("%[^\n]s", padrao);
    			forca_bruta(texto, strlen(texto), padrao, strlen(padrao));
    			getchar();
				break;
			}
    			
    		case 2: {
    			printf("Informe um texto: ");
    			scanf("%[^\n]s", texto);
    			getchar();
    			printf("Informe um padrao: ");
    			scanf("%[^\n]s", padrao);
    			kmp(texto, strlen(texto), padrao, strlen(padrao));
    			getchar();
				break;
    		}
    		case 3: {
    			printf("Informe um texto: ");
    			scanf("%[^\n]s", texto);
    			getchar();
    			printf("Informe um padrao: ");
    			scanf("%[^\n]s", padrao);
    			bmh(texto, strlen(texto), padrao, strlen(padrao));
    			getchar();
				break;
    		}
    		case 4: {
    			printf("Informe um texto: ");
    			scanf("%[^\n]s", texto);
    			getchar();
    			printf("Informe um padrao: ");
    			scanf("%[^\n]s", padrao);
    			bmhs_(texto, strlen(texto), padrao, strlen(padrao));
    			getchar();
				break;
    		}
	    	default:
	    		puts("OPCAO INCORRETA,TENTAR NOVAMENTE.");break;
	      
	        }
	getchar();	
	}while(op!=0);
}

void forca_bruta(TipoTexto T, int n, TipoPadrao P, int m){
	int i, j, k;
	for(i = 1; i <= (n - m + 1); i++){ 
		k = i;  
		j = 1;
	    while (T[k-1] == P[j-1] && j <= m){ 
			j++; 
			k++; 
		}
	    if(j > m) 
			printf("Casamento na posicao: %d\n", i);
	}
}
void mapearPrefixo(TipoPadrao P, int m, int* prefixo){
	int comprimentoPrefixo = 0;
	prefixo[0]=0;
	//calcular o prefixo [i] de 1 até o comprimento m
	int i = 1; 
    while (i < m) { 
        if (P[i] == P[comprimentoPrefixo]) { 
            comprimentoPrefixo++; 
            prefixo[i] = comprimentoPrefixo; 
            i++; 
        } 
        else{ // se for diferente   
            if (comprimentoPrefixo != 0) { 
                comprimentoPrefixo = prefixo[comprimentoPrefixo - 1]; 
            } 
            else{ // se for zero 
                prefixo[i] = 0; 
                i++; 
            } 
        } 
    } 
}
void kmp(TipoTexto T, int n, TipoPadrao P, int m){ 
    // o vetor de prefixo
    int prefixo[m]; 
  
    //verifica o padrão do prefixo
    mapearPrefixo(P, m, prefixo); 
  
    int i = 0; // indice para o texto
    int j = 0; // indice para o padrão 
    while (i < n) { //analise todo o texto
        if (P[j] == T[i]) {//se são iguais avança a comparação
            j++; 
            i++; 
        } 
  
        if (j == m) { //se j é m então terminou de validar o padrão
            printf("Casamento na posicao: %d\n", (i - j)+1); 
            j = prefixo[j - 1]; //volta j último indice de prefixo
        } 
  
        // se j não é m 
        else 
			if (i < n && P[j] != T[i]) { //se i não terminou e ñ há padrão
	            if (j != 0) 
	                j = prefixo[j - 1]; 
	            else
	                i = i + 1; //avança no padrão
        	} 
    } 
} 
void bmh(TipoTexto T, int n, TipoPadrao P, int m){
	int i,j,k,d[257];
	for(j=0;j<=256;j++)
		d[j] = m;//tamanho do padrao
	for(j=1;j<m;j++)
		d[P[j-1]] = m-j;//até o penultimo
	i=m;
	while(i<=n){
		k=i;
		j=m;
		while(T[k-1] == P[j-1] && j>0){
			k--;
			j--;
		}
		if(j==0)
			printf("Casamento de padrao na posicao %d\n",k+1);
		i = i + d[T[i-1]];
	}
}

void bmhs_(TipoTexto T, int n, TipoPadrao P, int m){
	int i,j,k,d[257];
	for(j=0;j<=256;j++)
		d[j] = m+1;//tamanho do padrao
	for(j=1;j<=m;j++)
		d[P[j-1]] = m-j+1;//até o ultimo
	i=m;
	while(i<=n){
		k=i;
		j=m;
		while(T[k-1] == P[j-1] && j>0){
			k--;
			j--;
		}
		if(j==0)
			printf("Casamento de padrao na posicao %d\n",k+1);
		i = i + d[T[i]];
	}
}
















