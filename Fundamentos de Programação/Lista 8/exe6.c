#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int numFib(int pos);
int fatorial(int num);
void calculaS(int* vet);
void calculaT(int* vet);

int main(){
	
	int vetor[6];
	int i;
	
	for(i=0; i<6; i++){
		
		printf("Digite o valor da posicao [%d]: ", i+1);
		scanf("%d", &vetor[i]);
	}
	
	printf("\n\n");
	
	calculaS(vetor);
	
	printf("\n\n");
	
	calculaT(vetor);
	
	printf("\n\n");
	
	return 0;
}


int numFib(int pos){
	
	int pos1=0, pos2=1, aux;
	int contPos=2, posAtual;
	
	if(pos==1){
		
		return 0;
	}
	else
	if(pos==2){
		
		return 1;
	}
	else{
		
		while(contPos!=pos){
			
			posAtual = pos1+pos2;
			
			aux = pos1;
			pos1 = pos2;
			pos2 = pos2+aux;
			
			contPos++;
		}
	}
	
	return posAtual;
}


int fatorial(int num){
	
	int resultado=num;
	int i;
	
	if(num==0){
		
		return 1;
	}
	
	for(i=1; i<num; i++){
		
		resultado *= i;
	}
	
	return resultado;
}


void calculaS(int* vet){
	
	float resultadoS = 0;
	int i, radicando=2;
	
	for(i=0; i<6; i++){
		
		resultadoS += vet[i]/sqrt(radicando); // ou pow(num, 0.5)
		radicando += 2;
	}
	
	printf("Resultado S = %f", resultadoS);
}


void calculaT(int* vet){
	
	float resultadoT = 1;
	int i, numFat=1, posFib=1;
	
	for(i=0; i<6; i++){
		
		resultadoT *= (pow(vet[i], 2))/((fatorial(numFat))+numFib(posFib));
		
		numFat++;
		posFib += 2;
	}
	
	printf("Resultado T = %f", resultadoT);	
}
