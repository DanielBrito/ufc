#include<stdio.h>

/*

Faça um programa que recebe o número de horas trabalhadas e o valor do salário
mínimo, calcule e mostre o salário a receber, seguindo estas regras:

a) a hora trabalhada vale a metade do salário mínimo.
b) o salário bruto equivale ao número de horas trabalhadas multiplicado pelo
valor da hora trabalhada da pessoa.
c) o imposto equivale a 3% do salário bruto.
d) o salário a receber equivale ao salário bruto menos o imposto.

*/

int main()
{
    float horas_trab, sal_minimo, imposto, sal_liquido, sal_bruto;

    printf("Digite o numero de horas trabalhadas: ");
    scanf("%f", &horas_trab);
    printf("Digite o valor do salario minimo: ");
    scanf("%f", &sal_minimo);


    sal_bruto = horas_trab*(sal_minimo/2);

    imposto = sal_bruto*(3.0/100.00);

    sal_liquido = sal_bruto-imposto;

    printf("\n\nSalario bruto: %.2f\n", sal_bruto);
    printf("Valor do imposto: %.2f\n", imposto);

    printf("\n\nSalario a receber: %.2f\n\n", sal_liquido);



    return 0;
}
