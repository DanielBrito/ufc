#include<stdio.h>
#include<stdlib.h>

struct funcionario{
	
	float salario;
	float vendas;
};

typedef struct funcionario Funcionario;

int main(){
	
	float comissao, salarioFinal;
	Funcionario func;
	
	printf("Digite o valor do salario: ");
	scanf("%f", &func.salario);
	printf("Digite o valor das vendas: ");
	scanf("%f", &func.vendas);
	
	comissao = func.vendas * 0.06;
	salarioFinal = func.salario + comissao;
	
	printf("\n\n");
	
	printf("Comissao: %.2f\n", comissao);
	printf("Salario Final: %.2f", salarioFinal);
	
	printf("\n\n");
	
	return 0;
}
