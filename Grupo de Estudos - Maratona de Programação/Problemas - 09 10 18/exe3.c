#include<stdio.h>
#include<stdlib.h>

struct lista{

	int indice;
	int info;
	struct lista* prox;
};

typedef struct lista Lista;

Lista* cria();
Lista* insere(Lista* l, int i, int v);
Lista* retira(Lista* l, int i);
void imprime(Lista* l);
void libera(Lista* l);
int getValor(Lista* l);

int main(){

	int p, r, i, j, qtdParticipantes, ordem, valor, vencedor=0, indiceP=0, indiceA=0;
	Lista* resultado = cria();
	Lista* acao;
	Lista* participantes;

	while(1){

		indiceP = 0;
		indiceA = 0;

		participantes = cria();
		acao = cria();

		printf("Quantidade de Participantes e Rodadas: ");
		scanf("%d %d", &p, &r);

		qtdParticipantes=p;

		if(p==0 && r==0){

			break;
		}
		else{

			printf("\nNumero dos participantes\n");

			for(i=0; i<p; i++){

				printf("%do participante: ", i+1);
				scanf("%d", &valor);

				participantes = insere(participantes, indiceP++, valor);
			}

			// Dados da rodada:

			for(i=0; i<r; i++){

				acao = cria();

				printf("\n\n%da rodada\n", i+1);

				printf("Quantidade de participantes: ");
				scanf("%d", &qtdParticipantes);

				printf("Ordem: ");
				scanf("%d", &ordem);

				printf("\n");

				for(j=0; j<qtdParticipantes; j++){

					printf("Acao do %do participante: ", j+1);
					scanf("%d", &valor);

					acao = insere(acao, indiceA++, valor);
				}

				// Verificar vencedor:

				Lista* auxP;
				Lista* auxA;

				for(auxP=participantes, auxA=acao; auxA!=NULL; auxA=auxA->prox, auxP=auxP->prox){

					if(auxA->info!=ordem){

						participantes = retira(participantes, auxP->indice);
						acao = retira(acao, auxP->indice);
					}
				}
			}

			resultado = insere(resultado, vencedor++, getValor(participantes));
		}

		printf("\n");
	}

	imprime(resultado);

	libera(resultado);
	libera(acao);
	libera(participantes);

	return 0;
}

Lista* cria(){

	return NULL;
}

void libera(Lista* l){

	Lista* p=l;

	while(p!=NULL){

		Lista* t = p->prox;

		free(p);

		p = t;
	}
}

Lista* insere(Lista* l, int i, int v){

	Lista* ant = NULL;
	Lista* aux = l;

	while(aux!=NULL){

		ant = aux;
		aux = aux->prox;
	}

	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->indice = i;
	novo->info = v;

	if(ant==NULL){

		novo->prox = l;
		l = novo;
	}
	else{

		novo->prox = ant->prox;
		ant->prox = novo;
	}

	return l;
}

Lista* retira(Lista* l, int i){

	Lista* ant=NULL;
	Lista* p=l;

	while(p!=NULL && p->indice!=i){

		ant = p;
		p = p->prox;
	}

	if(p==NULL){

		return l;
	}

	if(ant==NULL){

		l = p->prox;
	}
	else{

		ant->prox = p->prox;
	}

	free(p);

	return l;
}

void imprime(Lista* l){

	Lista* p;
	int i=1;

	for(p=l; p!=NULL; p=p->prox){

		printf("\nTeste %d\n", i++);
		printf("%d\n", p->info);
	}
}

int getValor(Lista* l){

	return l->info;
}