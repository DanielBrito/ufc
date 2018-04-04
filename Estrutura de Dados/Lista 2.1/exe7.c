#include <stdio.h>

int multRec(int n1, int n2);

int main(){
	
	int num1, num2;

	printf("Digite dois valores: ");
	scanf("%d %d", &num1, &num2);

	printf("\n");

	printf("%d * %d = %d", num1, num2, multRec(num1, num2));

	printf("\n");

	return 0;
}


int multRec(int n1, int n2){

	if(n2==0){

		return 0;
	}

	return n1 + multRec(n1, n2-1);
}