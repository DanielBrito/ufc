#include<stdio.h>

int main()
{
    float salario = 1000.00, salario_atual;
    float aumento = 0.015; // 1,5%
    int i;

    salario_atual = salario+(salario*aumento);

    for(i=2007; i<=2017; i++)
    {
        aumento*=2;

        salario_atual = salario_atual+(salario_atual*aumento);
    }

    printf("Salario atual: R$ %.2f\n\n", salario_atual);

    system("PAUSE");
    return 0;
}
