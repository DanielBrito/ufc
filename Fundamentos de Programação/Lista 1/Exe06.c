#include<stdio.h>
#include<math.h>

int main()
{
    float num;

    printf("Digite um numero: ");
    scanf("%f", &num);

    printf("\nAo quadrado: %.2f", pow(num, 2)); //pow(num, potencia)
    printf("\nAo cubo: %.2f", pow(num, 3)); //pow(num, potencia)
    printf("\nRaiz quadrada: %.2f", sqrt(num)); // ou pow(num, 0.5) = num^(1/2)
    printf("\nRaiz cubica: %.2f\n\n", pow(num, 0.33)); // ou pow(num, 1.0/3.0) = num^(1/3)

    return 0;

}
