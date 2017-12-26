#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int i, j;
	
	for(i=0; i<5; i++){
		
		for(j=0; j<i; j++){
			
			if(i==0 || i==1){
				
				printf("*\n");
			}
			
			printf("*");
		}
		
		printf("\n");
	}

	printf("\n\n");
	
	return 0;
}
