#include<stdio.h>

#define LIMITE 101

int main()
{
    int num[LIMITE];
    int i, n=200;

    for(i=0; i<LIMITE; i++)
    {
        num[i] = n;

        n = n+1;
    }

    for(i=0; i<LIMITE; i++)
    {
        if(num[i]%4==0)
        {
            printf("Posicao %d - Valor %d\n", i, num[i]);
        }
    }

    return 0;
}
