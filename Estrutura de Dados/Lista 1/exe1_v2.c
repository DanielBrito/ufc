#include<stdio.h>

int main(){
	
    float nota[3], peso[3];
    int i, j;
    float mediaPonderada=0, somaPsos=0;
    
    for(i=0; i<3; i++){
    	
    	printf("Nota %d: ", i+1);
    	scanf("%f", &nota[i]);
	}
	
	for(j=0; j<3; j++){
		
		printf("Peso da nota %d: ", j+1);
		scanf("%f", &peso[j]);
		
		somaPesos += peso[j];
	}
	
	for(i=0, j=0; i<3, j<3; i++, j++){
		
		mediaPonderada += nota[i]*peso[i];
	}
	
	mediaPonderada /= somaPesos;
	
	printf("\n\nMedia ponderada: %.2f", mediaPonderada);

    printf("\n\n");

    system("PAUSE");
    return 0;
}
