#include<stdio.h>

int main()
{
    float salario, perc_aumento, valor_aumento;

    printf("Digite o valor do salario: ");
    scanf("%f", &salario);

    printf("Digite o percentual de aumento: ");
    scanf("%f", &perc_aumento);

    valor_aumento = salario*(perc_aumento/100);

    salario = salario + valor_aumento;

    printf("\nNovo salario: %.2f\n\n", salario);

    return 0;
}
