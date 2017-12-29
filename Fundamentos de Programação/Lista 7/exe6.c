#include<stdio.h>
#include<string.h>

int main(){
	
	int i, j;
	char palavra[20];
	
	printf("Digite um palavra: ");
	scanf("%s", palavra);
	
	printf("\n");
	
	for(i=strlen(palavra)-1; i>=0; i--){
		
		for(j=strlen(palavra)-1; j>=0; j--){
			
			if(i+j == strlen(palavra)-1){
				
				printf("%c ", palavra[i]);
			}
			else{
				
				printf("- ");
			}
		}
		
		printf("\n");
	}
	
	printf("\n\n");
	
	return 0;
}
