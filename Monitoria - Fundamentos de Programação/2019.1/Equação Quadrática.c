/* Estudos práticos de switch-case */

#include<stdio.h>
#include<math.h>

int main(){
	
	float a, b, c, delta;
	
	printf("\tResolver equacao ax^2 + bx + c = 0\n\n");

    // Fazendo a entrada dos valores dos coeficientes:
	
	printf("Digite o valor de \"a\": ");
	scanf("%f", &a);
	
	printf("Digite o valor de \"b\": ");
	scanf("%f", &b);

	printf("Digite o valor de \"c\": ");
	scanf("%f", &c);
	
	delta = (b*b)-(4*a*c); // Calculando delta: b^2-4*a*c
	
	switch(delta>=0){ // Utilizando o resultado da operação lógica para indexar os casos

        // Se o delta for maior ou igual a 0, temos que o resultado de retorno é 1 (true). Então precisamos saber se ele é igual a 0 ou maior que 0:
		
		case 1: switch(delta==0){

                    // Se o delta for igual a zero, temos que o resultado de retorno é 1 (true). Então realizamos o cálculo do único valor de x:
			    
			        case 1: printf("\nx1 = x2 = %.2f\n", (-b+sqrt(delta))/2*a); break;

                    // Se o delta não for igual a 0, só pode ser maior que zero, logo, realizamos o cálculo de x1 e x2:
			        
			        case 0: printf("\nx1 = %.2f e x2 = %.2f\n", (-b+sqrt(delta))/(2*a), (-b-sqrt(delta))/(2*a)); break;
			    }
				break;

        // Se delta não for maior nem igual a zero, o resultado de retorno é 0 (falso). Ou seja, delta só pode ser negativo. Logo, a equação não possui raízes reais:

		case 0: printf("\nNao existem raizes reais.\n");
	}
	
	return 0;
}
