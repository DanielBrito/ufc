/* https://youtu.be/Mdn8CmhFaSs */

#include<stdio.h>
#include<math.h>

void primeirosTermos(int n);
void somaPrimeirosTermos(int n);
void formulaBinet(int n);
int arredondarNumero(float num);

int main(){
	
	int n;
	
	printf("SEQUENCIA DE FIBONACCI\n\n");
	
	printf("Digite o valor de N: ");
	scanf("%d", &n);
	
	primeirosTermos(n);
	
	somaPrimeirosTermos(n);
	
	formulaBinet(n);
	
	return 0;	
}

void primeirosTermos(int n){
	
	printf("\nN primeiros termos:\n");
	
	int x=1, y=1, z, i;
	
	if(n==1){
		
		printf("%d", x);
		return;
	}
	
	if(n==2){
		
		printf("%d %d", x, y);
		return;
	}
	
	printf("%d ", x);
	printf("%d ", y);
	
	for(i=3; i<=n; i++){
		
		z = x+y;
		
		printf("%d ", z);
		
		x = y;
		y = z;
	}
	
	return;	
}

void somaPrimeirosTermos(int n){
	
	printf("\n\nSoma dos N primeiros termos:\n");
	
	int x=1, y=1, z, i, soma=0;
	
	if(n==1){
		
		printf("%d", x);
		return;
	}
	
	if(n==2){
		
		printf("%d", x+y);
		return;
	}
	
	soma = x+y;
	
	for(i=3; i<=n; i++){
		
		z = x+y;
		x = y;
		y = z;
		
		soma += z;
	}
	
	printf("%d", soma);
	
	return;	
}

void formulaBinet(int n){
	
	printf("\n\nN-esimo termo pela Formula de Binet:\n");
	
	float Fn;
	
	Fn = (pow(((1+sqrt(5))/2), n) - pow(((1-sqrt(5))/2), n)) / sqrt(5);
	
	printf("%d\n", arredondarNumero(Fn));
	
	return;
}

int arredondarNumero(float num){
	
	if(num>=0){
		
		return (int)(num+0.5);
	}
	else{
		
		return (int)(num-0.5);
	}
}