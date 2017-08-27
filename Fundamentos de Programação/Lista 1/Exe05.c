#include<stdio.h>
#include<math.h>

int main()
{
    float raio, area;

    printf("Digite o raio do circulo: ");
    scanf("%f", &raio);

    area = 3.14*(pow(raio, 2));

    printf("\nA area do circulo e: %.2f\n\n", area);

    return 0;
}
