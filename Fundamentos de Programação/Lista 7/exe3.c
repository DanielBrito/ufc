#include<stdio.h>

int main()
{
    float temp[7]={0}, soma=0, media=0;
    int i;

    for(i=0; i<7; i++)
    {
        printf("Temperatura do %do dia da semana: ", i+1);
        scanf("%f", &temp[i]);

        soma = soma+temp[i];
    }

    media = soma/7;

    printf("\n----------------------------------");

    printf("\n\nTemperaturas acima da media semanal (%.2f):\n\n", media);

    for(i=0; i<7; i++)
    {
        if(temp[i]>media)
        {
            if(i==0)
            {
                printf("> Segunda-feira = %.2f\n", temp[i]);
            }
            else
            if(i==1)
            {
                printf("> Terca-feira = %.2f\n", temp[i]);
            }
            else
            if(i==2)
            {
                printf("> Quarta-feira = %.2f\n", temp[i]);
            }
            else
            if(i==3)
            {
                printf("> Quinta-feira = %.2f\n", temp[i]);
            }
            else
            if(i==4)
            {
                printf("> Sexta-feira = %.2f\n", temp[i]);
            }
            else
            if(i==5)
            {
                printf("> Sabado = %.2f\n", temp[i]);
            }
            else
                printf("> Domingo = %.2f\n", temp[i]);
        }
    }

    printf("\n\n");

    return 0;
}
