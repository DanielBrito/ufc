#include<stdio.h>

int main()
{
    int num, fat=1, i=1, j=1;
    float E = 1.0;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    for(i=1; i<=num; i++)
    {
        fat = 1;

        for(j=1; j<=i; j++)
        {
            fat = fat*=j;
        }

        E = E + 1.0/fat;
    }

    printf("E = %f\n\n", E);

    system("PAUSE");
    return 0;
}
