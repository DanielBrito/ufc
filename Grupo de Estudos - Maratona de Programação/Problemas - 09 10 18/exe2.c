#include<stdio.h>
#include<stdlib.h>

#define N 100000

struct pilha{

    int topo;
    int v[N];
};

typedef struct pilha Pilha;

Pilha* cria(void);
void push(Pilha* p, int v);
int pop(Pilha* p);
int vazia(Pilha* p);
void libera(Pilha* p);

int main(){
	
	int n, i, carta, atual=1, rodadas=0;
	
	printf("Quantidade de cartas do baralho: ");
	scanf("%d", &n);
	
	Pilha* compra = cria();
	
	printf("\n");
	
	for(i=0; i<n; i++){
		
		printf("%da carta: ", i+1);
		scanf("%d", &carta);
		
		push(compra, carta);
	}
	
	Pilha* morto = cria();
	Pilha* descarte = cria();
	
	while(atual<=n){
		
		while(!vazia(compra) && atual<=n){
			
			carta = pop(compra);
		
			if(carta==atual){
				
				push(morto, carta);
				++atual;
			}
			else{
				
				push(descarte, carta);
			}			
		}
		
		++rodadas;
		
		while(!vazia(descarte)){
			
			push(compra, pop(descarte));
		}
	}
	
	printf("\nQuantidade de rodadas: %d\n", rodadas);
	
	libera(compra);
	libera(morto);
	libera(descarte);	
	
	return 0;
}

Pilha* cria(void){

    Pilha* p;

    p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = 0;

    return p;
}

void push(Pilha* p, int v){

    if(p->topo == N){

        printf("Erro! Pilha cheia!\n");
        exit(1);
    }

    p->v[p->topo] = v;
    p->topo++;
}

int pop(Pilha* p){

    int aux;

    if(vazia(p)){

        printf("Erro! Pilha vazia!\n");
        exit(1);
    }

    aux = p->v[p->topo-1];
    p->topo--;

    return aux;
}

int vazia(Pilha* p){

    return p->topo == 0;
}

void libera(Pilha* p){

    free(p);
}
