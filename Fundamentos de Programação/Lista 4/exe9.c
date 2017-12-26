#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int popA = 80000, popB = 200000;
	float taxaA = 3, taxaB = 1.5;
	
	int anos=0;
	
	for(popA=80000, popB=200000; ; popA += popA * (taxaA/100), popB += popB * (taxaB/100)){
		
		if(popA>=popB){
			
			printf("Populacao do pais A: %d\n", popA);
			printf("Populacao do pais B: %d\n\n", popB);
			
			printf("Anos = %d", anos);
			
			break;
		}
		
		++anos;
	}

	printf("\n\n");
	
	return 0;
}
