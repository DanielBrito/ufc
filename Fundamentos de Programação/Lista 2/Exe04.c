#include<stdio.h>
#include<stdlib.h>

/*

Faça um programa que receba o código correspondente ao cargo de um funcionário
e seu salário atual e mostre o código do cargo, o valor do aumento e seu novo salário.
Os cargos estão na tabela a seguir.
CÓDIGO  % AUMENTO
1          50%
2          35%
3          20%
4          10%

*/

int main()
{
    int codigo;
    float salario;

    printf("Digite o codigo do cargo: ");
    scanf("%d", &codigo);
    printf("Digite o valor do salario: ");
    scanf("%f", &salario);

    if(codigo==1)
    {
        printf("\n\n   RELATORIO\n\n");
        printf("Codigo do cargo: %d\n", codigo);
        printf("Valor do aumento: %.2f\n", salario*0.5);
        printf("Salario atual: %.2f\n\n", salario*1.5);
    }
    if(codigo==2)
    {
        printf("\n\n   RELATORIO\n\n");
        printf("Codigo do cargo: %d\n", codigo);
        printf("Valor do aumento: %.2f\n", salario*0.35);
        printf("Salario atual: %.2f\n\n", salario*1.35);
    }
    if(codigo==3)
    {
        printf("\n\n   RELATORIO\n\n");
        printf("Codigo do cargo: %d\n", codigo);
        printf("Valor do aumento: %.2f\n", salario*0.2);
        printf("Salario atual: %.2f\n\n", salario*1.2);
    }
    if(codigo==4)
    {
        printf("\n\n   RELATORIO\n\n");
        printf("Codigo do cargo: %d\n", codigo);
        printf("Valor do aumento: %.2f\n", salario*0.1);
        printf("Salario atual: %.2f\n\n", salario*1.1);
    }

    return 0;
}
