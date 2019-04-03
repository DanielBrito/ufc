/* Estudos práticos de switch-case e laços de repetição */

#include<stdio.h>

int main(){
	
	float n1, n2;
	char oper, op;
	int continuar=1; // Variável utilizada para verificar se o usuário deseja realizar outra operação no laço de repetição
	
	while(continuar==1){ // Se o resultado da operação (==) for verdade, continua a execução, caso contrário, quebra o laço de repetição
		
		printf("\t# CALCULADORA #\n\n");
	
		printf("Digite a operacao: ");
		scanf("%f%c%f", &n1, &oper, &n2); // Recebe a operação completa, por exemplo: 1+1
		
		switch(oper){ // Indexa a operação digitada pelo usuário (oper) e efetua o respectivo cálculo
			
			case '+': printf("\n%.2f %c %.2f = %.2f\n", n1, oper, n2, n1+n2); // Se oper for +, realiza a soma e para a execução com o break
					  break;
			
			case '-': printf("\n%.2f %c %.2f = %.2f\n", n1, oper, n2, n1-n2); // Se oper for -, realiza a subtração e para a execução com o break
					  break;
			
			case '*': printf("\n%.2f %c %.2f = %.2f\n", n1, oper, n2, n1*n2); // Se oper for *, realiza a multiplicação e para a execução com o break
			          break;
			
			case '/': if(n2==0){ // Verifica se o divisor é 0
				
				          printf("\nNao e possivel dividir por 0."); // Se n2 for 0, exibe mensagem de erro e para a execução com o break
				          break;
					  }
					  else{ // Se n2 for diferente de 0, efetua operação de divisão e para a execução com o break
					  	
					      printf("\n%.2f %c %.2f = %.2f", n1, oper, n2, n1/n2);
					      break;
					  }
					     
			default : printf("\nOperacao invalida."); // Caso o usuário digite uma operação inválida como 1@2
		}

        // Código para controlar a quantidade de operações que usuário deseja realizar:
		
		printf("\n\nDeseja realizar outra operacao? (s/n): ");
		scanf(" %c", &op);
		
		if(op=='s'){
			
			continuar = 1; // continuar é verdade
		}
		else{
			
			continuar = 0; // continuar é falso
		}
		
		printf("\n\n");
	}
	
	printf("Ate a proxima!");
	
	return 0;	
}
