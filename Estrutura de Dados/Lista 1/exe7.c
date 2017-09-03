#include<stdio.h>

int main(){
	
	int num, i;
	
	printf("Digite um valor: ");
	scanf("%d", &num);
	
	printf("\n");
	
	for(i=2; i<=num; i++){
		
		if(num%i == 0){
			
			printf("%d\n", i);
		}
	}
	
	printf("\n\n");
	
	system("PAUSE");
	return 0;
}
