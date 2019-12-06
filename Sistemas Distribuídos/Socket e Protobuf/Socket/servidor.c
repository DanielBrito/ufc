#include <netdb.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <pthread.h>
#include <stdbool.h>

#define PORT 5000
#define N_MAX_CLIENTS 5
#define MAX_BUFFER 1000

// Definição da estrutura que irá compor o sistema:

#define STR_LEN 100
#define TEL_LEN 15
#define TEL_UNI_LEN 15 * 50
int sock_cli; //socket cliente

pthread_mutex_t the_mutex;
pthread_cond_t condc, condp;
int cadeado = 0;

// Definição das estruturas que irão compor o sistema:

struct telefone
{
    char numero[TEL_UNI_LEN];
    struct telefone *prox;
};

typedef struct telefone Telefone;

struct contato
{
    char nome[STR_LEN]; // Obrigatório
    char endereco[STR_LEN];
    char email[STR_LEN];
    Telefone *telefones; // Obrigatório
    struct contato *prox;
};

typedef struct contato Contato;

char buffer[MAX_BUFFER]; //buffer shared
Contato *contatos;
char bufferNome[MAX_BUFFER];

//////////////////////

// Métodos para manipulação do arquivo de texto:

void inicializar();
void lerArquivo();
void salvarArquivo();

// Métodos para manipulação das listas (telefones e contatos) - CRUD (Create + Read + Update + Delete):

Contato *inserirContato(Contato *contatos, char *nome, char *endereco, char *email, char *telefones);
Contato *inserirContatoEntrada(Contato *contatos, char *nome, char *endereco, char *email, char *telefones);
Contato *procurarContato(char *nome);
Contato *removerContato(Contato *contatos, char *nome);

Telefone *inserirTelefone(Telefone *telefones, char *telefone);

void liberarLista();

// Métodos para controlar o fluxo das telas:

void menuPrincipal();
void subMenu();

char *opInserir();
char *opProcurar();
char *opAtualizar();
char *opRemover();

void imprimirContato(Contato *contato);
void imprimirTelefones(Telefone *telefones);
void imprimirContatos();

// Métodos para manipulação dos dados de entrada:

char *unificarTexto(char *texto);
char *separarTexto(char *texto);

Telefone *separarTelefones(char *telefones);
Telefone *separarTelefonesEntrada(char *telefones);

void lerArquivo()
{

    FILE *arquivo = fopen("contatos.txt", "r");

    char nome[STR_LEN], endereco[STR_LEN], email[STR_LEN], telefones[TEL_UNI_LEN];

    contatos = (Contato *)malloc(sizeof(Contato));

    contatos = NULL;

    if (arquivo == NULL)
    {

        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }
    else
    {

        while (fscanf(arquivo, "%s %s %s %s", nome, endereco, email, telefones) == 4)
        {

            contatos = inserirContato(contatos, strcpy(nome, separarTexto(nome)), strcpy(endereco, separarTexto(endereco)), strcpy(email, separarTexto(email)), telefones);
        }

        fclose(arquivo);
    }
}

void salvarArquivo()
{

    FILE *arquivo;

    arquivo = fopen("contatos.txt", "w");

    if (arquivo == NULL)
    {

        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }

    Contato *aux;

    for (aux = contatos; aux != NULL; aux = aux->prox)
    {

        char telefonesUnificados[TEL_UNI_LEN];

        int i, j = 0;
        Telefone *tel;

        for (tel = aux->telefones; tel->prox != NULL; tel = tel->prox)
        {

            for (i = 0; i < strlen(tel->numero); i++)
            {

                telefonesUnificados[j++] = tel->numero[i];
            }

            telefonesUnificados[j++] = '+';
        }

        telefonesUnificados[--j] = '\0';

        fprintf(arquivo, "%s %s %s %s\n", strcpy(aux->nome, unificarTexto(aux->nome)), strcpy(aux->endereco, unificarTexto(aux->endereco)), strcpy(aux->email, unificarTexto(aux->email)), telefonesUnificados);
    }

    fclose(arquivo);
}

