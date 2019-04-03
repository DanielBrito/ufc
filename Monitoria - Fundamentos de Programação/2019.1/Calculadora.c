/* Estudos práticos de switch-case e laços de repetição */

#include<stdio.h>

int main(){
	
	float n1, n2;
	char oper, op;
	int continuar=1;
	
	while(continuar==1){
		
		printf("\t# CALCULADORA #\n\n");
	
		printf("Digite a operacao: ");
		scanf("%f%c%f", &n1, &oper, &n2);
		
		switch(oper){
			
			case '+': printf("\n%.2f %c %.2f = %.2f\n", n1, oper, n2, n1+n2);
					  break;
			
			case '-': printf("\n%.2f %c %.2f = %.2f\n", n1, oper, n2, n1-n2);
					  break;
			
			case '*': printf("\n%.2f %c %.2f = %.2f\n", n1, oper, n2, n1*n2);
			          break;
			
			case '/': if(n2==0){
				
				          printf("\nNao e possivel dividir por 0.");
				          break;
					  }
					  else{
					  	
					      printf("\n%.2f %c %.2f = %.2f", n1, oper, n2, n1/n2);
					      break;
					  }
					     
			default : printf("\nOperacao invalida.");
		}
		
		printf("\n\nDeseja realizar outra operacao? (s/n): ");
		scanf(" %c", &op);
		
		if(op=='s'){
			
			continuar = 1;
		}
		else{
			
			continuar = 0;
		}
		
		printf("\n\n");
	}
	
	printf("Ate a proxima!");
	
	return 0;	
}
