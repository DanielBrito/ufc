#include "lib.h"

void menu(){

	int op, i;
	
    Tregistro valor;
	Tpagina pagina = 0;
    
    do{

        printf("\n\t\t\t\tARVORE B - ORDEM 2\n");
        printf("\t1 - INSERIR ELEMENTO\n \t2  - IMPRIMIR ARVORE\n \t0  - SAIR");
        printf("\n\nINFORME SUA OPCAO: ");
        scanf("%d", &op);
        
        switch(op){

    		case 1: printf("\nInforme um elemento: ");
    			    scanf("%d", &valor.chave);

    			    pagina = insere(valor, pagina);
                
				    break;
    			
    		case 2: imprime(pagina, 0); break;
        }

	}while(op!=0);
}

Tregistro* pesquisar(int chave, Tpagina a){ 

    int i = 0;

    if (a==NULL) return NULL;

    while (i < a->n && chave > a->registro[i].chave){

        i++;
    }

    if (chave == a->registro[i].chave) {

        return &a->registro[i];
    }
  	
    if (chave < a->registro[i].chave){

        return (pesquisar(chave, a->folha[i]));
    }
    else{

        return (pesquisar(chave, a->folha[i+1]));
    }
}

void insere_na_pagina(Tpagina pag, Tregistro reg, Tpagina pag_dir){ 

    int i;

    for (i = pag->n; (i > 0) && (reg.chave < pag->registro[i-1].chave); i--){

        pag->registro[i] = pag->registro[i-1];
        pag->folha[i+1] = pag->folha[i];    
    }

    pag->registro[i] = reg;
    pag->folha[i+1] = pag_dir;
    pag->n++;
} 

int insere_rec(Tregistro reg, Tpagina pag, Tregistro *reg_retorno, Tpagina *pag_retorno){ 

    int cresceu;
    int j, i = 0;
    Tpagina pag_temp;

    if (pag == NULL){ 

        *reg_retorno = reg; 
        *pag_retorno = NULL;

        return TRUE;
    }
    
    while (i < pag->n && reg.chave > pag->registro[i].chave) {

        i++;
    }

    if (reg.chave == pag->registro[i].chave) { 

        printf("O registro ja esta presente!\n");

        return FALSE; 
    }

    cresceu = insere_rec(reg, pag->folha[i], reg_retorno, pag_retorno);

    if (!cresceu) {

        return FALSE;
    }

    if (pag->n < maximo){

        insere_na_pagina(pag, *reg_retorno, *pag_retorno);

        return FALSE;
    }

    pag_temp = (Tpagina)malloc(sizeof(pagina));
    pag_temp->n = 0;  
    pag_temp->folha[0] = NULL;
    
    if (i < ordem+1){

        insere_na_pagina(pag_temp, pag->registro[maximo-1], pag->folha[maximo]);//insere o �ltimo elemento em uma flha tempor�ria
        pag->n--;
        insere_na_pagina(pag, *reg_retorno, *pag_retorno);
    } 
    else{

        insere_na_pagina(pag_temp, *reg_retorno, *pag_retorno);
    }
        
    
    for (j = ordem + 2; j <= maximo; j++){

        insere_na_pagina(pag_temp, pag->registro[j-1], pag->folha[j]);
    }        
    
    pag->n = ordem;  
    pag->folha[0] = pag->folha[ordem+1];
    *reg_retorno = pag->registro[ordem];
    *pag_retorno = pag_temp;

    return TRUE;
}

Tpagina insere(Tregistro reg, Tpagina pag_raiz){ 

    int cresceu;
    Tregistro reg_retorno;
    Tpagina pag_retorno, pag_temp;

    cresceu = insere_rec(reg, pag_raiz, &reg_retorno, &pag_retorno);

    if (cresceu){

        pag_temp = (Tpagina)malloc(sizeof(pagina));
        pag_temp->n = 1;
        pag_temp->registro[0] = reg_retorno;
        pag_temp->folha[1] = pag_retorno;
        pag_temp->folha[0] = pag_raiz;

        return pag_temp;
    }
    
    return pag_raiz;
}

void imprime(Tpagina p, int nivel){ 

    int i;

    if (p == NULL) return;

    printf("Nivel %d : ", nivel);

    for (i = 0; i < p->n; i++){

        printf("%d ", p->registro[i].chave);
    }
        
    printf("\n");

    for (i = 0; i <= p->n; i++){

        imprime(p->folha[i], nivel+1);
    }        
} 
