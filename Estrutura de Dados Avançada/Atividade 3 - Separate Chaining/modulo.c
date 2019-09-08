#include"modulo.h"

void inicializar(){

	int i;

	// Inicializa a lista de cada posição do vetor de registros com NULL:

	for(i=0; i<MAX; i++){

		registros[i] = NULL;
	}

	menuPrincipal();
}

void menuPrincipal(){

	int opcao;
	bool opInvalida;

	system("clear");
		
	printf("\t# MENU PRINCIPAL #\n\n");

	printf("1 - Remetente\n");
	printf("2 - Destinatario\n");
	printf("0 - Sair\n\n");

	do{

		printf("- > ");
		scanf("%d", &opcao);

		if(opcao<0 || opcao>2){
		
			printf("\nOpcao invalida!\n\n");
			
			opInvalida = true;
		}
		else{
			
			opInvalida = false;
		}

	}while(opInvalida==true);

	if(opcao==1){

		menuRemetente();
	}
	else
	if(opcao==2){

		menuDestinatario();			
	}
	else{

		system("clear");

		apagarRegistros();
	
		printf("Sistema encerrado.\n");

		exit(0);
	}
}

void menuRemetente(){

	int opcao, codigoMensagem;
	bool opInvalida;
	char mensagem[50], nomeRemetente[20], nomeDestinatario[20];

	system("clear");
		
	printf("\t# MENU - REMETENTE #\n\n");

	printf("1 - Enviar mensagem\n");
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

		system("clear");

		printf("\t# ENVIAR MENSAGEM #\n\n");

		printf("Digite o codigo da mensagem: ");
		scanf("%d", &codigoMensagem);

		printf("Digite o nome do remetente: ");
		scanf("%s", nomeRemetente);

		printf("Digite o nome do destinatario: ");
		scanf("%s", nomeDestinatario);

		printf("Digite a mensagem: ");
		scanf("%s", mensagem);

		enviarMensagem(codigoMensagem, nomeRemetente, nomeDestinatario, mensagem);

		subMenu();
	}
	else{

		system("clear");

		apagarRegistros();

		printf("Sistema encerrado.\n");

		exit(0);
	}
}

void menuDestinatario(){

	int opcao, codMensagem;
	bool opInvalida;
	char nomeDestinatario[20];

	system("clear");
		
	printf("\t# MENU - DESTINATARIO #\n\n");

	printf("1 - Buscar mensagem\n");
	printf("2 - Apagar mensagem\n");
	printf("0 - Sair\n\n");

	do{

		printf("- > ");
		scanf("%d", &opcao);

		if(opcao<0 || opcao>2){
		
			printf("\nOpcao invalida!\n\n");
			
			opInvalida = true;
		}
		else{
			
			opInvalida = false;
		}

	}while(opInvalida==true);		

	if(opcao==1){

		system("clear");

		printf("\t# BUSCAR MENSAGEM #\n\n");

		printf("Digite o codigo da mensagem: ");
		scanf("%d", &codMensagem);

		printf("Digite o nome do destinatario: ");
		scanf("%s", nomeDestinatario);

		buscarMensagem(codMensagem, nomeDestinatario);

		subMenu();
	}
	else
	if(opcao==2){

		system("clear");

		printf("\t# APAGAR MENSAGEM #\n\n");

		printf("Digite o codigo da mensagem: ");
		scanf("%d", &codMensagem);

		printf("Digite o nome do destinatario: ");
		scanf("%s", nomeDestinatario);

		buscarRemocao(codMensagem, nomeDestinatario);

		subMenu();
	}
	else{

		system("clear");

		apagarRegistros();

		printf("Sistema encerrado.\n");

		exit(0);
	}
}

