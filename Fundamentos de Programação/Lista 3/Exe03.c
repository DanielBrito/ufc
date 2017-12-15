#include<stdio.h>

int main()
{
    int num, i, j, x;
    int fat=1;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    printf("\n");

    for(i=1; i<=num; i++)
    {
        printf("Digite o valor %d: ", i);
        scanf("%d", &x);

        for(j=1; j<=x; j++)
        {
            fat = fat*j;
        }
        printf("%d! = %d\n\n", x, fat);

        fat = 1;
    }

    system("PAUSE");
    return 0;
}