Contato *inserirContato(Contato *contatos, char *nome, char *endereco, char *email, char *telefones)
{

    Contato *novoContato = (Contato *)malloc(sizeof(Contato));

    strcpy(novoContato->nome, nome);
    strcpy(novoContato->endereco, endereco);
    strcpy(novoContato->email, email);

    Telefone *listaTelefones = separarTelefones(telefones);

    novoContato->telefones = listaTelefones;

    novoContato->prox = contatos;

    return novoContato;
}

Contato *inserirContatoEntrada(Contato *contatos, char *nome, char *endereco, char *email, char *telefones)
{

    Contato *novoContato = (Contato *)malloc(sizeof(Contato));

    strcpy(novoContato->nome, nome);
    strcpy(novoContato->endereco, endereco);
    strcpy(novoContato->email, email);

    Telefone *listaTelefones = separarTelefonesEntrada(telefones);

    novoContato->telefones = listaTelefones;

    novoContato->prox = contatos;

    return novoContato;
}

Contato *procurarContato(char *nome)
{

    Contato *aux;

    for (aux = contatos; aux != NULL; aux = aux->prox)
    {

        if (strstr(aux->nome, nome) != NULL)
        {

            return aux;
        }
    }

    return NULL;
}

Contato *removerContato(Contato *contatos, char *nome)
{

    Contato *ant = NULL;
    Contato *aux = contatos;

    while (aux != NULL && strstr(aux->nome, nome) == NULL)
    {

        ant = aux;
        aux = aux->prox;
    }

    if (aux == NULL)
    {

        return contatos;
    }

    if (ant == NULL)
    {

        contatos = aux->prox;
    }
    else
    {

        ant->prox = aux->prox;
    }

    free(aux);

    return contatos;
}

void liberarLista()
{

    Contato *auxContato = contatos;

    while (auxContato != NULL)
    {

        Telefone *auxTelefone = auxContato->telefones;

        while (auxTelefone != NULL)
        {

            Telefone *tempT = auxTelefone->prox;

            free(tempT);

            auxTelefone = tempT;
        }

        Contato *tempC = auxContato->prox;

        free(tempC);

        auxContato = tempC;
    }
}

char *opInserir()
{

    system("clear");

    char nome[STR_LEN], endereco[STR_LEN], email[STR_LEN], telefone[TEL_UNI_LEN];
    char bufferTemp[MAX_BUFFER];

    strcpy(bufferTemp, buffer);

    // QUEBRANDO MENSAGEM;

    int i = 0, j;

    char *vet[MAX_BUFFER], vetAux[MAX_BUFFER + 1];
    char *strAux;

    strcpy(vetAux, bufferTemp);

    vetAux[strlen(vetAux)] = '\0';

    strAux = strtok(vetAux, "_");

    vet[i] = (char *)malloc(sizeof(char) * MAX_BUFFER);

    strcpy(vet[i], strAux);

    i++;

    do
    {

        strAux = strtok(NULL, "_");

        if (strAux != NULL)
        {

            vet[i] = (char *)malloc(sizeof(char) * MAX_BUFFER);

            strcpy(vet[i++], strAux);
        }

    } while (strAux != NULL);

    strcpy(nome, vet[1]);
    strcpy(endereco, vet[2]);
    strcpy(email, vet[3]);
    strcpy(telefone, vet[4]);

    //asdasd

    contatos = inserirContato(contatos, nome, endereco, email, telefone);

    return "\nContato criado com sucesso!\n";
}

