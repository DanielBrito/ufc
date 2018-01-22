#include<stdio.h>
#include<string.h>

int main()
{
    int num, i, j;

    printf("Digite um numero: ");
    scanf("%d", &num);

    printf("\n\n");

    for(i=0; i<num; i++)
    {
        for(j=0; j<=i; j++)
        {
            printf("%d", j+1);
        }

        printf("\n");
    }

    printf("\n\n");

    return 0;
}
