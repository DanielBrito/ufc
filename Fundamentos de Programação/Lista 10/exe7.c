#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct ponto{
	
	float x;
	float y;
};

typedef struct ponto Ponto;

float distancia(Ponto* a, Ponto* b);

int main(){
	
	Ponto pA, pB;
	
	printf("PONTO A\n");
	printf("x = ");
	scanf("%f", &pA.x);
	printf("y = ");
	scanf("%f", &pA.y);
	
	printf("\n\n");
	
	printf("PONTO B\n");
	printf("x = ");
	scanf("%f", &pB.x);
	printf("y = ");
	scanf("%f", &pB.y);
	
	printf("\n\n");
	
	printf("Distancia entre o ponto A e B: %.2f", distancia(&pA, &pB));
	
	printf("\n\n");
	
	return 0;
}


float distancia(Ponto* a, Ponto* b){
	
	return (sqrt(pow((b->x - a->x),2) + pow((b->y - a->y),2)));
}