char *opProcurar()
{

    system("clear");

    char *mensagem = (char *)malloc(sizeof(char) * 1000);

    char nome[STR_LEN], bufferTemp[MAX_BUFFER];
    Contato *contatoBuscado;

    int i = 0, j;

    char *vet[MAX_BUFFER], vetAux[MAX_BUFFER + 1];
    char *strAux;

    strcpy(bufferTemp, buffer);

    strcpy(vetAux, bufferTemp);

    vetAux[strlen(vetAux)] = '\0';

    strAux = strtok(vetAux, "_");

    vet[i] = (char *)malloc(sizeof(char) * MAX_BUFFER);

    strcpy(vet[i], strAux);

    i++;

    do
    {

        strAux = strtok(NULL, "_");

        if (strAux != NULL)
        {

            vet[i] = (char *)malloc(sizeof(char) * MAX_BUFFER);

            strcpy(vet[i++], strAux);
        }

    } while (strAux != NULL);

    strcpy(nome, vet[1]);

    int x;

    for (x = 0; x < strlen(nome); x++)
    {

        if (nome[x] == '+')
        {

            nome[x] = ' ';
        }
    }

    contatoBuscado = procurarContato(nome);

    if (contatoBuscado == NULL)
    {
        return "O contato nao foi encontrado!";
    }
    else
    {
        //imprimirContato(contatoBuscado);

        j = 0;
        i = 0;

        for (j = 0; j < strlen(contatoBuscado->nome); j++)
        {

            if (contatoBuscado->nome[j] == ' ')
            {

                mensagem[i++] = '+';
            }
            else
            {

                mensagem[i++] = contatoBuscado->nome[j];
            }
        }

        mensagem[i++] = '_';

        for (j = 0; j < strlen(contatoBuscado->endereco); j++)
        {

            if (contatoBuscado->endereco[j] == ' ')
            {

                mensagem[i++] = '+';
            }
            else
            {

                mensagem[i++] = contatoBuscado->endereco[j];
            }
        }

        mensagem[i++] = '_';

        for (j = 0; j < strlen(contatoBuscado->email); j++)
        {

            if (contatoBuscado->email[j] == ' ')
            {

                mensagem[i++] = '+';
            }
            else
            {

                mensagem[i++] = contatoBuscado->email[j];
            }
        }

        mensagem[i++] = '_';

        Telefone *aux;

        for (aux = contatoBuscado->telefones; aux != NULL; aux = aux->prox)
        {

            for (j = 0; j < strlen(aux->numero); j++)
            {

                mensagem[i++] = aux->numero[j];
            }

            mensagem[i++] = '+';
        }

        mensagem[i - 2] = '\0';

        printf("\nMENSAGEM A SER ENVIADA: %s\n", mensagem);

        return mensagem;
    }
}

