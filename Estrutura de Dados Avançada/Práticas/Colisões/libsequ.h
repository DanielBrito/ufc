#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define MAX 17

typedef struct{
	int chave;
	int valor;
} Telemento;
        
typedef struct{
        Telemento elemento[MAX];
        int n;
        } Tlista;

int hashing(int chave);
void criar(Tlista *);
int tamanho(Tlista);
int elemento(Tlista, int, Telemento *);
void exibir(Tlista L);
//--------------TRATAMENTO DE COLIS�ES----------------//
float taxaOcupacao(Tlista);
int sondagemLinear(Tlista *, Telemento);
int rehashing(Tlista *, Telemento);
int doubleHashing(Tlista*, Telemento);

