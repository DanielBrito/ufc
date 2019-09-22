#include "lib.h"

void menu(){

	int op, valor;

    heap *h = NULL;
    
    do{    
        printf("\n\n\tHEAP ESQUERDISTA\n\n");
        printf("1  - INSERIR ELEMENTO\n2  - RETIRAR ELEMENTO\n3 - REMOVER HEAP\n4  - MOSTRAR TODA ESTRUTURA\n0  - SAIR");
        printf("\n\n- > ");
        scanf("%d", &op);
        
        switch(op){
        
    		case 1:{

    			printf("\nInforme um elemento: ");
    			scanf("%d", &valor);

    			heap *novo = cria_heap(valor);

    			h = uniao(h, novo);

    			imprime(h);

				break;
			}
    		
    		case 2: {

    			break;
			}

			case 3: {

				h = remover(h);

				break;
			}
    			
    		case 4:{

				imprime(h); 
				break;
			}
	    }
		
	}while(op!=0);
}

heap* cria_heap(int valor){

	heap* h = (heap*)malloc(sizeof(heap));

	h->elemento = valor;
	h->esq = NULL;
	h->dir = NULL;
	h->densidade = 1;

	return h;
}

heap* remover(heap* h){

	if(h==NULL){

		printf("Heap vazia\n");
		return h;
	}
	else{

		printf("Elemento removido: %d\n", h->elemento);
	}

	return uniao(h->esq, h->dir);
}

void troca_heaps (heap* a, heap*b){
	//TO DO
}

void troca_filhos (heap* a){
	
	heap* temp = a->esq;
	a->esq = a->dir;
	a->dir = temp;
}

heap* uniao(heap * h1, heap* h2) { 
    
	if(h1==NULL) return h2;
	if(h2==NULL) return h1;

	if(h1->elemento > h2->elemento){

		return uniao_heaps(h1, h2);
	}
	else{

		return uniao_heaps(h2, h1);
	}
} 
  
heap* uniao_heaps(heap* h1, heap * h2) { 
    
	if(h1->esq == NULL){

		h1->esq = h2;
	}
	else{

		h1->dir = uniao(h1->dir, h2);

		if(h1->esq->densidade < h1->dir->densidade){

			troca_filhos(h1);
		}

		h1->densidade = h1->dir->densidade+1;
	}

	return h1;
} 


void imprime(heap *h){ 

	printf("<");

	if (h != NULL){

		printf("%d", h->elemento);

		imprime(h->esq);
		imprime(h->dir);
	}    

	printf(">"); 
}
