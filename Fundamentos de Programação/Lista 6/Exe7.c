#include<stdio.h>

int main()
{
    float vet[10]={10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    int i=0;
    float S=0;

    for(i=0; i<10; i++)
    {
        S = S + ((float)i/vet[i]);
    }

    printf("S = %.2f\n\n", S);

    return 0;
}
