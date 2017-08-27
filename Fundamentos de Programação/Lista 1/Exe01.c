#include<stdio.h>

int main()
{
    float n1, n2, n3, media_ponderada;

    printf("Digite a primeira nota: ");
    scanf("%f", &n1);

    printf("Digite a segunda nota: ");
    scanf("%f", &n2);

    printf("Digite a terceira nota: ");
    scanf("%f", &n3);

    media_ponderada = ((n1*2)+(n2*3)+(n3*5))/10;

    printf("\nMedia ponderada: %.2f\n\n", media_ponderada);

    return 0;
}
