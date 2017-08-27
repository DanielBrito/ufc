#include<stdio.h>
#include<stdlib.h>

/*

Faça um programa que apresente o meni a seguir, permita ao usuário escolher a
opção desejada, receba os dados necessários para executar a operação e mostre o
resultado. Verifique a possibilidade de opção inválida.
MENU DE OPÇÕES:
1 - Imposto
2 - Novo salário
3 - Faixa salarial
Digite a opção desejada:

*/

int main()
{
    int opcao;
    float salario, imposto;
    char faixa_salarial;

    system("cls");

    printf("   * MENU DE OPCOES *\n\n");
    printf("1 - Imposto\n");
    printf("2 - Novo salario\n");
    printf("3 - Faixa salarial\n\n");

    printf("- > Opcao desejada: ");
    scanf("%d", &opcao);

    if(opcao==1)
    {
        printf("\n\nDigite o valor do salario: ");
        scanf("%f", &salario);

        if(salario<500)
        {
            imposto = salario*0.05;
        }
        if(salario>=500 && salario<=850)
        {
            imposto = salario*0.10;
        }
        if(salario>850)
        {
            imposto = salario*0.15;
        }

        printf("\n\nValor do imposto: %.2f\n\n", imposto);
    }
    else
    if(opcao==2)
    {
        printf("\n\nDigite o valor do salario: ");
        scanf("%f", &salario);

        if(salario<450)
        {
            printf("\n\nNovo salario: %.2f\n\n", salario+100);
        }
        if(salario>=450 && salario<750)
        {
            printf("\n\nNovo salario: %.2f\n\n", salario+75);
        }
        if(salario>=750 && salario<=1500)
        {
            printf("\n\nNovo salario: %.2f\n\n", salario+50);
        }
        if(salario>1500)
        {
            printf("\n\nNovo salario: %.2f\n\n", salario+25);
        }
    }
    else
    if(opcao==3)
    {
        printf("\n\nDigite o valor do salario: ");
        scanf("%f", &salario);

        if(salario<=700)
        {
            faixa_salarial = 'A';
        }
        else
        {
            faixa_salarial = 'B';
        }

        printf("\n\nFaixa salarial: %c\n\n", faixa_salarial);
    }
    else
    {
        system("cls");

        printf("ERRO! Opcao invalida!\n\nTecle ENTER para retornar ao MENU DE OPCOES.\n\n");

        system("PAUSE");

        return main();
    }

    return 0;
}
