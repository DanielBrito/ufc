#include<stdio.h>
#include<math.h>

/*
	Mais informações: http://www.matematicadidatica.com.br/SequenciaFibonacci.aspx
*/

#define MAX 22 

int arredondaNumero(double num);
int verificaPertinencia(int num);
int nEsimaPosicaoFibonacci(int p);

int main(){
	
	int p;
	double phi = (1+sqrt(5))/2;
	double n;
	
	printf("SEQUENCIA DE FIBONACCI\n\n");
	
	while(1){
		
		printf("Digite um termo da sequencia: ");
		scanf("%d", &p);
		
		printf("\n");
		
		if(verificaPertinencia(p)){
			
			n = (log10(sqrt(5)*p))/log10(phi);
			
			printf("O termo %d esta na posicao [%d].", p, arredondaNumero(n));
		}
		else{
			
			printf("O numero nao pertence a sequencia.");
		}
		
		printf("\n\n");
	}
	
	return 0;
}


int verificaPertinencia(int num){
	
	int i;
	
	for(i=0; ; i++){
		
		if(num == nEsimaPosicaoFibonacci(i)){
			
			return 1;
		}
		else
		if(nEsimaPosicaoFibonacci(i)>num){
			
			return 0;
		}
	}
}


int nEsimaPosicaoFibonacci(int p){
	
	float Fn;
	
	Fn = (pow(((1+sqrt(5))/2), p) - pow(((1-sqrt(5))/2), p)) / sqrt(5);
	
	return arredondaNumero(Fn);
}


int arredondaNumero(double num){
	
	return (num>=0) ? (int)(num+0.5) : (int)(num-0.5);
}
