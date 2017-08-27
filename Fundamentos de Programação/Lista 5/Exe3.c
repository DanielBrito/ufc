#include<stdio.h>

float vol(float r)
{
    float vol;

    vol = ((4*3.14)*(r*r*r))/3;

    return vol;
}

int main()
{
    float raio, volume;

    printf("Digite o raio do circulo: ");
    scanf("%f", &raio);

    volume = vol(raio);

    printf("\n\nO volume da esfera e %.2f\n\n", volume);

    system("PAUSE");
    return 0;
}
