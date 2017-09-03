#include<stdio.h>
#include<math.h>

void calc_esfera(float n, float *area, float *volume)
{
    *area = 4*(pow(n,2));
    *volume = 4*(pow(n,3))/3.0;
}

int main()
{
    float raio, area, volume;
    
    printf("Digite o raio da esfera: ");
    scanf("%f", &raio);

    calc_esfera(raio, &area, &volume);

    printf("Area: %.2f\n", area);
    printf("Volume: %.2f", volume);

    printf("\n\n");

    return 0;
}
