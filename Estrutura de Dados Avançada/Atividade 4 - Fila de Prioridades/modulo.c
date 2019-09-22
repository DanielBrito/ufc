#include"modulo.h"

Guiche* guiches; // Ponteiro referente à lista de guichês que irão atender os clientes.
Heap* preferencial; // Ponteiro referente à fila de clientes com necessidades especiais.
Heap* normal; // Ponteiro referente à fila de clientes normais.
int senhaSistema; // Variável que irá gerar as senhas que cada cliente irá receber.
int guichesAbertos; // Variável para armazenar a quantidade de guichês abertos durante o fluxo da execução.

// Exibição do menu principal:

void menuPrincipal(){

    int opcao;
    bool opInvalida = false;

    system("clear");

    printf("\t# MENU PRINCIPAL #\n\n");

    printf("1 - Abrir guiche\n");
    printf("2 - Fechar guiche\n");
    printf("3 - Nova senha\n");
    printf("4 - Atender cliente\n");
    printf("5 - Finalizar atendimento\n");
    printf("6 - Situacao dos guiches\n");
    printf("0 - Sair\n\n");

    do{

		printf("- > ");
		scanf("%d", &opcao);

		if(opcao<0 || opcao>6){
		
			printf("\nOpcao invalida!\n\n");
			
			opInvalida = true;
		}
		else{
			
			opInvalida = false;
		}

	}while(opInvalida==true);

    if(opcao==1){

        system("clear");

		printf("\t# ABRIR GUICHE #\n\n");

        abrirGuiche();

		subMenu();
    }
    else
    if(opcao==2){

        system("clear");

		printf("\t# FECHAR GUICHE #\n\n");

        fecharGuiche();

		subMenu();
    }
    else
    if(opcao==3){

        system("clear");

		printf("\t# GERAR NOVA SENHA #\n\n");

        gerarSenha();

		subMenu();
    }
    else
    if(opcao==4){

        system("clear");

		printf("\t# ATENDER CLIENTE #\n\n");

        atenderCliente();

		subMenu();
    }
    else
    if(opcao==5){

        system("clear");

		printf("\t# FINALIZAR ATENDIMENTO #\n\n");

        finalizarAtendimento();

		subMenu();
    }
    if(opcao==6){

        system("clear");

        printf("\t# SITUACAO DOS GUICHES #\n");

        situacaoGuiches();

		subMenu();
    }
    else{

        system("clear");

        finalizar();

		printf("Sistema encerrado.\n");

		exit(0);
    }
}

// Exibição do submenu após realizar alguma operação do menu principal:

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

        finalizar();

		printf("Sistema encerrado.\n");

		exit(0);
	}
}

// Abrir novo guichê para atendimento dos clientes:

void abrirGuiche(){

    int idGuiche;
    bool jaExiste=false;

    do{

        printf("Digite o numero do guiche: ");
        scanf("%d", &idGuiche);

        // Verifica se já existe um guichê com o número digitado:

        if(verificarExistenciaGuiche(idGuiche)==true){

            jaExiste = true;

            printf("\nJa existe um guiche com esta identificacao!\n\n");
        }
        else{

            jaExiste = false;
        }

    }while(jaExiste==true);

    guiches = inserir(guiches, idGuiche); // Insere o novo guichê na lista de guichês.
}

// Atualiza a lista de guichês com a inserção do novo guichê:

Guiche* inserir(Guiche* g, int id){

    Guiche* novoGuiche = (Guiche*)malloc(sizeof(Guiche)); // Aloca memória para a estrutura.

    // As informações do guichê criado são inicializadas:

    novoGuiche->id = id;
    novoGuiche->clienteAtendimento = NULL;
    novoGuiche->prox = g;

    ++guichesAbertos; // Atualiza o contador de guichês em funcionamento.

    printf("\nGuiche aberto com sucesso!\n");

    return novoGuiche; // Retorna a nova lista de guichês atualizada.
}

// Realiza a remoção de um determinado guichê:

