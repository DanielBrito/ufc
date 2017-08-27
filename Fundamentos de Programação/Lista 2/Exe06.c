#include<stdio.h>
#include<stdlib.h>

int main()
{
    int venda_media_mensal;
    float preco;

    printf("Digite a venda media mensal do produto: ");
    scanf("%d", &venda_media_mensal);
    printf("Digite o preco atual do produto: ");
    scanf("%f", &preco);

    printf("\n\n");

    if(venda_media_mensal<500 && preco<30)
    {
        preco = preco*1.10;

        printf("Novo preco: %.2f\n\n", preco);
    }
    else
    if(venda_media_mensal>=500 && venda_media_mensal<1200 && preco>=30 && preco<80)
    {
        preco = preco*1.15;

        printf("Novo preco: %.2f\n\n", preco);
    }
    else
    if(venda_media_mensal>=1200 && preco>=80)
    {
        preco = preco-(preco*0.20);

        printf("Novo preco: %.2f\n\n", preco);
    }
    else
        printf("Nao houve alteracao de preco.\n\n");

    return 0;
}
