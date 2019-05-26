/* https://www.youtube.com/watch?v=amjq63biyDs */

#include<stdio.h>
#include<string.h>

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
		
		contStr1 += str1[i];
	}
	
	for(j=0; j<tamStr2; j++){
		
		contStr2 += str2[j];
	}
	
	contStr1==contStr2 ? printf("\nSao anagramas.\n") : printf("\nNao sao anagramas.\n");
	
	return 0;
}
