#include<stdio.h>

int main(){
	
	float n1, n2;
	char oper, op;
	int continuar=1;
	
	do{

        system("cls");
		
		printf("  # C-alc #\n\n");
		
		printf(" 7  8  9   +\n");
		printf(" 4  5  6   -\n");
		printf(" 1  2  3   *\n");
		printf("    0      /\n\n");
	
		printf("Calcule: ");
		scanf("%f%c%f", &n1, &oper, &n2);
		
		switch(oper){
			
			case '+': printf("Resultado: %.2f\n", n1+n2);
					  break;
			
			case '-': printf("Resultado: %.2f\n", n1-n2);
					  break;
			
			case '*': printf("Resultado: %.2f\n", n1*n2);
			          break;
			
			case '/': if(n2==0){
				
				          printf("Nao e possivel dividir por 0.\n");
				          break;
					  }
					  else{
					  	
					      printf("Resultado: %.2f", n1/n2);
					      break;
					  }
					     
			default : printf("Operacao invalida.\n");
		}
		
		fflush(stdin);
		
		printf("\nDeseja realizar outra operacao? (s/n): ");
		scanf("%c", &op);

        op=='s' ? (continuar=1): (continuar=0);
        
	}while(continuar==1);
	
	printf("\nAte a proxima!\n");
	
	return 0;	
}
