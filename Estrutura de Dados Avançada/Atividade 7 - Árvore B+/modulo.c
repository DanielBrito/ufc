#include"modulo.h"

int chave;

void inicializar(){

    chave = lerContador();

    menuPrincipal();
}

// Método para exibição das opções do menu principal:

void menuPrincipal(){

	int opcao;
	bool opInvalida = false;

	system("clear");

	printf("\tGERENCIMENTO DE LIVROS\n\n");

	printf("1 - Inserir livro\n");
	printf("2 - Buscar livro\n");
	printf("3 - Modificar livro\n");
	printf("4 - Listar livros\n");
	printf("0 - Sair\n\n");

	do{

		printf("- > ");
		scanf("%d", &opcao);

		if(opcao<0 || opcao>4){
		
			printf("\nOpcao invalida!\n\n");
			
			opInvalida = true;
		}
		else{
			
			opInvalida = false;
		}

	}while(opInvalida==true);

    setbuf(stdin, NULL);

    if(opcao==1){

        system("clear");

		printf("\t# INSERIR LIVRO #\n\n");

		inserirLivro();

		subMenu();

    }
    else
    if(opcao==2){

        system("clear");

		printf("\t# BUSCAR LIVRO #\n\n");

		buscarLivro();

		subMenu();
    }
    else
    if(opcao==3){

        system("clear");

		printf("\t# MODIFICAR LIVRO #\n\n");

		modificarLivro();

		subMenu();
    }
    else
    if(opcao==4){

        system("clear");

		printf("\t# LISTAR LIVROS #\n\n");

		listarLivros();

		subMenu();
    }
    else{

        system("clear");

        printf("Sistema encerrado.\n");

        exit(0);
    }
}

// Método para exibição do submenu, após a realização de algum processo:

void subMenu(){

    int opcao;
	bool opInvalida = false;
		
	printf("\n\nO que deseja fazer? \n\n");
	
	printf("1 - Menu Principal\n");
	printf("0 - Sair\n\n");

	do{

		printf("- > ");
		scanf("%d", &opcao);
		
		if(opcao<0 || opcao>1){
			
			printf("\nOpcao invalida!\n\n");
			
			opInvalida = true;
		}
		else{
			
			opInvalida = false;
		}	

	}while(opInvalida==true);
		
	if(opcao==1){
		
		menuPrincipal();
	}
	else{

		system("clear");

		printf("Sistema encerrado.\n");

		exit(0);
	}
}

void inserirLivro(){

    char tituloPort[MAX], tituloOrig[MAX], autor[MAX], pais[MAX], nota[MAX];
    int ano;

    printf("Digite o titulo em portugues: ");
    scanf("%[^\n]s", tituloPort);

    setbuf(stdin, NULL);

    printf("Digite o titulo original: ");
    scanf("%[^\n]s", tituloOrig);

    setbuf(stdin, NULL);

    printf("Digite o nome do autor: ");
    scanf("%[^\n]s", autor);

    setbuf(stdin, NULL);

    printf("Digite o ano de lancamento: ");
    scanf("%d", &ano);

    setbuf(stdin, NULL);

    printf("Digite o pais: ");
    scanf("%[^\n]s", pais);

    setbuf(stdin, NULL);

    printf("Digite a nota: ");
    scanf("%[^\n]s", nota);

    setbuf(stdin, NULL);

    salvarRegistro(tituloPort, tituloOrig, autor, ano, pais, nota);
}