void fecharGuiche(){

    if(guichesAbertos==0){

        printf("Nao existem guiches abertos para atendimento!\n");

        return;
    }

    int idGuiche;

    printf("Digite o numero do guiche: ");
    scanf("%d", &idGuiche);

    guiches = remover(guiches, idGuiche); // Busca pelo guichê e o remove, atualizando a lista (caso ele exista).
}

// Atualiza a lista com a remoção de um guichê que possui determinado id (caso ele exista):

Guiche* remover(Guiche* g, int id){

    // Ponteiros para auxiliar na manipulação dos nós:

	Guiche* anterior=NULL;
	Guiche* atual=g;

	// Percorre a lista até o final ou até que o guichê seja encontrado:

	while(atual!=NULL && atual->id!=id){

		anterior = atual;
		atual = atual->prox;
	}

	// O ponteiro 'atual' permaneceu no mesmo lugar ou recebeu uma lista nula:

	if(atual==NULL){

		printf("\nGuiche nao encontrado.\n");

		return g;
	}

	// Realiza a manipulação dos nós para remoção do guichê:

	if(anterior==NULL){

		g = atual->prox;
	}
	else{

		anterior->prox = atual->prox;
	}

	free(atual); // Libera a memória do nó que representa o guichê que foi fechado.

    --guichesAbertos; // Atualiza o contador de guichês em funcionamento.

	printf("\nGuiche fechado com sucesso!\n");

	return g; // Retorna a lista de guichês atualizada.
}

// Exibe a situação dos guichês após a realização de alguma ação:

void situacaoGuiches(){

    if(guichesAbertos==0){

        printf("\nNao existem guiches abertos para atendimento!\n");
    }
    else{

        Guiche* aux; // Ponteiro auxiliar para percorrer a lista de guichês.

        // Percorre a lista exibindo as informações de cada um dos guichês:

        for(aux=guiches; aux!=NULL; aux=aux->prox){

            // Se a identificação do guichê for 1, significa que trata-se do guichê preferencial:

            if(aux->id==GUICHE_PREFERENCIAL){

                printf("\nGUICHE #%d (PREFERENCIAL)\n", aux->id); // Identificação do guichê.

                // Verifica se existe algum cliente em atendimento no guichê:

                if(verificarAtendimentoGuiche(aux)==true){

                    exibirCliente(aux->clienteAtendimento); // Exibe as informações do cliente que está sendo atendido.
                }
                else{
                
                    printf("\nNenhum cliente em atendimento\n");
                }
            }

            // Caso contrário, trata-se de um guichê normal:

            else{

                printf("\nGUICHE #%d\n", aux->id); // Identificação do guichê.

                // Verifica se existe algum cliente em atendimento no guichê:

                if(verificarAtendimentoGuiche(aux)==true){

                    exibirCliente(aux->clienteAtendimento); // Exibe as informações do cliente que está sendo atendido.
                }
                else{
                
                    printf("\nNenhum cliente em atendimento\n");
                }              
            }
        }
    }

    // Exibe a situação da fila de clientes com necessidades especiais:

    printf("\n\n\t# FILA PREFERENCIAL # \n\n");

    mostrarHeap(preferencial);

    // Exibe a situação da fila de clientes normais:

    printf("\n\n\t# FILA NORMAl # \n\n");

    mostrarHeap(normal);
}

// Verifica a existência de um guichê com uma dada identificação:

bool verificarExistenciaGuiche(int id){

    Guiche* aux; // Ponteiro auxiliar para percorrer a lista de guichês.
    
    // Realiza o percorrimento da lista de guichês:

    for(aux=guiches; aux!=NULL; aux=aux->prox){

        // Verifica se o id do guichê é igual ao id recebido:

        if(aux->id==id){

            return true; // O guichê com id digitado existe.
        }
    }

    return false; // O guichê com o id digitado não existe.
}

// Retorna a referência para um guichê com determinada identificação:

Guiche* buscarGuiche(int id){

    Guiche* aux; // Ponteiro auxiliar para percorrer a lista de guichês.
    
    // Realiza o percorrimento da lista de guichês:

    for(aux=guiches; aux!=NULL; aux=aux->prox){

        // Verifica se o id do guichê é igual ao id recebido:

        if(aux->id==id){

            return aux; // O guichê com id digitado é retornado.
        }
    }

    return NULL; // O guichê com determinado id não possui referência.
}

