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

#define STR_LEN 100
#define TEL_LEN 15
#define TEL_UNI_LEN 15 * 50

#define MAX 100000000
#define PORT 5000       //porta de de acessso
#define MAX_BUFFER 1000 //tamanho max do buffer

pthread_mutex_t the_mutex;
pthread_cond_t condc, condp;
int cadeado = 0;

char buffer[MAX_BUFFER]; //intermediador entre threads.
char buff[MAX_BUFFER];   //novo vetor para receber resposta do server
char op[1];
int trava = 0; //logica para o UPDATE

char *resposta(char *mensagem);

void *func_rec()
{
    int i;
    for (i = 1; i <= MAX; i++)
    {
        pthread_mutex_lock(&the_mutex);
        while (cadeado != 0)
            pthread_cond_wait(&condp, &the_mutex);
        cadeado = i;

        if (trava == 0)
        {
            printf("\t# MENU PRINCIPAL #\n\n");
            printf("1 - Novo contato\n");
            printf("2 - Procurar contato\n");
            printf("3 - Atualizar contato\n");
            printf("4 - Remover contato\n");
            printf("0 - Sair\n\n");
            printf("-> ");

            scanf("%s", op);
            setbuf(stdin, NULL);
        }
        else if (trava == 1)
        {
            op[0] = '3';
        }

        if (strcmp(op, "1") == 0)
        {
            system("clear");

            char mensagem[1000];
            int i = 0, j;

            mensagem[i++] = '1';
            mensagem[i++] = '_';

            char nome[STR_LEN], endereco[STR_LEN], email[STR_LEN], telefone[TEL_UNI_LEN];

            printf("\t # NOVO CONTATO (* Campo obrigatório) #\n\n");
            printf("* Digite o nome: ");
            scanf("%[^\n]s", nome);
            

            for (j = 0; j < strlen(nome); j++)
            {
                if (nome[j] == ' ')
                {
                    mensagem[i++] = '+';
                }
                else
                {
                    mensagem[i++] = nome[j];
                }
            }

            mensagem[i++] = '_';
            setbuf(stdin, NULL);

            printf("\n  Digite o endereco: ");
            scanf("%[^\n]s", endereco);

            for (j = 0; j < strlen(endereco); j++)
            {
                if (endereco[j] == ' ')
                {
                    mensagem[i++] = '+';
                }
                else
                {
                    mensagem[i++] = endereco[j];
                }
            }

            mensagem[i++] = '_';
            setbuf(stdin, NULL);

            printf("\n  Digite o email: ");
            scanf("%[^\n]s", email);

            for (j = 0; j < strlen(email); j++)
            {
                if (email[j] == ' ')
                {
                    mensagem[i++] = '+';
                }
                else
                {
                    mensagem[i++] = email[j];
                }
            }

            mensagem[i++] = '_';
            setbuf(stdin, NULL);

            printf("\n* Digite o telefone: ");
            scanf("%[^\n]s", telefone);

            for (j = 0; j < strlen(telefone); j++)
            {

                if (telefone[j] == ' ')
                {
                    mensagem[i++] = '+';
                }
                else
                {
                    mensagem[i++] = telefone[j];
                }
            }

            mensagem[i] = '\0';
            strcpy(buffer, mensagem);

            setbuf(stdin, NULL);

            bzero(mensagem, sizeof(mensagem));
            bzero(nome, sizeof(nome));
            bzero(endereco, sizeof(endereco));
            bzero(email, sizeof(email));
            bzero(telefone, sizeof(telefone));
        }
        else if (strcmp(op, "2") == 0) //READ
        {
            bzero(buffer, sizeof(buffer));
            system("clear");

            char nome[STR_LEN];
            char mensagem[1000];
            int i = 0, j;

            mensagem[i++] = '2';
            mensagem[i++] = '_';

            printf("\t # PROCURAR CONTATO #\n\n");

            printf("Digite o nome do contato a ser buscado: ");
            scanf("%[^\n]s", nome);
            //scanf("%s", nome);

            for (j = 0; j < strlen(nome); j++)
            {
                if (nome[j] == ' ')
                {
                    mensagem[i++] = '+';
                }
                else
                {
                    mensagem[i++] = nome[j];
                }
            }
            mensagem[i] = '\0';

            strcpy(buffer, mensagem);
            setbuf(stdin, NULL);
        }
        else if (strcmp(op, "3") == 0)
        {
            if (trava == 0)
            {
                system("clear");

                char nome[STR_LEN];

                char mensagem[1000];
                int i = 0, j;

                mensagem[i++] = '3';
                mensagem[i++] = '_';

                printf("\t # ATUALIZAR CONTATO #\n\n");

                printf("Digite o nome do contato a ser atualizado: ");
                scanf("%[^\n]s", nome);

                for (j = 0; j < strlen(nome); j++)
                {

                    if (nome[j] == ' ')
                    {

                        mensagem[i++] = '+';
                    }
                    else
                    {

                        mensagem[i++] = nome[j];
                    }
                }

                mensagem[i] = '\0';

                strcpy(buffer, mensagem);

                setbuf(stdin, NULL);
                trava = 1;
            }
            else if (trava == 1)
            {
                
                
                if (buff[0] == '#') // APÓS A RESPOSTA DO SERVIDOR:
                {
                    printf("%s\n", buff);
                    trava = 3;
                }
                else if (buff[0] == '@')
                {
                    char mensagem[1000];
                    int i = 0, j;

                    mensagem[i++] = '5';
                    mensagem[i++] = '_';

                    char nome[STR_LEN], endereco[STR_LEN], email[STR_LEN], telefone[TEL_UNI_LEN];
                    printf("\nCOM BASE NOS DADOS MOSTRADOS, EDITE OS CAMPOS QUE DESESJA\n");
                    printf("\t # ATUALIZAR CONTATO (* Campo obrigatório) #\n\n");

                    printf("* Digite o nome: ");
                    scanf("%[^\n]s", nome);

                    for (j = 0; j < strlen(nome); j++)
                    {

                        if (nome[j] == ' ')
                        {

                            mensagem[i++] = '+';
                        }
                        else
                        {

                            mensagem[i++] = nome[j];
                        }
                    }

                    mensagem[i++] = '_';

                    setbuf(stdin, NULL);

                    printf("\n  Digite o endereco: ");
                    scanf("%[^\n]s", endereco);

                    for (j = 0; j < strlen(endereco); j++)
                    {

                        if (endereco[j] == ' ')
                        {

                            mensagem[i++] = '+';
                        }
                        else
                        {

                            mensagem[i++] = endereco[j];
                        }
                    }

                    mensagem[i++] = '_';

                    setbuf(stdin, NULL);

                    printf("\n  Digite o email: ");
                    scanf("%[^\n]s", email);

                    for (j = 0; j < strlen(email); j++)
                    {

                        if (email[j] == ' ')
                        {

                            mensagem[i++] = '+';
                        }
                        else
                        {

                            mensagem[i++] = email[j];
                        }
                    }

                    mensagem[i++] = '_';

                    setbuf(stdin, NULL);

                    printf("\n* Digite o telefone: ");
                    scanf("%[^\n]s", telefone);

                    for (j = 0; j < strlen(telefone); j++)
                    {

                        if (telefone[j] == ' ')
                        {

                            mensagem[i++] = '+';
                        }
                        else
                        {

                            mensagem[i++] = telefone[j];
                        }
                    }

                    mensagem[i] = '\0';

                    strcpy(buffer, mensagem);

                    trava = 2;

                    printf("\nEnviar para o servidor buffer: %s\n", buffer);
                    bzero(buff, sizeof(buff));
                    setbuf(stdin, NULL);
                }
                
                bzero(buff, sizeof(buff));
            }
        }
        else if (strcmp(op, "4") == 0)
        {

            system("clear");

            char nome[STR_LEN];
            char mensagem[1000];
            int i = 0, j; // asdasd

            mensagem[i++] = '4';
            mensagem[i++] = '_';

            printf("\t # REMOVER CONTATO #\n\n");

            printf("Digite o nome do contato a ser removido: ");
            scanf("%[^\n]s", nome);

            for (j = 0; j < strlen(nome); j++)
            {

                if (nome[j] == ' ')
                {

                    mensagem[i++] = '+';
                }
                else
                {

                    mensagem[i++] = nome[j];
                }
            }

            mensagem[i] = '\0';

            strcpy(buffer, mensagem);
            setbuf(stdin, NULL);
        }
        else if (strcmp(op, "0") == 0)
        {
            exit(1);
        }

        pthread_cond_signal(&condc);
        pthread_mutex_unlock(&the_mutex);
    }
}

