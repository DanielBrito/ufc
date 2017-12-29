#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void funcao_a(int num[]);
void funcao_b(int num[]);
void funcao_c(int num[]);
void funcao_d(int num[]);
void funcao_e(int num[]);
int funcao_f(int num[]);
int funcao_g(int num[]);
float funcao_h(int num[]);
void funcao_i(int num[]);
void funcao_j(int num[]);
void funcao_k(int num[]);

int main()
{
    int num[7]={9, 6, 13, 3, 14, 22, 7};
    int maior_num=0, menor_num=0;
    float media_vetor=0;

    printf("             * FUNDAMENTOS DE PROGRAMACAO - LISTA 7 *\n\n");
    printf("Dado o vetor = [9, 6, 13, 3, 14, 22, 7]:\n\n");

    funcao_a(num);

    funcao_b(num);

    funcao_c(num);

    funcao_d(num);

    funcao_e(num);

    printf("f) Retorne o maior elemento do vetor:\n");
    maior_num = funcao_f(num);
    printf("> %d\n\n", maior_num);


    printf("g) Retorne o menor elemento do vetor:\n");
    menor_num = funcao_g(num);
    printf("> %d\n\n", menor_num);

    printf("h)  Calcule e retorne a media dos elementos do vetor:\n");
    media_vetor = funcao_h(num);
    printf("> %.2f\n\n", media_vetor);

    funcao_i(num);

    funcao_j(num);

    funcao_k(num);

    return 0;
}

 void funcao_a(int vet[])
 {
     int i, soma=0;

     printf("a) Calcule e mostre a soma dos elementos do vetor:\n");

     for(i=0; i<7; i++)
     {
         soma+=vet[i];
     }

     printf("> %d\n\n", soma);
 }

 void funcao_b(int vet[])
 {
     int i=0;

     printf("b) Mostre o indice dos elementos que tem valor impar:\n");

     for(i=0; i<7; i++)
     {
         if(vet[i]%2==1)
         {
             printf("> %d\n", i);
         }
     }

     printf("\n");
 }

void funcao_c(int vet[])
{
    int i=0, produto=1;

    printf("c) Calcule e mostre o produto dos elementos que tem valor par:\n");

    for(i=0; i<7; i++)
    {
        if(vet[i]%2==0)
        {
            produto*=vet[i];
        }
    }

    printf("> %d\n\n", produto);
}

 void funcao_d(int vet[])
 {
     int i=0;

     printf("d) Calcule e mostre a soma do triplo do valor dos elementos com indice impar:\n");

     for(i=0; i<7; i++)
     {
         if(vet[i]%2==1)
         {
             printf("> %d\n", vet[i]*3);
         }
     }

     printf("\n");
 }

 void funcao_e(int vet[])
 {
     int i=0;
     float resultado;

     printf("e) Divida todos os elementos do vetor por 4 e mostre os novos valores:\n");

     for(i=0; i<7; i++)
     {
        resultado= (float) vet[i]/4;

        printf("> %.2f\n", resultado);
     }

     printf("\n");
}

int funcao_f(int vet[])
{
    int i, maior_numero=INT_MIN;

    for(i=0; i<7; i++)
    {
        if(vet[i]>maior_numero)
        {
            maior_numero=vet[i];
        }
    }

    return maior_numero;
}

int funcao_g(int vet[])
{
    int i=0;
    int menor_numero=INT_MAX;

    for(i=0; i<7; i++)
    {
        if(vet[i]<menor_numero)
        {
            menor_numero=vet[i];
        }
    }

    return menor_numero;
}

float funcao_h(int vet[])
{
    int i=0, soma=0;
    float media=0;

    for(i=0; i<7; i++)
    {
        soma = soma + vet[i];
    }

    media = (float)soma/7;

    return media;
}

void funcao_i(int vet[])
{
    int i=0;
    float media = funcao_h(vet);

    printf("i) Calcule e mostre os elementos que sao menores que a media:\n");

    for(i=0; i<7; i++)
    {
        if(vet[i]<media)
        {
            printf("> %d\n", vet[i]);
        }
    }

    printf("\n");
}

void funcao_j(int vet[])
{
    int i=0;
    float media = funcao_h(vet);

    printf("i) Calcule e mostre o indice dos elementos que sao maiores que a media:\n");

    for(i=0; i<7; i++)
    {
        if(vet[i]>media)
        {
            printf("> %d\n", i);
        }
    }

    printf("\n");
}

void funcao_k(int vet[])
{
    int i, j, aux;
    i = j = aux = 0;

    printf("k) Ordene os elementos do vetor:\n");

    for(i=0; i<7; i++)
    {
        for(j=0 ; j<6; j++)
        {
            if(vet[j] > vet[j+1])
            {
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }

    for(j=0; j<7; j++)
    {
        printf("> %d\n", vet[j]);
    }

    printf("\n");
}
