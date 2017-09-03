#include<stdio.h>

int main(){
	
    float nota1, nota2, nota3;
    float peso1, peso2, peso3;
    float mediaPonderada = 0;

    printf("Digite a nota 1: ");
    scanf("%f", &nota1);

    printf("Digite a nota 2: ");
    scanf("%f", &nota2);

    printf("Digite a nota 3: ");
    scanf("%f", &nota3);

    printf("\n");

    printf("Peso da nota 1: ");
    scanf("%f", &peso1);

    printf("Peso da nota 2: ");
    scanf("%f", &peso2);

    printf("Peso da nota 3: ");
    scanf("%f", &peso3);

    mediaPonderada = ((nota1*peso1)+(nota2*peso2)+(nota3*peso3))/(peso1+peso2+peso3);

    printf("\n\nMedia Ponderada: %.2f", mediaPonderada);

    printf("\n\n");

    system("PAUSE");
    return 0;
}
