#include<stdio.h>
#include<stdlib.h>

// Assinatura da função que recebe três argumentos (dois ponteiros do tipo inteiro e um inteiro):
// Os dois primeiros, farão referência à primeira posição de memória dos respectivos vetores com os valores a serem somados.
// O terceiro se refere ao tamanho destes vetores, auxiliando na criação do vetor resultado, que possuirá o mesmo tamanho.
int* somaVetores(int* vetA, int* vetB, int tamanho);

int main(){
	
	int tamanhoA, tamanhoB, i;

	printf("Digite o tamanho do vetor A: ");
	scanf("%d", &tamanhoA);

	printf("Digite o tamanho do vetor B: ");
	scanf("%d", &tamanhoB);

	if(tamanhoA != tamanhoB){ // Se os tamanhos forem diferentes, terminar de imediato

		printf("\nOs vetores possuem tamanhos diferentes!\n");

		return 1;
	}

	// Alocando memória para os vetores A e B
	int* vetA = (int*)malloc(sizeof(int)*tamanhoA);
	int* vetB = (int*)malloc(sizeof(int)*tamanhoB);

	// Recebendo valores para o vetor A:
	printf("\nVETOR A:\n");

	for(i=0; i<tamanhoA; i++){

		printf("Digite o %do elemento: ", i+1);
		scanf("%d", &vetA[i]);
	}

	// Recebendo valores para o vetor B:
	printf("\nVETOR B:\n");

	for(i=0; i<tamanhoB; i++){

		printf("Digite o %do elemento: ", i+1);
		scanf("%d", &vetB[i]);
	}

	// Ponteiro que fará referência à primeira posição de memória do nosso vetor com o resultado:
	int* resultado;

	// Chamada da função passando os dados convenientes para a operação, conforme explicado no início.
	// No retorno da função, poderemos ter acesso à posição de memória do primeiro elemento do resultado.
	// Pode ser enviado tanto o tamanhoA quanto o tamanhoB, pois ambos possuem valores iguais.
	resultado = somaVetores(vetA, vetB, tamanhoA);

	// Feito isso, podemos imprimir todos os elementos:
	printf("\nRESULTADO:\n");

	for(i=0; i<tamanhoA; i++){ // O vetor resultado possui tamanho igual ao vetor A e B

		printf("[%d] ", resultado[i]);
	}
	
	return 0;
}

int* somaVetores(int* vetA, int* vetB, int tamanho){ // Implementação da função
	
	int i;

	// Alocando memória para o vetor que conterá o resultado:
	int* soma = (int*)malloc(sizeof(int)*tamanho);

	for(i=0; i<tamanho; i++){

		// Somando os respectivos valores do vetor A e B na posição i e armazenando no vetor resultado na posição i:
		soma[i] = vetA[i] + vetB[i];
	}

	return soma; // Retornando a referência da primeira posição de memória do vetor com o resultado
}