void buscarLivro(){

    int chave;

    printf("Digite a chave do livro a ser buscado: ");
    scanf("%d", &chave);

    // Abrindo o arquivo que contém as chaves dos livros cadastrados:

    FILE* chaves = fopen("chaves.txt", "r");

	if(chaves==NULL){

        printf("Erro na abertura do arquivo!\n");
        exit(1);
	}

    // Construindo a árvore com as chaves existentes no arquivo (chaves.txt):

    Registro valor;
	Pagina pagina = 0;

    while(fscanf(chaves, "%d", &valor.chave)==1){

    	pagina = inserir(valor, pagina);
    }

    fclose(chaves);

    // Verificando se a chave buscada está presente na árvore:

    Registro* resultado = pesquisar(chave, pagina);

    if(resultado==NULL){

        // Não foi encontrado registro referente à chave digitada:

        printf("\nNenhum registro encontrado!\n");
    }
    else{

        // Busca (linear) das informações do livro no arquivo livros.txt:

        FILE* livros = fopen("livros.txt", "r");
    
        char tituloPort[MAX], tituloOrig[MAX], autor[MAX], pais[MAX], nota[MAX];
        int ano, index;

        if(livros==NULL){

            printf("Erro na abertura do arquivo!\n");
            exit(1);
        }

        while(fscanf(livros, "%d %s %s %s %d %s %s", &index, tituloPort, tituloOrig, autor, &ano, pais, nota)==7){

            if(index==chave){

                printf("\nCodigo: %d\n", index);
                printf("Titulo em portugues: %s\n", separarTexto(tituloPort));
                printf("Titulo original: %s\n", separarTexto(tituloOrig));
                printf("Autor: %s\n", separarTexto(autor));
                printf("Ano de lancamento: %d\n", ano);
                printf("Pais: %s\n", separarTexto(pais));
                printf("Nota: %s\n", separarTexto(nota));

                break;
            }
        }

        fclose(livros);
    }
}

void modificarLivro(){

    printf("Digite a chave do livro a ser modificado: ");
    scanf("%d", &chave);

    setbuf(stdin, NULL);

    // Abrindo o arquivo que contém as chaves dos livros cadastrados:

    FILE* chaves = fopen("chaves.txt", "r");

	if(chaves==NULL){

        printf("Erro na abertura do arquivo!\n");
        exit(1);
	}

    // Construindo a árvore com as chaves existentes no arquivo (chaves.txt):

    Registro valor;
	Pagina pagina = 0;

    while(fscanf(chaves, "%d", &valor.chave)==1){

    	pagina = inserir(valor, pagina);
    }

    fclose(chaves);

    // Verificando se a chave do livro a ser modificado está presente na árvore:

    Registro* resultado = pesquisar(chave, pagina);

    if(resultado==NULL){

        // Não foi encontrado registro referente à chave digitada:

        printf("\nNenhum registro encontrado!\n");
    }
    else{

        char novaNota[MAX];

        char tituloPort[MAX], tituloOrig[MAX], autor[MAX], pais[MAX], nota[MAX];
        int ano, index;

        printf("\nDigite a nova nota do livro: ");
        scanf("%[^\n]", novaNota);

        setbuf(stdin, NULL);

        // Abrindo o arquivo para atualização do livro que possui a chave digitada:

        FILE *livros = fopen("livros.txt", "r");

        if(livros==NULL){

            printf("Erro na abertura do arquivo!\n");
            exit(1);
        }

        // Atualizando a linha do arquivo (livros.txt) onde o livro está localizado:

        FILE * fPtr;
        FILE * fTemp;
        
        char buffer[BUFFER];
        char novaLinha[BUFFER];
        int linha, cont=0;

        setbuf(stdin, NULL);

        fPtr  = fopen("livros.txt", "r");
        fTemp = fopen("replace.tmp", "w"); 

        if (fPtr==NULL || fTemp==NULL){

            printf("Erro na abertura do arquivo!\n");
            exit(1);
        }

        while(fscanf(livros, "%d %s %s %s %d %s %s", &index, tituloPort, tituloOrig, autor, &ano, pais, nota)==7){

            cont++;

            if(index==chave){

                sprintf(novaLinha, "%d %s %s %s %d %s %s\n", index, unificarTexto(tituloPort), unificarTexto(tituloOrig), unificarTexto(autor), ano, unificarTexto(pais), unificarTexto(novaNota));

                fputs(novaLinha, fTemp);
            }
            else{

                sprintf(buffer, "%d %s %s %s %d %s %s\n", index, unificarTexto(tituloPort), unificarTexto(tituloOrig), unificarTexto(autor), ano, unificarTexto(pais), unificarTexto(nota));

                fputs(buffer, fTemp);
            }
        }

        fclose(fPtr);
        fclose(fTemp);

        remove("livros.txt");

        rename("replace.tmp", "livros.txt");

        printf("\nRegistro atualizado com sucesso!\n");

    }
}