// Verifica se existe algum cliente sendo atendido em um dado guichê:

bool verificarAtendimentoGuiche(Guiche* g){

    return g->clienteAtendimento!=NULL; // Se o cliente for diferente de NULL, o guichê está ocupado, logo, retorna 'true'.
}

// Inclui um novo cliente em uma determinada fila (preferencial ou normal):

void gerarSenha(){

    int tipo, prioridade;
    bool opInvalida=false;

    Cliente* cliente = (Cliente*)malloc(sizeof(Cliente)); // Aloca memória para armazenar as informações do cliente.

    // Seleciona o tipo de atendimento do cliente:

    printf("Tipo de atendimento:\n\n");
    printf("1 - Empresarial\n");
    printf("2 - Particular\n\n");

    do{

        printf("- > ");
        scanf("%d", &tipo);
        
        if(tipo<1 || tipo>2){
            
            printf("\nOpcao invalida!\n\n");
            
            opInvalida = true;
        }
        else{
            
            opInvalida = false;

            cliente->tipoAtendimento = tipo;
        }	

    }while(opInvalida==true);

    // Verifica se o cliente possui necessidades especiais:

    printf("\nPossui necessidades especiais?\n\n");
    printf("1 - Sim\n");
    printf("2 - Nao\n\n");

    do{

        printf("- > ");
        scanf("%d", &prioridade);
        
        if(prioridade<1 || prioridade>2){
            
            printf("\nOpcao invalida!\n\n");
            
            opInvalida = true;
        }
        else{
            
            opInvalida = false;

            cliente->necessidadeEspecial = (prioridade==1) ? true : false;
            cliente->codigoSenha = (prioridade==1) ? 'P' : 'N'; // P (Preferencial) e N (Normal)
        }	

    }while(opInvalida==true);

    cliente->senha = senhaSistema++; // Atribui ao cliente uma senha gerada pelo sistema.

    printf("\nNova senha: %d%c\n", cliente->senha, cliente->codigoSenha);

    // Verifica se o cliente é preferencial ou normal:

    if(cliente->necessidadeEspecial==true){

        // Verifica se a fila (heap) atingiu a capacidade máxima de armazenamento:

        if(heapCheia(preferencial)==true){

            printf("A capacidade maxima da fila foi atingida!\n");

            return;
        }
        else{

            inserirHeap(preferencial, cliente); // Adiciona o cliente na fila preferencial.  
        }
    }
    else{

        // Verifica se a fila (heap) atingiu a capacidade máxima de armazenamento:

        if(heapCheia(normal)==true){

            printf("A capacidade maxima da fila foi atingida.\n");

            return;
        }
        else{

            inserirHeap(normal, cliente); // Adiciona o cliente na fila preferencial.  
        }
    }
}

// Atende algum cliente (normal ou preferencial) em um determinado guichê:

