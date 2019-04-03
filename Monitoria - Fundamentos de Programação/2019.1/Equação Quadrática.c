/* Estudos práticos de switch-case */

#include<stdio.h>
#include<math.h>

int main(){
	
	float a, b, c, x1, x2, delta;
	
	printf("\tResolver equacao ax^2 + bx + c = 0\n\n");
	
	printf("Digite o valor de \"a\": ");
	scanf("%f", &a);
	
	printf("Digite o valor de \"b\": ");
	scanf("%f", &b);

	printf("Digite o valor de \"c\": ");
	scanf("%f", &c);
	
	delta = (b*b)-(4*a*c);
	
	switch(delta>=0){
		
		case 1: switch(delta==0){
			    
			        case 1: printf("\nx1 = x2 = %.2f\n", (-b+sqrt(delta))/2*a); break;
			        
			        case 0: printf("\nx1 = %.2f e x2 = %.2f\n", (-b+sqrt(delta))/(2*a), (-b-sqrt(delta))/(2*a)); break;
			    }
				break;
		case 0: printf("\nNao existem raizes reais.\n");
	}
	
	return 0;
}
