#include<stdio.h>

int main()
{
    float salario_base, salario_liquido;

    printf("Digite o salario base: ");
    scanf("%f", &salario_base);

    salario_liquido = salario_base+(salario_base*0.05)-(salario_base*0.07);

    printf("\nSalario a receber: %.2f\n\n", salario_liquido);

    return 0;

}
