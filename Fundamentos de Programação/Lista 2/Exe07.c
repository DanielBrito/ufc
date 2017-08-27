#include<stdio.h>
#include<stdlib.h>

int main()
{
    float a, b, c; // variáveis de entrada
    float delta, x, x1, x2; // variaveis de saida

    system("cls");

    printf("Para a formula: ax^2 + bx + c = 0:\n\n");

    printf("Digite o valor de a: ");
    scanf("%f", &a);

    while(a==0)
    {
        printf("\n\nValor invalido! A variavel 'a' dever ser diferente de 0.\n\n");

        printf("Tecle ENTER para reiniciar.\n\n");

        system("PAUSE");

        return main();
    }

    printf("Digite o valor de b: ");
    scanf("%f", &b);

    printf("Digite o valor de c: ");
    scanf("%f", &c);

    delta = (b*b)-(4*a*c);

    if(delta<0)
    {
        printf("\n\nNao existe raiz real para delta = %.2f.\n\n", delta);
    }
    else
    if(delta==0)
    {
        x = (-b)/(2*a);

        printf("\n\nPara delta = %.2f, x = %.2f\n\n", delta, x);
    }
    else
    if(delta>0)
    {
        x1 = (-b+(sqrt(delta)))/(2*a);

        x2 = (-b-(sqrt(delta)))/(2*a);

        printf("\n\nPara delta = %.2f, x1 = %.2f e x2 = %.2f\n\n", delta, x1, x2);
    }

    return 0;
}
