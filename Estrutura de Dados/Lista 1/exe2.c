#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int raizes(float a, float b, float c, float* x1, float* x2);

int main()
{
	float a, b, c, x1, x2, delta;
	int op=-1;
	
	do
	{		
		system("cls");
		
		printf("      # FUNCAO QUADRATICA: ax^2 + bx + c #\n\n");
	
		printf("Digite o valor de a: ");
		scanf("%f", &a);
		
		if(a==0)
		{
			printf("ATENCAO: O valor de a tem que ser diferente de 0!\n\n");
			
			system("PAUSE");
		}
		
	}while(a==0);
		
	printf("Digite o valor de b: ");
	scanf("%f", &b);
		
	printf("Digite o valor de c: ");
	scanf("%f", &c);
		
	raizes(a, b, c, &x1, &x2);
	
	printf("\n");
	
	printf("x1 = %2.f e x2 = %2.f", x1, x2);	
	
	printf("\n\n");
	
	printf("\nDeseja executar novamente? (1 - SIM / 0 - NAO): ");
    scanf("%d", &op);
    
    printf("\n\n");

    if(op==1){
    	
        main();
    }
    else{
        
		system("PAUSE");
		return 0;
    }
}


int raizes(float a, float b, float c, float* x1, float* x2){
	
	float delta=0;
	
	delta = (b*b)-(4*a*c);
	
	printf("\nDelta = %.2f\n", delta);
		
	if(delta<0){
		
		printf("\nNao existem raizes reais para delta < 0.\n\n");
		
		exit(0);
	}
	else{
		
		*x1 = (-b + sqrt(delta))/(2*a);
    	*x2 = (-b - sqrt(delta))/(2*a);			
	}
}