void listarLivros(){

    FILE *livros = fopen("livros.txt", "r");
    
    char tituloPort[MAX], tituloOrig[MAX], autor[MAX], pais[MAX], nota[MAX];
    int ano, index;

	if(livros==NULL){

        printf("Erro na abertura do arquivo!\n");
        exit(1);
	}

    while(fscanf(livros, "%d %s %s %s %d %s %s", &index, tituloPort, tituloOrig, autor, &ano, pais, nota)==7){

        printf("Codigo: %d\n", index);
        printf("Titulo em portugues: %s\n", separarTexto(tituloPort));
        printf("Titulo original: %s\n", separarTexto(tituloOrig));
        printf("Autor: %s\n", separarTexto(autor));
        printf("Ano de lancamento: %d\n", ano);
        printf("Pais: %s\n", separarTexto(pais));
        printf("Nota: %s\n\n", separarTexto(nota));
    }

    fclose(livros);
}

void salvarRegistro(char* tituloPort, char* tituloOrig, char* autor, int ano, char* pais, char* nota){

    FILE* livros;
    FILE* chaves;
    FILE* contador;

    livros = fopen("livros.txt", "a");
    chaves = fopen("chaves.txt", "a");
    contador = fopen("contador.txt", "w");

    if(livros==NULL || chaves==NULL || contador==NULL){

        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }

    fprintf(livros, "%d %s %s %s %d %s %s\n", chave, unificarTexto(tituloPort), unificarTexto(tituloOrig), unificarTexto(autor), ano, unificarTexto(pais), unificarTexto(nota));

    fprintf(chaves, "%d\n", chave);

    fprintf(contador, "%d\n", chave);

    ++chave; // Incrementa a chave (para o próximo livro a ser inserido)
    
    fclose(livros);
    fclose(chaves);
    fclose(contador);
}

int lerContador(){

    FILE* contador;
    int cont;

    // Abre o arquivo que controla a criação das chaves:

    contador = fopen("contador.txt", "r");

    if(contador==NULL){

        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }

    // Verifica se o arquivo possui conteúdo:
 
    long int conteudo = 0;

    fseek(contador, 0L, SEEK_END); 
    conteudo = ftell(contador); 

    // Se o arquivo estiver vazio, a primeira chave a ser utilizada é a 1:

    if(conteudo==0) return 1;

    // Senão, realiza a leitura do conteúdo do arquivo, ou seja, da última chave utilizada:

    rewind(contador); // Retorna para o início do arquivo

    fscanf(contador, "%d", &cont);
    
    fclose(contador);

    // Retorna a próxima chave a ser utilizada na indexação do livro:

    return cont+1;
}

char* unificarTexto(char* texto){

    int i;

    for(i=0; i<strlen(texto); i++){

        if(texto[i]==' ') texto[i] = '+';
    }

    return texto;
}

char* separarTexto(char* texto){

    int i;

    for(i=0; i<strlen(texto); i++){

        if(texto[i]=='+') texto[i] = ' ';
    }

    return texto;
}

void pausar(){

    setbuf(stdin, NULL);

    char c;

    scanf("%c", &c);
}

/////////////////////////////////////////////// ÁRVORE B - TRABALHO //////////////////////////////////////////////////////

Pagina inserir(Registro reg, Pagina pag_raiz){ 

    int cresceu;
    Registro reg_retorno;
    Pagina pag_retorno, pag_temp;

    cresceu = inserir_recursivo(reg, pag_raiz, &reg_retorno, &pag_retorno);

    if (cresceu){

        pag_temp = (Pagina)malloc(sizeof(pagina));
        pag_temp->n = 1;
        pag_temp->registro[0] = reg_retorno;
        pag_temp->folha[1] = pag_retorno;
        pag_temp->folha[0] = pag_raiz;

        return pag_temp;
    }
    
    return pag_raiz;
}