char *opProcurarAtualizar()
{

    system("clear");

    char *mensagem = (char *)malloc(sizeof(char) * 1000);

    char nome[STR_LEN], bufferTemp[MAX_BUFFER];
    Contato *contatoBuscado;

    int i = 0, j;

    char *vet[MAX_BUFFER], vetAux[MAX_BUFFER + 1];
    char *strAux;

    strcpy(bufferTemp, buffer);

    strcpy(vetAux, bufferTemp);

    vetAux[strlen(vetAux)] = '\0';

    strAux = strtok(vetAux, "_");

    vet[i] = (char *)malloc(sizeof(char) * MAX_BUFFER);

    strcpy(vet[i], strAux);

    i++;

    do
    {

        strAux = strtok(NULL, "_");

        if (strAux != NULL)
        {

            vet[i] = (char *)malloc(sizeof(char) * MAX_BUFFER);

            strcpy(vet[i++], strAux);
        }

    } while (strAux != NULL);

    strcpy(nome, vet[1]);
    strcpy(bufferNome, vet[1]); // buffer auxiliar para armazenar o nome antigo do contato a ser atualizado

    int x;

    for (x = 0; x < strlen(nome); x++)
    {

        if (nome[x] == '+')
        {

            nome[x] = ' ';
        }
    }

    contatoBuscado = procurarContato(nome);

    if (contatoBuscado == NULL)
    {
        return "# O contato nao foi encontrado!";
    }
    else
    {

        j = 0;
        i = 0;

        mensagem[i++] = '@';
        mensagem[i++] = '_';

        for (j = 0; j < strlen(contatoBuscado->nome); j++)
        {

            if (contatoBuscado->nome[j] == ' ')
            {

                mensagem[i++] = '+';
            }
            else
            {

                mensagem[i++] = contatoBuscado->nome[j];
            }
        }

        mensagem[i++] = '_';

        for (j = 0; j < strlen(contatoBuscado->endereco); j++)
        {

            if (contatoBuscado->endereco[j] == ' ')
            {

                mensagem[i++] = '+';
            }
            else
            {

                mensagem[i++] = contatoBuscado->endereco[j];
            }
        }

        mensagem[i++] = '_';

        for (j = 0; j < strlen(contatoBuscado->email); j++)
        {

            if (contatoBuscado->email[j] == ' ')
            {

                mensagem[i++] = '+';
            }
            else
            {

                mensagem[i++] = contatoBuscado->email[j];
            }
        }

        mensagem[i++] = '_';

        Telefone *aux;

        for (aux = contatoBuscado->telefones; aux != NULL; aux = aux->prox)
        {

            for (j = 0; j < strlen(aux->numero); j++)
            {

                mensagem[i++] = aux->numero[j];
            }

            mensagem[i++] = '+';
        }

        mensagem[i - 2] = '\0';

        printf("\nMENSAGEM A SER ENVIADA: %s\n", mensagem);

        return mensagem;
    }
}

char *opAtualizar()
{

    system("clear");

    char nome[STR_LEN], endereco[STR_LEN], email[STR_LEN], telefone[TEL_UNI_LEN];
    char bufferTemp[MAX_BUFFER];

    strcpy(bufferTemp, buffer);

    // QUEBRANDO MENSAGEM;

    int i = 0, j;

    char *vet[MAX_BUFFER], vetAux[MAX_BUFFER + 1];
    char *strAux;

    strcpy(vetAux, bufferTemp);

    vetAux[strlen(vetAux)] = '\0';

    strAux = strtok(vetAux, "_");

    vet[i] = (char *)malloc(sizeof(char) * MAX_BUFFER);

    strcpy(vet[i], strAux);

    i++;

    do
    {

        strAux = strtok(NULL, "_");

        if (strAux != NULL)
        {

            vet[i] = (char *)malloc(sizeof(char) * MAX_BUFFER);

            strcpy(vet[i++], strAux);
        }

    } while (strAux != NULL);

    strcpy(nome, vet[1]);
    strcpy(endereco, vet[2]);
    strcpy(email, vet[3]);
    strcpy(telefone, vet[4]);

    Contato *aux;

    for (aux = contatos; aux != NULL; aux = aux->prox)
    {

        if (strstr(aux->nome, bufferNome) != NULL)
        {

            strcpy(aux->nome, nome);
            strcpy(aux->endereco, endereco);
            strcpy(aux->email, email);
            aux->telefones = separarTelefones(telefone);

            return "Contato atualizado com sucesso!";
        }
    }
    bzero(bufferNome, sizeof(bufferNome));
    return "O contato nao foi encontrado!";
}

