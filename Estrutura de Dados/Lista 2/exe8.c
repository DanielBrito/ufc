#include<stdio.h>
#include<stdlib.h>

int verificaPrimo(int n);
int primosDecrescente(int n);

int main(){
	
	int num;
	
	printf("Digite um numero: ");
	scanf("%d", &num);
	
	printf("\nNumeros primos de 0 ate %d:\n\n", num);
	
	primosDecrescente(num);
	
	printf("\n");
	
	return 0;
}


int verificaPrimo(int n){
	
	int i, cont=0;
	
	for(i=1; i<=n; i++){
				
		if(n%i == 0){
			
			cont++;
		}
	}
	
	if(n==1){
		
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


int primosDecrescente(int n){
	
	if(n<2){
		
		return 0;
	}
	else{
		
		if(verificaPrimo(n)){
		
			printf("%d\n", n);
		
			return primosDecrescente(n-1);
		}
		else{
		
			return primosDecrescente(n-1);
		}
	}
}
