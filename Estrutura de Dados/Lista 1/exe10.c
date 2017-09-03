#include<stdio.h>

int main(){
	
    int num, i, j;
    
    printf("Digite um numero: ");
    scanf("%d", &num);
    
    printf("\n");
    
    for(i=0; i<num; i++){
    	
    	for(j=0; j<num; j++){
    		
    		if(i==j){
    			
    			printf(" O ");
			}
			else{
				
				printf(" # ");
			}
		}
		
		printf("\n");
	}

    printf("\n\n");

	system("PAUSE");
    return 0;
}
