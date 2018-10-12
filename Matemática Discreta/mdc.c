#include <stdio.h>

int mdc(int x, int y);

int main(){

	int num1, num2;

	printf("Digite dois valores: ");
	scanf("%d %d", &num1, &num2);

	printf("\n");

	printf("MDC(%d, %d) = %d", num1, num2, mdc(num1, num2));

	printf("\n");

	return 0;
}


int mdc(int x, int y){

	if(y==0){

		return x;
	}

	return mdc(y, x%y);
}