void atenderCliente(){

    // Verifica a restrição do atendimento, onde a quantidade mínima de guichês abertos deve ser, no mínimo, 3:

    if(guichesAbertos<MIN_GUICHES){

        printf("E necessario que haja pelo menos 3 guiches abertos para atendimento!\n");

        return;
    }

    int idGuiche;
    Guiche* guicheAtendimento; // Referência para o guichê que irá realizar o atendimento (caso exista).

    printf("Digite o guiche que deseja atender um cliente: ");
    scanf("%d", &idGuiche);

    // Verifica se o guichê com a identificação recebida existe:

    if(verificarExistenciaGuiche(idGuiche)==true){

        guicheAtendimento = buscarGuiche(idGuiche); // Retorna a referência para guichê com id digitado.

        // Verifica se o guichê está realizando o atendimento de algum cliente:

        if(verificarAtendimentoGuiche(guicheAtendimento)==true){

            printf("\nJa existe um cliente sendo atendido por este guiche!\n");

            exibirCliente(guicheAtendimento->clienteAtendimento);
        }
        else{

            // Verifica se o guichê que irá realizar o atendimento é preferencial:

            if(guicheAtendimento->id==GUICHE_PREFERENCIAL){

                // Verifica a existência de clientes na fila preferencial:

                if(heapVazia(preferencial)==false){

                    // O atendimento do primeiro cliente da fila preferencial é iniciado:

                    guicheAtendimento->clienteAtendimento = retirarHeap(preferencial);

                    exibirCliente(guicheAtendimento->clienteAtendimento);
                }
                else

                // Não existem clientes preferenciais, logo, verifica-se a existência de clientes normais:

                if(heapVazia(normal)==false){

                    // O atendimento do primeiro cliente da fila normal é iniciado (no guichê preferencial):

                    guicheAtendimento->clienteAtendimento = retirarHeap(normal);

                    exibirCliente(guicheAtendimento->clienteAtendimento);
                }

                // Não existem clientes a serem atendidos, sejam preferenciais ou normais:

                else{

                    printf("\nNao existem clientes nas filas para serem atendidos!\n");
                }
            }

            // O guichê que irá realizar o atendimento é normal:

            else{

                // Verifica a existência de clientes na fila normal:

                if(heapVazia(normal)==false){

                    // O atendimento do primeiro cliente da fila normal é iniciado:

                    guicheAtendimento->clienteAtendimento = retirarHeap(normal);   

                    exibirCliente(guicheAtendimento->clienteAtendimento);  
                }
                else

                // Não existem clientes normais, logo, verifica-se a existência de clientes preferenciais:

                if(heapVazia(preferencial)==false){

                    // O atendimento do primeiro cliente da fila preferencial é iniciado (no guichê normal):

                    guicheAtendimento->clienteAtendimento = retirarHeap(preferencial);

                    exibirCliente(guicheAtendimento->clienteAtendimento);
                }

                // Não existem clientes a serem atendidos, sejam preferenciais ou normais:

                else{

                    printf("\nNao existem clientes nas filas para serem atendidos!\n");
                }
            }
        }
    }
    else{

        printf("\nNao existe guiche com esta indentificacao!\n");
    }
}

// Exibe as informações de um determinado cliente:

void exibirCliente(Cliente* c){

    printf("\nSenha do cliente: %d%c\n", c->senha, c->codigoSenha);
    printf("Tipo de atendimento: ");
    (c->tipoAtendimento==1) ? printf("Empresarial\n") : printf("Particular\n");
    printf("Necessidades especiais: ");
    (c->necessidadeEspecial==true) ? printf("Sim\n") : printf("Nao\n");
}

// Finaliza o atendimento do cliente em um determinado guichê:

void finalizarAtendimento(){

    if(guichesAbertos<MIN_GUICHES){

        printf("E necessario que haja pelo menos 3 guiches abertos para atendimento!\n");

        return;
    }

    int idGuiche;
    Guiche* guicheAtendimento; // Referência para o guichê que irá finalizar o atendimento (caso exista).

    printf("Digite o guiche que ira finalizar o atendimento: ");
    scanf("%d", &idGuiche);

    // Verifica se o guichê com a identificação recebida existe:

    if(verificarExistenciaGuiche(idGuiche)==true){

        guicheAtendimento = buscarGuiche(idGuiche); // Retorna a referência para guichê com id digitado.

        // Verifica se o guichê está realizando o atendimento de algum cliente:

        if(verificarAtendimentoGuiche(guicheAtendimento)==true){

            exibirCliente(guicheAtendimento->clienteAtendimento); // Exibe as informações do cliente que está sendo atendido.

            guicheAtendimento->clienteAtendimento = NULL; // Remove o cliente que estava sendo atendido pelo guichê.

            printf("\nAtendimento encerrado!\n");
        }
        else{

            printf("\nNenhum cliente esta sendo atendido por este guiche!\n");
        }
    }
    else{

        printf("\nNao existe guiche com esta indentificacao!\n");
    }
}

// Inicializa a estrutura de uma determinada fila (heap):

Heap* criarHeap(){

    Heap* h = (Heap*)malloc(sizeof(Heap)); // Aloca memória para armazenar a estrutura.

	h->qtdClientes=0; // Atribui a quantidade inicial de clientes na fila.

	return h; // Retorna a fila (heap) criada.
}

