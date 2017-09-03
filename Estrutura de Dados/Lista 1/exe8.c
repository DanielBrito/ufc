#include<stdio.h>

int primo(int num);

int main(){
	
	int num, i;
	
	printf("Digite um valor: ");
	scanf("%d", &num);
	
	printf("\n");
	
	for(i=num; i>0; i--){
		
		if(primo(i)){
			
			printf("Maior primo que e menor ou igual a %d = %d", num, i);
			
			break;
		}
	}
	
	printf("\n\n");
	
	for(i=num; ; i++){
		
		if(primo(i)){
			
			printf("Menor primo que e maior ou igual a %d = %d", num, i);
			
			break;
		}
	}	
	
	printf("\n\n\n");
	
	system("PAUSE");
	return 0;
}


int primo(int num){
	
	int i, cont=0;
	
	for(i=1; i<=num; i++){
				
		if(num%i == 0){
			
			cont++;
		}
	}
	
	if(num==1){
		
		return 0;
	}
	else
	if(cont<3){
		
		return 1; // Numero primo
	}
	else{
		
		return 0; // Numero nao primo
	}
}
