#include <stdio.h>
#include <math.h>

/*
Exemplos:
x² – 5x + 6 = 0 possui duas raizes reais, 2 e 3
x² – 4x + 4 = 0 possui uma raiz real, 2
x² + 2x + 2 = 0 não possi raizes reais.
*/

int raizes(float a, float b, float c, float* x1, float*x2){

	float delta;

	delta = (b*b)-4*a*c;

	if(delta<0){

		return 0;
	}
	else
	if(delta==0){

		*x1 = (b*(-1)+sqrt(delta))/(2*a);

		return 1;
	}
	else{

		*x1 = (b*(-1)+sqrt(delta))/(2*a);

		*x2 = (b*(-1)-sqrt(delta))/(2*a);

		return 2;
	}

}

int main(){

	float a,b,c,x1,x2;

	printf("Informe os valores de a, b e c\n");
	scanf("%f", &a);
	scanf("%f", &b);
	scanf("%f", &c);

	if(raizes(a,b,c,&x1,&x2)==0){

		printf("Não existem raizes reais\n");
	}
	else 
	if(raizes(a,b,c,&x1,&x2)==1){

		printf("Existe uma raiz real, que vale: %.2f\n", x1);
	}
	else{

		printf("Existe duas raiz real, que valem: %.2f e %.2f\n", x1, x2);
	}

	return 0;
}