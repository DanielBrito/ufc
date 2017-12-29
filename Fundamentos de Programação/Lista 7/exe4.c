#include<stdio.h>

#define TAM 5

int maiores(int vet[]);

int main()
{
    int num[TAM]={0};
    int i, qtd=0;

    for(i=0; i<TAM; i++)
    {
        printf("Digite o %do valor: ", i+1);
        scanf("%d", &num[i]);
    }

    qtd = maiores(num);

    printf("\n\nA quantidade de valores maiores que a media e %d.\n\n", qtd);

    return 0;
}

int maiores(int vet[])
{
    int i, maior=0;
    int soma=0, cont=0;
    float media=0;

    for(i=0; i<TAM; i++)
    {
        soma = soma+vet[i];
    }

    media = (float)soma/TAM;

    for(i=0; i<TAM; i++)
    {
        if(vet[i]>media)
        {
            cont++;
        }
    }

    return cont;
}
