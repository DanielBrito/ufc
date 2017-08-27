#include<stdio.h>
#include<math.h>

float volume(float comp)
{
    float vol;

    vol = (5/12)*(3+(pow(5.0, 0.5)))*(pow(comp, 3.0));

    return vol;
}

int main()
{
    float comprimento, resultado;

    printf("Digite o comprimento da aresta (a): ");
    scanf("%f", &comprimento);

    resultado = volume(comprimento);

    printf("\n\nO volume do icosaedro com aresta %.2f e %.2f\n\n", comprimento, resultado);

    system("PAUSE");
    return 0;
}
