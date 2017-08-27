#include<stdio.h>
#include<stdlib.h>

/*

Faça um programa que mostre um menu de opções a seguir, receba a opção do
usuário e os dados necessários para executar cada operação.

MENU DE OPÇÕES:
1 - Somar dois números.
2 - Raiz quadrada de um número.
Digite a opção desejada:

*/

int main()
{
    system("cls");

    int opcao;
    int n1=0, n2=0; // Soma
    float num; // Raiz quadrada

    printf("MENU DE OPCOES:\n\n");
    printf("1 - Somar dois inteiros\n");
    printf("2 - Raiz quadrada de um numero\n\n");

    printf("- > Opcao desejada: ");
    scanf("%d", &opcao);

    if(opcao==1)
    {
        printf("\n\nDigite dois valores: \n");
        scanf("%d%d", &n1, &n2);

        printf("\n\n%d + %d = %d\n\n", n1, n2, n1+n2);

        system("PAUSE");

        return main();
    }
    if(opcao==2)
    {
        printf("\n\nDigite um numero: ");
        scanf("%f", &num);

        printf("\n\nRaiz quadrada de %.2f = %.2f\n\n", num, pow(num, 0.5)); // ou sqrt(num);

        system("PAUSE");

        return main();
    }

    return 0;
}
