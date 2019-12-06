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
#define N_MAX_CLIENTS 5
#define MAX_BUFFER 256

char buffer[MAX_BUFFER];

void *func_send(void *arg)
{
    int sockEntrada = *(int *)arg;
    char buff[MAX_BUFFER];
    while (1)
    {
        read(sockEntrada, buffer, sizeof(buffer));
        if (strcmp(buffer, "2") != 0)
        {
            printf("%s\n", "Server sends the hour!");
            const time_t timer = time(NULL);
            strcpy(buff, ctime(&timer));

            send(sockEntrada, buff, sizeof(buff), 0);
        }
        else
        {

            close(sockEntrada);
            pthread_exit((void *)0);
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

        pthread_t tHoras;

        int cSocked = accept(*sockfd, (struct sockaddr *)&clientAddr, &tam);
        if (cSocked < 0)
        {
            printf("Erro no Socket!\n");
            exit(0);
        }
        //read(cSocked, buffer, sizeof(buffer));
        if (pthread_create(&tHoras, NULL, func_send, &cSocked) != 0)
        {
            printf("Erro na criacao da thread tHoras.\n");
            exit(0);
        }
        pthread_detach(tHoras);
    }
}

void main()
{
    pthread_t thread_receber;
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

    pthread_create(&thread_receber, NULL, func_rec, (void *)&sockfd);
    pthread_join(thread_receber, NULL);
}