#include<stdio.h>
#include<stdlib.h>

int main()
{
    int x, y, z; // lados do triangulo

    printf("Digite o primeiro valor: ");
    scanf("%d", &x);
    printf("Digite o segundo valor: ");
    scanf("%d", &y);
    printf("Digite o terceiro valor: ");
    scanf("%d", &z);

    if(x>y+z || y>x+z || z>x+y)
    {
        printf("\n\nO valores nao formam um triangulo.\n\n");
    }
    else
    if(x==y==z)
    {
        printf("\n\nOs valores formam um triangulo equilatero.\n\n");
    }
    else
    if(x==y || x==z || y==z)
    {
        printf("\n\nOs valores formam um triangulo isosceles.\n\n");
    }
    else
    if(x!=y && x!=z && y!=z)
    {
        printf("\n\nOs valores formam um triangulo escaleno.\n\n");
    }

    return 0;
}
