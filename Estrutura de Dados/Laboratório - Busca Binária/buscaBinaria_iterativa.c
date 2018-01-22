#include<stdio.h>

int buscaBinaria(int x, int n, int *v){
	
	int e, m, d;
	
	e = -1;
	d = n;
	
	while(e<d-1){
		
		m = (e+d)/2;
		
		if(v[m]<x){
			
			e = m;
		}
		else{
			
			d = m;
		}
	}
	
	return d;	
}

int main(){
	
	int vetor[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	int resultado = buscaBinaria(5, 10, vetor); // Valor buscado, tamanho do vetor, vetor
	
	printf("O numero %d foi encontrado no vetor.", resultado);

	printf("\n\n");
	
	return 0;	
}
