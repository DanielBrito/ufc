#include<stdio.h>

int main(){
	
    int num, i, j;

    printf("Digite um numero: ");
    scanf("%d", &num);

    printf("\n");

    for(i=0; i<num; i++){
    	
        for(j=0; j<=i; j++){
        	
            printf("%d", j+1);
        }

        printf("\n");
    }

    printf("\n");

	system("PAUSE");
    return 0;
}
