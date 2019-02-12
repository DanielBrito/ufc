#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int qtdAlunos, i, j, cont=0, igual=0;
	
	printf("Digite a quantidade de alunos: ");
	scanf("%d", &qtdAlunos);
	
	int* registros=(int*)malloc(sizeof(int)*qtdAlunos);
	
	printf("\n");
	
	for(i=0; i<qtdAlunos; i++){
		
		printf("Registro do %do aluno: ", i+1);
		scanf("%d", &registros[i]);
	}
	
	for(i=0; i<qtdAlunos-1; i++){
		
		igual=0;
		
		for(j=i+1; j<qtdAlunos; j++){
			
			if(registros[i]==registros[j]){
				
				++igual;
			}
		}
		
		if(igual==0){
			
			++cont;
		}
	}
	
	printf("\nQuantidade de alunos presentes: %d\n", cont+1);	
	
	return 0;
}