void *func_send(void *arg)
{
    int *sockfd = arg;
    int i;
    for (i = 1; i <= MAX; i++)
    {
        pthread_mutex_lock(&the_mutex);
        while (cadeado == 0)
            pthread_cond_wait(&condc, &the_mutex);
        cadeado = 0;

        if (trava == 2)
        {
            printf("\nEnviando para o server: %s\n", buffer);
            send(*sockfd, buffer, sizeof(buffer), 0);
            bzero(buffer, sizeof(buffer)); //zero buffer_shared

            read(*sockfd, buff, sizeof(buff));
            printf("\nServidor respondeu: %s\n", buff);
            trava = 0;
        }
        else if (trava == 3)
        {
            trava = 0;
            bzero(buff, sizeof(buff));
        }
        else
        {

            printf("\nEnviando para o server: %s\n", buffer);
            send(*sockfd, buffer, sizeof(buffer), 0);
            bzero(buffer, sizeof(buffer)); //zero buffer_shared

            read(*sockfd, buff, sizeof(buff));

            printf("\nServidor respondeu: %s\n", buff);
        }

        pthread_cond_signal(&condp);
        pthread_mutex_unlock(&the_mutex);
    }
}

void main()
{
    pthread_t thread_rec, thread_send;
    struct sockaddr_in serv_addr;
    socklen_t addrlen = sizeof(serv_addr);

    int sockfd;
    sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0)
    {
        printf("Erro no Socket\n");
        exit(1);
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, addrlen) < 0)
    {
        printf("Error\n");
        exit(1);
    }

    pthread_mutex_init(&the_mutex, 0);
    pthread_cond_init(&condc, 0);
    pthread_cond_init(&condp, 0);

    pthread_create(&thread_rec, NULL, func_rec, NULL);
    pthread_create(&thread_send, NULL, func_send, (void *)&sockfd);

    pthread_join(thread_rec, 0);
    pthread_join(thread_send, 0);
    pthread_cond_destroy(&condc);
    pthread_cond_destroy(&condp);
    pthread_mutex_destroy(&the_mutex);
}