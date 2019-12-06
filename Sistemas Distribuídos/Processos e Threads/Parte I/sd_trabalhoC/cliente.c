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
#define MAX_BUFFER 256
char buffer[MAX_BUFFER];

void *func_rec(void *arg)
{
    printf("1 - Fazer requisicao das horas.\n");
    printf("2 - Encerrar.\n");

    scanf("%s", buffer);
    fflush(stdin);

    while (strcmp(buffer, "2") != 0)
    {
        printf("1 - Fazer requisicao das horas.\n");
        printf("2 - Encerrar.\n");
        scanf("%s", buffer);
        fflush(stdin);
    }
}

void *func_send(void *arg)
{
    int *sockfd = arg;
    while (1)
    {
        if (strcmp(buffer, "1") == 0)
        {
            send(*sockfd, buffer, sizeof(buffer), 0);
            char buff[MAX_BUFFER];
            read(*sockfd, buff, sizeof(buff));

            printf("From server - %s\n", buff);

            strcpy(buffer, "");
        }
        else if (strcmp(buffer, "2") == 0)
        {
            close(*sockfd);
            break;
        }
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

    pthread_create(&thread_rec, NULL, func_rec, NULL);
    pthread_create(&thread_send, NULL, func_send, (void *)&sockfd);

    pthread_join(thread_rec, NULL);
    pthread_join(thread_send, NULL);
}