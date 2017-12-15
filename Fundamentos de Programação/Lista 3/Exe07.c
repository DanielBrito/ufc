#include<stdio.h>

int main(){
	
	int t, j, idade, altura, menorDeIdade=0, somaIdades=0;
	float peso, mediaIdades=0, somaAltura=0, mediaAltura=0, pesamMaisQue80=0, porcentagem=0;
	
	for(t=0; t<5; t++){
		
		somaIdades = 0;
		
		printf("TIME %d\n\n", t+1);
		
		for(j=0; j<11; j++){
			
			printf("JOGADOR %d\n", j+1);
			printf("Idade: ");
			scanf("%d", &idade);
			
			somaIdades = somaIdades + idade;
			
			if(idade<18){
				
				++menorDeIdade;
			}
			
			printf("Altura: ");
			scanf("%d", &altura);
			
			somaAltura = somaAltura + altura;
			
			printf("Peso: ");
			scanf("%f", &peso);
			
			if(peso>80){
				
				++pesamMaisQue80;
			}
		}
		
		printf("\nMedia das idades: %.2f\n\n", somaIdades/11);
	}
	
	mediaAltura = somaAltura/55;
	
	// Cada jogador representa, aproximadamente, 1.81% do total
	porcentagem = (100/55)*pesamMaisQue80;
	
	printf("\tRELATORIO\n");
	printf("Quantidade de jogadores com menos de 18 anos: %d\n", menorDeIdade);
	printf("Media das alturas de todos os jogadores do campeonato: %.2f", mediaAltura);
	printf("Porcentagem de jogadores com mais de 80Kg: %.2f", porcentagem);
	
	printf("\n\n");
	
	system("PAUSE");
	return 0;
}
