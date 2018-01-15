#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int contSim=0;
	char resposta;
	
	printf("1) Telefonou para a vitima?\nResposta (s/n): ");
	scanf(" %c", &resposta);
	
	if(resposta=='s'){
		
		contSim++;
	}
	
	printf("2) Esteve no local do crime?\nResposta (s/n): ");
	scanf(" %c", &resposta);
	
	if(resposta=='s'){
		
		contSim++;
	}
	
	printf("3) Mora perto da vitima?\nResposta (s/n): ");
	scanf(" %c", &resposta);
	
	if(resposta=='s'){
		
		contSim++;
	}
	
	printf("4) Devia para a vitima?\nResposta (s/n): ");
	scanf(" %c", &resposta);
	
	if(resposta=='s'){
		
		contSim++;
	}
	
	printf("5) Ja trabalhou com a vitima?\nResposta (s/n): ");
	scanf(" %c", &resposta);
	
	if(resposta=='s'){
		
		contSim++;
	}
	
	printf("\n");
	
	if(contSim==2){
		
		printf("Suspeita");
	}
	else	
	if(contSim>=3 && contSim<=4){
		
		printf("Cumplice");
	}
	else
	if(contSim==5){
		
		printf("Assassino");
	}
	else{
		
		printf("Inocente");
	}	
	
	printf("\n\n");
	
	return 0;
}