char *opRemover()
{
    system("clear");

    char nome[MAX_BUFFER];
    char bufferTemp[MAX_BUFFER];
    Contato *contatoBuscado;

    strcpy(bufferTemp, buffer);

    // QUEBRANDO MENSAGEM:

    int i = 0, j;

    char *vet[MAX_BUFFER], vetAux[MAX_BUFFER + 1];
    char *strAux;

    strcpy(vetAux, bufferTemp);

    vetAux[strlen(vetAux)] = '\0';

    strAux = strtok(vetAux, "_");

    vet[i] = (char *)malloc(sizeof(char) * MAX_BUFFER);

    strcpy(vet[i], strAux);

    i++;

    do
    {

        strAux = strtok(NULL, "_");

        if (strAux != NULL)
        {

            vet[i] = (char *)malloc(sizeof(char) * MAX_BUFFER);

            strcpy(vet[i++], strAux);
        }

    } while (strAux != NULL);

    strcpy(nome, vet[1]);

    int x;

    for (x = 0; x < strlen(nome); x++)
    {

        if (nome[x] == '+')
        {

            nome[x] = ' ';
        }
    }

    contatoBuscado = procurarContato(nome);

    if (contatoBuscado == NULL)
    {

        return "O contato nao foi encontrado!";
    }
    else
    {

        contatos = removerContato(contatos, nome);

        return "Contato removido com sucesso!";
    }
}

void imprimirContato(Contato *contato)
{

    printf("\nNome: %s\n", contato->nome);
    printf("Endereco: %s\n", contato->endereco);
    printf("Email: %s\n", contato->email);
    printf("Telefone: ");
    imprimirTelefones(contato->telefones);

    printf("\n");
}

void *func_send(void *arg) //Thread envia/recebe do servidor
{
    int sockEntrada = *(int *)arg;
    int i;

    for (i = 1; i <= 10000000; i++)
    {
        pthread_mutex_lock(&the_mutex);
        while (cadeado == 0)
            pthread_cond_wait(&condc, &the_mutex);
        cadeado = 0;

        char buff[MAX_BUFFER]; // reponder o client

        contatos = (Contato *)malloc(sizeof(Contato));

        lerArquivo();

        printf("FUNCAO_SEND: %s\n", buffer);

        char op = buffer[0];

        if (op == '1') //CREATE
        {
            opInserir();
            salvarArquivo();
            strcpy(buff, "Cadastro realizado com sucesso!\n");
            send(sockEntrada, buff, sizeof(buff), 0);
        }
        else if (op == '2') // READ
        {
            printf("Estou no READ :D");
            strcpy(buff, opProcurar());

            // Formatando mensagem de resposta:

            char nome[STR_LEN], endereco[STR_LEN], email[STR_LEN], telefone[TEL_UNI_LEN];
            char bufferTemp[MAX_BUFFER];

            strcpy(bufferTemp, buff);

            // QUEBRANDO MENSAGEM;

            int i = 0, j;

            char *vet[MAX_BUFFER], vetAux[MAX_BUFFER + 1];
            char *strAux;

            strcpy(vetAux, bufferTemp);

            vetAux[strlen(vetAux)] = '\0';

            strAux = strtok(vetAux, "_");

            vet[i] = (char *)malloc(sizeof(char) * MAX_BUFFER);

            strcpy(vet[i], strAux);

            i++;

            do
            {

                strAux = strtok(NULL, "_");

                if (strAux != NULL)
                {

                    vet[i] = (char *)malloc(sizeof(char) * MAX_BUFFER);

                    strcpy(vet[i++], strAux);
                }

            } while (strAux != NULL);

            char resposta[MAX_BUFFER];

            sprintf(resposta, "\n\nNome: %s\nEndereco: %s\nEmail: %s\nTelefones: %s\n", vet[0], vet[1], vet[2], vet[3]);

            // Removendo +:

            int x;

            for (x = 0; x < strlen(resposta); x++)
            {

                if (resposta[x] == '+')
                {

                    resposta[x] = ' ';
                }
            }

            send(sockEntrada, resposta, sizeof(resposta), 0);
            bzero(buffer, sizeof(buffer));
        }
        else if (op == '3') // UPDATE
        {
            printf("Estou no UPDATE :D");
            strcpy(buff, opProcurarAtualizar());

            if (buff[0] == '@')
            {
                // Formatando mensagem de resposta:

                char nome[STR_LEN], endereco[STR_LEN], email[STR_LEN], telefone[TEL_UNI_LEN];
                char bufferTemp[MAX_BUFFER];

                strcpy(bufferTemp, buff);

                // QUEBRANDO MENSAGEM;

                int i = 0, j;

                char *vet[MAX_BUFFER], vetAux[MAX_BUFFER + 1];
                char *strAux;

                strcpy(vetAux, bufferTemp);

                vetAux[strlen(vetAux)] = '\0';

                strAux = strtok(vetAux, "_");

                vet[i] = (char *)malloc(sizeof(char) * MAX_BUFFER);

                strcpy(vet[i], strAux);

                i++;

                do
                {

                    strAux = strtok(NULL, "_");

                    if (strAux != NULL)
                    {

                        vet[i] = (char *)malloc(sizeof(char) * MAX_BUFFER);

                        strcpy(vet[i++], strAux);
                    }

                } while (strAux != NULL);

                char resposta[MAX_BUFFER];

                sprintf(resposta, "@\n\nNome: %s\nEndereco: %s\nEmail: %s\nTelefones: %s\n", vet[1], vet[2], vet[3], vet[4]);

                // Removendo +:

                int x;

                for (x = 0; x < strlen(resposta); x++)
                {

                    if (resposta[x] == '+')
                    {

                        resposta[x] = ' ';
                    }
                }
                printf("Vou mandar para cliente: %s\n", buff);
                salvarArquivo();
                send(sockEntrada, resposta, sizeof(resposta), 0);
            }
            else
            {
                printf("Vou mandar para cliente: %s\n", buff);
                salvarArquivo();
                send(sockEntrada, buff, sizeof(buff), 0);
            }
        }
        else if (op == '4') // DELETE
        {
            strcpy(buff, opRemover());
            salvarArquivo();
            send(sockEntrada, buff, sizeof(buff), 0);
        }
        else if (op == '5') // UPDATE PARTE 2
        {
            printf("Estou no UPDATE PARTE 2 :]");

            strcpy(buff, opAtualizar());
            printf("Vou mandar para cliente: %s\n", buff);

            //imprimirContatos();
            //sleep(5);
            salvarArquivo();
            send(sockEntrada, buff, sizeof(buff), 0);
        }
        else
        {
            printf("\nEncerrou a conexao!\n");
            //close(sockEntrada);
        }

        bzero(buff, MAX_BUFFER);
        bzero(buffer, MAX_BUFFER);

        pthread_cond_signal(&condp);
        pthread_mutex_unlock(&the_mutex);
    }
    pthread_exit(0);
}