void inserir_na_pagina(Pagina pag, Registro reg, Pagina pag_dir){ 

    int i;

    for (i=pag->n; (i > 0) && (reg.chave < pag->registro[i-1].chave); i--){

        pag->registro[i] = pag->registro[i-1];
        pag->folha[i+1] = pag->folha[i];    
    }

    pag->registro[i] = reg;
    pag->folha[i+1] = pag_dir;
    pag->n++;
} 

int inserir_recursivo(Registro reg, Pagina pag, Registro *reg_retorno, Pagina *pag_retorno){ 

    int cresceu;
    int j, i = 0;
    Pagina pag_temp;

    if (pag==NULL){ 

        *reg_retorno = reg; 
        *pag_retorno = NULL;

        return true;
    }
    
    while (i<pag->n && reg.chave>pag->registro[i].chave) {

        i++;
    }

    if (reg.chave==pag->registro[i].chave) { 

        printf("O registro ja esta presente!\n");

        return false; 
    }

    cresceu = inserir_recursivo(reg, pag->folha[i], reg_retorno, pag_retorno);

    if (!cresceu) {

        return false;
    }

    if (pag->n<MAXIMO){

        inserir_na_pagina(pag, *reg_retorno, *pag_retorno);

        return false;
    }

    pag_temp = (Pagina)malloc(sizeof(pagina));
    pag_temp->n = 0;  
    pag_temp->folha[0] = NULL;
    
    if (i<ORDEM+1){

        inserir_na_pagina(pag_temp, pag->registro[MAXIMO-1], pag->folha[MAXIMO]);//insere o �ltimo elemento em uma flha tempor�ria
        pag->n--;
        inserir_na_pagina(pag, *reg_retorno, *pag_retorno);
    } 
    else{

        inserir_na_pagina(pag_temp, *reg_retorno, *pag_retorno);
    }
        
    
    for (j=ORDEM+2; j<=MAXIMO; j++){

        inserir_na_pagina(pag_temp, pag->registro[j-1], pag->folha[j]);
    }        
    
    pag->n = ORDEM;  
    pag->folha[0] = pag->folha[ORDEM+1];
    *reg_retorno = pag->registro[ORDEM];
    *pag_retorno = pag_temp;

    return true;
}

Registro* pesquisar(int chave, Pagina a){ 

    int i=0;

    if (a==NULL) return NULL;

    while (i<a->n && chave>a->registro[i].chave){

        i++;
    }

    if (chave==a->registro[i].chave) {

        return &a->registro[i];
    }
  	
    if (chave<a->registro[i].chave){

        return (pesquisar(chave, a->folha[i]));
    }
    else{

        return (pesquisar(chave, a->folha[i+1]));
    }
}

/////////////////////////////////////////////// ÁRVORE B - LISIEUX //////////////////////////////////////////////////////

void menu(){

	int op, i;
	
    Registro valor;
	Pagina pagina = 0;
    
    do{

        printf("\n\t\t\t\tARVORE B - ORDEM 2\n");
        printf("\t1 - INSERIR ELEMENTO\n \t2  - IMPRIMIR ARVORE\n \t0  - SAIR");
        printf("\n\nINFORME SUA OPCAO: ");
        scanf("%d", &op);
        
        switch(op){

    		case 1: printf("\nInforme um elemento: ");
    			    scanf("%d", &valor.chave);

    			    pagina = inserir(valor, pagina);
                
				    break;
    			
    		case 2: imprimirArvore(pagina, 0); break;
        }

	}while(op!=0);
}

void imprimirArvore(Pagina p, int nivel){ 

    int i;

    if (p==NULL) return;

    printf("Nivel %d : ", nivel);

    for (i=0; i<p->n; i++){

        printf("%d ", p->registro[i].chave);
    }
        
    printf("\n");

    for (i=0; i<=p->n; i++){

        imprimirArvore(p->folha[i], nivel+1);
    }        
}

//////////////////////////////////////////////////// ÁRVORE B+  //////////////////////////////////////////////////////////