// Verifica se uma fila (heap) não possui clientes a serem atendidos:

bool heapVazia(Heap* h){

    return h->qtdClientes==0;
}

// Verifica se uma fila (heap) atingiu a sua capacidade máxima de clientes:

bool heapCheia(Heap* h){

    return h->qtdClientes==MAX_HEAP;
}

// Troca os elementos da fila (clientes) quando conveniente:

void trocarHeap(Heap* h, int i, int j){

    Cliente* temp = h->clientes[i];
	h->clientes[i] = h->clientes[j];
	h->clientes[j] = temp;
}

// Sobe um elemento (cliente) na heap (fila) quando conveniente:

void subirHeap(Heap* h, int i){

    int pai;

	while(i>0){
		
		pai = pai(i);

		if(h->clientes[pai]->senha <= h->clientes[i]->senha) break;

		trocarHeap(h, pai, i);

		i = pai;
	}
}

// Desce um elemento (cliente) na heap (fila) quando conveniente:

void descerHeap(Heap* h, int i){

    int filhoEsquerda = esq(i);
	int filhoDireita = dir(i);

	while(filhoEsquerda < h->qtdClientes){

		filhoDireita = dir(i);

		if((filhoDireita > h->qtdClientes) && (h->clientes[filhoDireita]->senha < h->clientes[filhoEsquerda]->senha)){

			filhoEsquerda = filhoDireita;
		}

		if(h->clientes[filhoEsquerda]->senha > h->clientes[i]->senha) break;

		trocarHeap(h, i, filhoEsquerda);

		i = filhoEsquerda;
		filhoEsquerda = esq(i);
	}
}

// Insere um novo elemento (cliente) na heap (fila) de acordo com sua senha:

void inserirHeap(Heap* h, Cliente* c){

    h->clientes[h->qtdClientes++] = c;

	subirHeap(h, h->qtdClientes-1);
}

// Remove um elemento (cliente) da heap (fila) após o seu atendimento:

Cliente* retirarHeap(Heap* h){

    Cliente* primeiroFila = h->clientes[0];

	h->clientes[0] = h->clientes[--h->qtdClientes];

	descerHeap(h, 0);

	return primeiroFila; // Retorna o primeiro cliente da fila, este que será atendido por um dos guichês.
}

// Exibe as informações de cada uma das filas (heaps):

void mostrarHeap(Heap* h){

    int i;

    printf("[INICIO] <- ");

	if(h->qtdClientes>0){

		for(i=0; i<h->qtdClientes; i++){

            printf("[%d%c] <- ", h->clientes[i]->senha, h->clientes[i]->codigoSenha);
        }

        printf("[FIM]\n");
	}
	else{
		
        printf("Fila vazia\n");
	}
}

// Inicializa as configurações iniciais do sistema:

void inicializar(){

    guichesAbertos = 0; // Quantidade de guichês abertos ao inicializar.

    guiches = NULL; // Lista de guichês que irão realizar os atendimentos.

    preferencial = criarHeap(); // Inicializa a fila que irá armazenar os clientes preferenciais.

    normal = criarHeap(); // Inicializa a fila que irá armazenar os clientes normais.

    senhaSistema = 1; // Primeira senha gerada pelo sistema.

    menuPrincipal();
}

// Libera a memória alocada para as filas (heaps):

void liberarHeap(Heap* h){

    int i;

    // Libera a memória de cada um dos clientes presentes na fila:

    for(i=0; i<h->qtdClientes; i++){

        free(h->clientes[i]);
    }

    free(h);
}

// Libera a memória alocada para um dos guichês:

void liberarGuiches(){

    Guiche* atual=guiches; // Ponteiro para auxiliar no percorrimento da lista.

	// Libera a memória de cada um dos nós que compõem a lista:

	while(atual!=NULL){

		Guiche* temp = atual->prox;

		free(atual);

		atual = temp;
	}
}

// Realiza a liberação da memória alocada durante a execução:

void finalizar(){

    liberarHeap(preferencial);
    liberarHeap(normal);
    liberarGuiches();
}