void *func_rec(void *arg)
{
    int i;
    int *sockfd = arg;
    printf("%d - Thread_rec esta executando...\n", *sockfd);
    for (i = 1; i <= 100000000; i++)
    {
        pthread_mutex_lock(&the_mutex);
        while (cadeado != 0)
            pthread_cond_wait(&condp, &the_mutex);
        cadeado = i;

        bzero(buffer, sizeof(buffer));
        printf("\nAguardando dados do cliente...\n");
        read(*sockfd, buffer, sizeof(buffer));
        if (strlen(buffer) == 0)
        {
            close(*sockfd);
            exit(1);
        }
        printf("Recebido do cliente : %s\n", buffer);

        pthread_cond_signal(&condc);
        pthread_mutex_unlock(&the_mutex);
    }
    pthread_exit(0);
}

void main()
{

    pthread_t thread_rec, thread_send;
    struct sockaddr_in serverAddr;
    int sockfd;
    if ((sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        printf("Erro no Socket!\n");
        exit(1);
    }
    else
        printf("Socket criado com sucesso\n");

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
        printf("Erro no bind.\n");
        exit(1);
    }
    else
        printf(":) ...\n");

    printf("Aguardando requisicao...\n");
    if (listen(sockfd, N_MAX_CLIENTS) < 0)
    {
        printf("Erro no Socket!\n");
        exit(1);
    }

    struct sockaddr_in clientAddr;
    int cli_len = sizeof(clientAddr);
    int client_socked = accept(sockfd, (struct sockaddr *)&clientAddr, &cli_len);
    sock_cli = client_socked;

    pthread_mutex_init(&the_mutex, 0);
    pthread_cond_init(&condc, 0);
    pthread_cond_init(&condp, 0);

    pthread_create(&thread_rec, NULL, func_rec, (void *)&client_socked);
    pthread_create(&thread_send, NULL, func_send, (void *)&client_socked);

    pthread_join(thread_rec, 0);
    pthread_join(thread_send, 0);
    pthread_cond_destroy(&condc);
    pthread_cond_destroy(&condp);
    pthread_mutex_destroy(&the_mutex);
}

