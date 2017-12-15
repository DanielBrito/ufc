#include<stdio.h>

int main()
{
    int num, i, fat=1;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    for(i=1; i<=num; i++)
    {
        fat = fat*i;
    }

    printf("\n%d! = %d\n\n", num, fat);

    system("PAUSE");
    return 0;
}
