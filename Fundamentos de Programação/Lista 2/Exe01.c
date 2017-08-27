#include<stdio.h>

int main()
{
    float n1, n2, n3, media_pond;
    char conceito;

    printf("Nota do trabalho pratico: ");
    scanf("%f", &n1);
    printf("Nota da avaliação semestral: ");
    scanf("%f", &n2);
    printf("Nota do Exame final: ");
    scanf("%f", &n3);

    media_pond = ((n1*2)+(n2*3)+(n3*5))/10;

    if(media_pond>=8.0 && media_pond<=10.0)
    {
        conceito = 'A';
    }
    if(media_pond>=7.0 && media_pond<=7.9)
    {
        conceito = 'B';
    }
    if(media_pond>=6.0 && media_pond<=6.9)
    {
        conceito = 'C';
    }
    if(media_pond>=5.0 && media_pond<=5.9)
    {
        conceito = 'D';
    }
    if(media_pond>=0.0 && media_pond<=4.9)
    {
        conceito = 'E';
    }

    printf("\n\nMedia Ponderada = %.2f\n", media_pond);
    printf("Conceito: %c\n\n", conceito);

    return 0;
}
