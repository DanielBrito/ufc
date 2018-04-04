#include <stdio.h>

int multRussa(int a, int b);

int main(){

	int num1, num2;

	printf("Digite dois valores: ");
	scanf("%d %d", &num1, &num2);

	printf("\n");

	printf("%d * %d = %d", num1, num2, multRussa(num1, num2));

	printf("\n");
	
	return 0;
}

int multRussa(int a, int b){

	if(a==1){

		return b;
	}
	
	if(a%2==1){

		return b + multRussa(a/2, b*2);
	}
	else{

		multRussa(a/2, b*2);
	}
}