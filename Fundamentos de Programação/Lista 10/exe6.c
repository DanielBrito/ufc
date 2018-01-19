#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct pessoa{
	
	char nome[30];
	char cpf[12];
	struct nascimento{
		
		int dia;
		int mes;
		int ano;
	}data;
};

typedef struct pessoa Pessoa;

void lerDados(Pessoa* p);
int verificaCPF(char* cpf);

int main(){
	
	Pessoa p1;
	Pessoa* p = &p1;
	
	lerDados(p);	
	
	printf("\n\n");
	
	return 0;
}


void lerDados(Pessoa* p){
	
	printf("Nome: ");
	scanf(" %[^\n]", p->nome);
	printf("Data de Nascimento\n");
	printf("Dia: ");
	scanf("%d", &p->data.dia);
	printf("Mes: ");
	scanf("%d", &p->data.mes);
	printf("Ano: ");
	scanf("%d", &p->data.ano);
	printf("CPF: ");
	scanf("%s", p->cpf);
	
	if(verificaCPF(p->cpf)==2){
		
		printf("\nO CPF nao tem numeros suficientes.");
	}
	else
	if(verificaCPF(p->cpf)==0){
		
		printf("\nO CPF deve conter somente numeros.");
	}
	else{
		
		printf("\n\nNome: %s\n", p->nome);
		printf("Data da nascimento: %.2d/%.2d/%d\n", p->data.dia, p->data.mes, p->data.ano);
		printf("CPF: %s", p->cpf);
	}
}


int verificaCPF(char* cpf){
	
	int i;
	
	if(strlen(cpf)==11){
		
		for(i=0; i<strlen(cpf); i++){
			
			if(!isdigit(cpf[i])){
				
				return 0;
			}
		}
	}
	else{
		
		return 2;
	}
	
	return 1;
}
