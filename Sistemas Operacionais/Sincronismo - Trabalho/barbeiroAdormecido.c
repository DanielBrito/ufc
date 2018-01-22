#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

#define QTD_CLIENTES 20
#define SALA_DE_ESPERA 4
#define TRUE 1

int qtdClientesAguardando = 0;
int idCliente[QTD_CLIENTES];

sem_t clientes;
sem_t barbeiro;
sem_t mutex;

void* rotinaBarbeiro(void* arg);
void* rotinaCliente(int* id);


int main(){

	sem_init(&clientes, TRUE, 0);
	sem_init(&barbeiro, TRUE, 0);
	sem_init(&mutex, TRUE, 1);

	pthread_t thBarbeiro;
	pthread_t thCliente[QTD_CLIENTES];			

	int j=0, i=0;

 	pthread_create(&thBarbeiro, NULL, (void*)rotinaBarbeiro, NULL);

 	for(j=0; j<QTD_CLIENTES; j++){

 		idCliente[j] = j+1;

 		pthread_create(&thCliente[j], NULL, (void*)rotinaCliente, (int*)&idCliente[j]);
 		sleep(1);
 	}

	for(i=0; i<QTD_CLIENTES; i++){

		pthread_join(thCliente[i], NULL);
	}

	printf("Acabou o expediente do barbeiro.\n");

	return 0;
}


void* rotinaBarbeiro(void* arg){

	while(TRUE) {

		sem_wait(&clientes);
		sem_wait(&mutex);
		
		qtdClientesAguardando = qtdClientesAguardando - 1;
		
		sem_post(&barbeiro);
		sem_post(&mutex);
		
		printf("Um cliente está tendo o cabelo cortado.\n");

		sleep(3);

	}

	pthread_exit(NULL);
}


void* rotinaCliente(int* id){

	sem_wait(&mutex);

	if(qtdClientesAguardando < SALA_DE_ESPERA){
	
		printf("O cliente %d chegou para cortar cabelo!\n", *id);
		
		qtdClientesAguardando = qtdClientesAguardando + 1;
		
		sem_post(&clientes);
		sem_post(&mutex);
		
		sem_wait(&barbeiro);
		
		printf("O cliente %d teve o cabelo cortado!\n", *id);
	} 
	else{

		sem_post(&mutex);
		
		printf("O cliente %d desistiu. O salão está cheio.\n", *id);
	}

	pthread_exit(NULL);
}