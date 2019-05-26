/* https://www.youtube.com/watch?v=amjq63biyDs */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	
	char str1[20], str2[20];
	int i, j, k;
	int tamStr1, tamStr2;
	int contStr1, contStr2;
	
	printf("Digite a primeira palavra: ");
	scanf("%[^\n]", str1);
	
	fflush(stdin);
	
	printf("Digite a segunda palavra: ");
	scanf("%[^\n]", str2);
	
	tamStr1 = strlen(str1);
	tamStr2 = strlen(str2);
	
	if((tamStr1!=tamStr2) || (strcmp(str1, str2)==0)){
		
		printf("\nNao sao anagramas.\n");
		return 0;
	}
	
	for(i=0; i<tamStr1; i++){
		
		contStr1=0;
		contStr2=0;
		
		for(j=0; j<tamStr1; j++){
			
			if(str1[i]==str1[j]){
				
				++contStr1;
			}
		}
		
		for(k=0; k<tamStr2; k++){
			
			if(str1[i]==str2[k]){
				
				++contStr2;
			}
		}
		
		if(contStr1!=contStr2){
			
			printf("\nNao sao anagramas.\n");
			return 0;
		}
	}
	
	printf("\nSao anagramas.\n");

	return 0;
}