void subMenu(){

	int opcao;
	bool opInvalida = false;
		
	printf("\n\nO que deseja fazer? \n\n");
	
	printf("1 - Menu Principal\n");
	printf("0 - Sair\n\n");

	do{

		printf("- > ");
		scanf("%d", &opcao);
		
		if(opcao<0 || opcao>2){
			
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

		apagarRegistros();

		printf("Sistema encerrado.\n");

		exit(0);
	}
}

void enviarMensagem(int codMensagem, char* nomeRemetente, char* nomeDestinatario, char* mensagem){

	int indexRegistro, criptoRemetente, criptoDestinatario;

	// Gera o index do vetor de registros onde será armazenada a nova mensagem:

	indexRegistro = hashCodigo(codMensagem);

	// Criptografa os dados do Remetente/Destinatario:

	criptoRemetente = hashNome(nomeRemetente);
	criptoDestinatario = hashNome(nomeDestinatario);

	// Insere a nova mensagem na lista do respectivo index gerado anteriormente:

	registros[indexRegistro] = inserirMensagem(registros[indexRegistro], codMensagem, criptoRemetente, criptoDestinatario, mensagem);
}

Lista* inserirMensagem(Lista* l, int codMensagem, int codRemetente, int codDestinatario, char* mensagem){

	// Aloca memória para o novo nó da lista que irá armazenar os dados da mensagem:

	Lista* novaMsg = (Lista*) malloc(sizeof(Lista));

	// Atribui os valores aos respectivos campos da mensagem:

	novaMsg->codigoMensagem = codMensagem;
	novaMsg->codigoRemetente = codRemetente;
	novaMsg->codigoDestinatario = codDestinatario;
	strcpy(novaMsg->mensagem, mensagem);

	// O novo nó criado aponta para o início da lista anterior:

	novaMsg->prox = l;

	// Retorna a lista atualizada:

	return novaMsg;
}

void buscarMensagem(int codMensagem, char* nomeDestinatario){

	int indexRegistro, criptoDestinario;

	// Flag para controlar a exibição do resultado da busca:

	bool encontrou = false;

	// Criptografa os dados da mensagem para pesquisa no vetor de registros:

	indexRegistro = hashCodigo(codMensagem);
	criptoDestinario = hashNome(nomeDestinatario);

	// Ponteiro auxiliar para percorrer a lista:

	Lista* aux;

	// Inicia o percorrimento da lista (a partir do primeiro nó):

	for(aux=registros[indexRegistro]; aux!=NULL; aux=aux->prox){

		// Compara o código do registro com o código criptografado baseado no nome do destinatário:

		if(aux->codigoDestinatario==criptoDestinario){

			printf("\nMensagem: %s\n", aux->mensagem);

			encontrou = true;
		}
	}

	if(encontrou==false){

		printf("\nNenhum registro encontrado.\n");
	}	
}

void buscarRemocao(int codMensagem, char* nomeDestinatario){

	int indexRegistro, criptoDestinatario;

	// Gera o index do vetor de registros que pode possuir a lista com a mensagem a ser excluída:

	indexRegistro = hashCodigo(codMensagem);
	criptoDestinatario = hashNome(nomeDestinatario);

	// Remove a mensagem da lista do respectivo index (se ela existir):

	registros[indexRegistro] = removerMensagem(registros[indexRegistro], criptoDestinatario);
}

Lista* removerMensagem(Lista* l, int codDestinatario){

	// Ponteiros para auxiliar na manipulação dos nós:

	Lista* anterior=NULL;
	Lista* atual=l;

	// Percorre a lista até o final ou até que o código do destinatário seja encontrado:

	while(atual!=NULL && atual->codigoDestinatario!=codDestinatario){

		anterior = atual;
		atual = atual->prox;
	}

	// O ponteiro 'atual' permaneceu no mesmo lugar ou recebeu uma lista nula:

	if(atual==NULL){

		printf("\nNenhum registro encontrado.\n");

		return l;
	}

	// Realiza a manipulação dos nós para remoção da mensagem que contém o código buscado:

	if(anterior==NULL){

		l = atual->prox;
	}
	else{

		anterior->prox = atual->prox;
	}

	// Libera a memória do nó que representa a mensagem que foi excluída:

	free(atual);

	printf("\nRegistro excluido com sucesso!\n");

	// Retorna a lista atualizada:

	return l;
}

void apagarRegistros(){

	int i;

	for(i=0; i<MAX; i++){

		// Libera a memória de cada uma das listas do vetor de registros:

		liberarLista(registros[i]);
	}
}

void liberarLista(Lista* l){

	Lista* atual=l;

	// Libera a memória de cada um dos nós que compõem a lista:

	while(atual!=NULL){

		Lista* temp = atual->prox;

		free(atual);

		atual = temp;
	}
}

int hashCodigo(int chave){

	// Hash simples para facilitar os testes:

	return (chave%MAX);
}

int hashNome(char* chave){

	int i, soma=0;

	for(i=0; i<strlen(chave); i++){

		// Realiza o somatório da representação decimal de cada caractere:

		soma += chave[i];
	}

	return soma;
}