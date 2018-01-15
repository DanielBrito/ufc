#include<stdio.h>
#include<stdlib.h>

char* cargo(float cod);
float atualizaSalario(float cod, float salario);

int main(){
	
	float tabela[5][3];
	float codigo, salario, aumento;
	int i, j;
	
	for(i=0; i<5; i++){
		
		printf("FUNCIONARIO %d\n", i+1);
		
		for(j=0; j<2; ){
			
			printf("Digite o codigo do cargo: ");
			scanf("%f", &codigo);
			
			tabela[i][j++] = codigo;
			
			printf("Digite o salario (R$): ");
			scanf("%f", &salario);
			
			tabela[i][j++] = salario;
			
			tabela[i][j++] = atualizaSalario(codigo, salario);
		}
		
		printf("\n");
	}
	
	printf("\n\nRELATORIO\n\n");
	
	printf("Cargo\t\t\tSalario\t\tNovo salario\n\n");
	
	for(i=0; i<5; i++){
		
		for(j=0; j<3; ){
			
			printf("%s", cargo(tabela[i][j++]));
			
			printf("\t\t%.2f", tabela[i][j++]);
			
			printf("\t\t%.2f", tabela[i][j++]);
		}
		
		printf("\n");
	}

	printf("\n\n");
	
	return 0;
}


char* cargo(float cod){
	
	if(cod==1){
		
		return "Secretario";
	}
	
	if(cod==2){
		
		return "Porteiro";
	}
	
	if(cod==3){
		
		return "Assistente";
	}
}

float atualizaSalario(float cod, float salario){
	
	if(cod==1){
		
		return salario*1.3;
	}
	
	if(cod==2){
		
		return salario*1.25;
	}
	
	if(cod==3){
		
		return salario*1.2;
	}
}
