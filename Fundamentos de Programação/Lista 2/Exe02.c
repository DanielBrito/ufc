#include<stdio.h>

int main()
{
    int n1, n2, n3, primeiro, segundo, terceiro;

    printf("Digite um numero: ");
    scanf("%d", &n1);
    printf("Digite um numero: ");
    scanf("%d", &n2);
    printf("Digite um numero: ");
    scanf("%d", &n3);

    if(n1>n2 && n1>n3)
    {
        terceiro = n1;

        if(n2>n3)
        {
            segundo = n2;
            terceiro = n3;
        }
    }
    if(n2>n1 && n2>n3)
    {
        terceiro = n2;

        if(n1>n3)
        {
            segundo = n1;
            primeiro = n3;
        }
    }
    if(n3>n1 && n3>n2)
    {
        terceiro = n3;

        if(n1>n2)
        {
            segundo = n1;
            primeiro = n2;
        }
    }

    printf("\n\n> Numeros digitados em ordem crescente: \n");
    printf(" %d | %d | %d\n\n", primeiro, segundo, terceiro);

    return 0;
}
