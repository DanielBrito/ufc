#include"modulo.h"

// Método para inicializar as informações necessárias para o processo de reconstrução das mensagens:

void inicializar(){

    system("clear");

    // Método auxiliar utilizado apenas na primeira execução para geração dos identificadores dos pacotes:

    // gerarArquivos();

    lerArquivos();
}

// Método para agilizar o processo de geração dos arquivos com os indentificadores dos pacotes que compõem as mensagens:

void gerarArquivos(){

    int i;

    // Ponteiros para os arquivos que conterão os identificadores dos pacotes das respectivas mensagens:

    FILE* msgA, *msgB, *msgC;

    // Abre os arquivos para realização de escrita de dados:

    msgA = fopen("msgA.txt", "w");
    msgB = fopen("msgB.txt", "w");
    msgC = fopen("msgC.txt", "w");

    // Verifica se a leitura/criação dos arquivos ocorreu sem problemas:

    if(msgA==NULL || msgB==NULL || msgC==NULL){

        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }

    // Escrita dos identificadores (aleatórios) nos arquivos, juntamente com a identificação da respectiva mensagem:

    for(i=0; i<MAX_MSG_A; i++){

        fprintf(msgA, "%d%c\n", rand()%MAX_MSG_A+1, 'A');
    }

    for(i=0; i<MAX_MSG_B; i++){

        fprintf(msgB, "%d%c\n", rand()%MAX_MSG_B+1, 'B');
    }

    for(i=0; i<MAX_MSG_C; i++){

        fprintf(msgC, "%d%c\n", rand()%MAX_MSG_C+1, 'C');
    }

    // Observação:

    // Após a geração dos identificadores, é realizada a verificação/inserção dos valores que faltam manualmente.
    // Assim, eles obedecem a quantidade de pacotes de cada mensagem, ou seja, no intervalo [1..MAX_MSG_X]

    // Realiza o fechamento dos arquivos:
    
    fclose(msgA);
    fclose(msgB);
    fclose(msgC);
}

// Lê os identificadores dos pacotes dos arquivos, descartando réplicas, com o objetivo de reconstruir as mensagens:

void lerArquivos(){

    // Abre os arquivos para operações de leitura de dados:

    FILE* pacotesA = fopen("msgA.txt", "r");
    FILE* pacotesB = fopen("msgB.txt", "r");
    FILE* pacotesC = fopen("msgC.txt", "r");

    // Verifica se a leitura/criação dos arquivos ocorreu sem problemas:

    if(pacotesA==NULL || pacotesB==NULL || pacotesC==NULL){

        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }

    // Ponteiro para a estrutura que irá armazenar os pacotes para reconstrução das mensagens:

    Tno* mensagens = NULL;

    int idPacote;
    char idMensagem;

    // Realização da leitura dos arquivos e inserção das informações na estrutura:

    while(fscanf(pacotesA, "%d%c", &idPacote, &idMensagem)==2){

        mensagens = inserir(mensagens, idPacote, idMensagem);
	}

    while(fscanf(pacotesB, "%d%c", &idPacote, &idMensagem)==2){

        mensagens = inserir(mensagens, idPacote, idMensagem);
	}

    while(fscanf(pacotesC, "%d%c", &idPacote, &idMensagem)==2){

        mensagens = inserir(mensagens, idPacote, idMensagem);
	}

    // Realiza o fechamento dos arquivos:

    fclose(pacotesA);
    fclose(pacotesB);
    fclose(pacotesC);

    // Impressão (em-ordem) dos identificadores dos pacotes que compõem as respectivas mensagens:

    printf("Identificadores dos pacotes da mensagem A:\n\n");
    imprimir(mensagens, 'A');

    printf("\n\nIdentificadores dos pacotes da mensagem B:\n\n");
    imprimir(mensagens, 'B');

    printf("\n\nIdentificadores dos pacotes da mensagem C:\n\n");
    imprimir(mensagens, 'C');

    printf("\n\n");
}

// Verificar a altura da árvore:

int alturaAVL(Tno* a){

    int alturaEsq, alturaDir;

    if(a==NULL){

        return 0;
    }
    else{

        alturaEsq = alturaAVL(a->esq);
        alturaDir = alturaAVL(a->dir);

        return (alturaEsq>alturaDir) ? (1+alturaEsq) : (1+alturaDir);
    }
}

// Calcular fator de balanceamento:

int calcularFB(Tno* a){

    return (alturaAVL(a->esq) - alturaAVL(a->dir));
}

// Realizar rotação simples à esquerda:

Tno* rotacaoSimplesEsquerda(Tno* a){

    Tno *aux;

    aux = a->dir;
    a->dir = aux->esq;
    aux->esq = a;
    a = aux;

    return a;
}

// Realizar rotação simples à direita:

Tno* rotacaoSimplesDireita(Tno* a){

    Tno *aux;

    aux = a->esq;
    a->esq = aux->dir;
    aux->dir = a;
    a = aux;

    return a;
}

// Realizar rotação simples à direita ou rotação dupla (esquerda-direita) quando conveniente:

Tno* balanceioEsquerda(Tno* a){

    int fator = calcularFB(a->esq);

    if(fator>0){

        return rotacaoSimplesDireita(a);
    }
    else 
    if(fator<0){ 

        a->esq = rotacaoSimplesEsquerda(a->esq);
        a = rotacaoSimplesDireita(a);

        return a;	
    }
    else{

        return a;
    }
}

// Realizar rotação simples à esquerda ou rotação dupla (direita-esquerda) quando conveniente:

Tno* balanceioDireita(Tno* a){

    int fator = calcularFB(a->dir);

    if(fator<0){

        return rotacaoSimplesEsquerda(a);
    }
    else 
    if(fator>0)
    { 
        a->dir = rotacaoSimplesDireita(a->dir);
        a = rotacaoSimplesEsquerda(a); 

        return a;
    }
    else{

        return a;
    }
}

// Realizar o balanceamento da árvore:

Tno* balanceamento(Tno* a){

    int fator = calcularFB(a);

	if(fator>1){

        return balanceioEsquerda(a);
    }
	else 
    if(fator<(-1)){

        return balanceioDireita(a);
    }
    else{

        return a;
    }
}

// Inserir novo nó na árvore:

Tno* inserir(Tno* a, int idPacote, char idMensagem){

    if(a==NULL){

        a = (Tno *)malloc(sizeof(Tno));

        a->idPacote = idPacote;
        a->idMensagem = idMensagem;
        a->esq = NULL;
        a->dir = NULL;

        return a;
    }
    else 
  	if(a->idPacote>idPacote || (a->idPacote>=idPacote && a->idMensagem!=idMensagem)) {

    	a->esq = inserir(a->esq, idPacote, idMensagem);
    	a = balanceamento(a);
	}
    else
    if(a->idPacote<idPacote || (a->idPacote<=idPacote && a->idMensagem!=idMensagem)){

    	a->dir = inserir(a->dir, idPacote, idMensagem);
    	a = balanceamento(a);
	}

    return a;
}

// Realiza a impressão (em-ordem) dos identificadores dos pacotes de uma dada mensagem:

void imprimir(Tno* a, char idMensagem){

    if(a==NULL) return;

    imprimir(a->esq, idMensagem);

    if(a->idMensagem==idMensagem){

        printf("%d ", a->idPacote);
    }

    imprimir(a->dir, idMensagem);
}

// Função para liberar a memória dos nós da árvore utilizando o percorrimento pós-ordem:

void liberar(Tno* a){

    if(a==NULL) return;

    liberar(a->esq);
    liberar(a->dir);

    free(a);
}