void imprimirContatos()
{
    Contato *aux;
    printf("\nCONTATOS DO ARQUIVO\n");
    for (aux = contatos; aux != NULL; aux = aux->prox)
    {
        imprimirContato(aux);
    }
}

void imprimirTelefones(Telefone *telefones)
{
    Telefone *aux;
    for (aux = telefones; aux->prox != NULL; aux = aux->prox)
    {
        printf("%s ", aux->numero);
    }
}

char *unificarTexto(char *texto)
{
    int i;
    for (i = 0; i < strlen(texto); i++)
    {
        if (texto[i] == ' ')
        {
            texto[i] = '+';
        }
    }
    return texto;
}

char *separarTexto(char *texto)
{
    int i;
    for (i = 0; i < strlen(texto); i++)
    {
        if (texto[i] == '+')
        {
            texto[i] = ' ';
        }
    }

    return texto;
}

Telefone *separarTelefones(char *telefones)
{

    Telefone *listaTelefones = (Telefone *)malloc(sizeof(Telefone));

    int i = 0, j;

    char *vet[TEL_UNI_LEN], vetAux[TEL_UNI_LEN + 1];
    char *strAux;

    strcpy(vetAux, telefones);

    vetAux[strlen(vetAux)] = '\0';

    strAux = strtok(vetAux, "+");

    vet[i] = (char *)malloc(sizeof(char) * TEL_UNI_LEN);

    strcpy(vet[i], strAux);

    i++;

    do
    {

        strAux = strtok(NULL, "+");

        if (strAux != NULL)
        {

            vet[i] = (char *)malloc(sizeof(char) * TEL_UNI_LEN);

            strcpy(vet[i++], strAux);
        }

    } while (strAux != NULL);

    for (j = 0; j < i; j++)
    {

        listaTelefones = inserirTelefone(listaTelefones, vet[j]);
    }

    return listaTelefones;
}

Telefone *separarTelefonesEntrada(char *telefones)
{

    Telefone *listaTelefones = (Telefone *)malloc(sizeof(Telefone));

    int i = 0, j;

    char *vet[TEL_UNI_LEN], vetAux[TEL_UNI_LEN + 1];
    char *strAux;

    strcpy(vetAux, telefones);

    vetAux[strlen(vetAux)] = '\0';

    strAux = strtok(vetAux, " ");

    vet[i] = (char *)malloc(sizeof(char) * TEL_UNI_LEN);

    strcpy(vet[i], strAux);

    i++;

    do
    {

        strAux = strtok(NULL, " ");

        if (strAux != NULL)
        {

            vet[i] = (char *)malloc(sizeof(char) * TEL_UNI_LEN);

            strcpy(vet[i++], strAux);
        }

    } while (strAux != NULL);

    for (j = 0; j < i; j++)
    {

        listaTelefones = inserirTelefone(listaTelefones, vet[j]);
    }

    return listaTelefones;
}

Telefone *inserirTelefone(Telefone *telefones, char *telefone)
{

    Telefone *novoTelefone = (Telefone *)malloc(sizeof(Telefone));

    strcpy(novoTelefone->numero, telefone);
    novoTelefone->prox = telefones;

    return novoTelefone;
}