#include<stdio.h>

int main()
{
    int base, altura, area;

    printf("Digite o valor da base (cm): ");
    scanf("%d", &base);

    printf("Digite o valor da altura (cm): ");
    scanf("%d", &altura);

    area = (base*altura)/2;

    printf("\nA area do triangulo é de %d cm2\n\n", area);

    return 0;
}
