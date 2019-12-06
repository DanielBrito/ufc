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

#define PORT 5000
#define N_THREADS 5
#define MAX_CLIENT 3
#define MAX_BUFFER 256

int semf = 0;

void *func_send(void *arg)
{
    int *newSocket = arg;
    printf("%d - thread executando...\n", *newSocket);
    while (1)
    {
        if (semf > 0)
        {

            char buffer[MAX_BUFFER];

            int socketNew = semf;
            semf = 0;

            while (1)
            {
                read(socketNew, buffer, sizeof(buffer));

                if (strcmp(buffer, "2") != 0)
                {
                    char buff[MAX_BUFFER];
                    printf("%s\n", "Server sends the hour!");
                    const time_t timer = time(NULL);
                    strcpy(buff, ctime(&timer));

                    send(socketNew, buff, sizeof(buff), 0); //envia as horas
                }
                else
                {
                    close(socketNew);
                    pthread_exit(NULL);
                }
            }
        }
    }
}

void *func_rec(void *arg)
{
    int *sockfd = arg;
    while (1)
    {
        struct sockaddr_in clientAddr;
        int tam = sizeof(clientAddr);
        int client_socked = accept(*sockfd, (struct sockaddr *)&clientAddr, &tam);
        if (client_socked < 0)
        {
            printf("Erro no Socket!\n");
            exit(1);
        }
        else
        {
            semf = client_socked;
            printf("Aguardando requisicoes...\n");
        }
    }
}

void main()
{
    int i;
    int sockfd;
    struct sockaddr_in serverAddr;

    if ((sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        printf("Erro socket...\n");
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
        printf("Erro no bind...\n");
        exit(0);
    }
    else
        printf(":) ...\n");

    if (listen(sockfd, MAX_CLIENT) < 0)
    {
        printf("Erro no listen...\n");
        exit(0);
    }

    pthread_t thread_rec;
    pthread_t thread_send[N_THREADS];
    int ind_thread_send[N_THREADS];

    pthread_create(&thread_rec, NULL, func_rec, (void *)&sockfd);

    for (i = 0; i < N_THREADS; i++)
    {
        ind_thread_send[i] = i + 1;
        pthread_create(&thread_send[i], NULL, func_send, (void *)&ind_thread_send[i]);
    }

    pthread_join(thread_rec, NULL);

    for (i = 0; i < N_THREADS; i++)
    {
        pthread_join(thread_send[i], NULL);
    }
}