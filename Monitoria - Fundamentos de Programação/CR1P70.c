/* Publicado no meu canal @ https://youtu.be/jCFo39EUOp4 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

void cadastrarAdmin();
void exibirMenu();
void exibirSubmenu();
bool autenticarUsuario();
char* criptografarTexto(char* texto);

char texto[100]="";
char senha[20];
char nome[20];
int nivelSeguranca;

int main(){
	
	cadastrarAdmin();
	
	return 0;	
}

void cadastrarAdmin(){
	
	printf("#########################################################\n");
	printf("                    CR1P70 - C4D457R0                    \n");
	printf("#########################################################\n\n");
	
	printf("Digite seu nome: ");
	scanf("%[^\n]s", nome);
	printf("Digite sua senha: ");
	scanf("%s", senha);
	printf("Nivel de seguranca (0-25): ");
	scanf("%d", &nivelSeguranca);
	
	exibirMenu();
}

void exibirMenu(){
	
	int opcao;
	char backup[100];
	
	do{
		
		system("cls");
		
		printf("#########################################################\n");
		printf("                       CR1P70 - M3NU                      \n");
		printf("#########################################################\n\n");
		
		printf("1 - Escrever texto\n");
		printf("2 - Ler texto\n");
		printf("0 - Sair do sistema\n\n");
		printf("- > ");
		scanf("%d", &opcao);
		
		if(opcao==1){
			
			if(autenticarUsuario()==true){
				
				system("cls");
				
				printf("#########################################################\n");
				printf("                    CR1P70 - 35CR3V3R                    \n");
				printf("#########################################################\n\n");
				
				printf("Digite o texto: ");
				scanf("%[^\n]s", texto);
				
				exibirSubmenu();
			}
			else{
				
				system("cls");
				
				printf("#########################################################\n");
				printf("                    CR1P70 - 35CR3V3R                    \n");
				printf("#########################################################\n\n");
				
				printf("Senha invalida!\n");
				
				exibirSubmenu();	
			}
		}
		
		if(opcao==2){
			
			if(autenticarUsuario()==true){
				
				system("cls");
				
				printf("#########################################################\n");
				printf("                     CR1P70 - L317UR4                    \n");
				printf("#########################################################\n\n");
				
				printf("%s\n", texto);
				
				exibirSubmenu();
			}
			else{
				
				system("cls");
				
				printf("#########################################################\n");
				printf("                     CR1P70 - L317UR4                    \n");
				printf("#########################################################\n\n");
				
				strcpy(backup, texto);
				strcpy(backup, criptografarTexto(backup));
				
				printf("%s\n", backup);
				
				exibirSubmenu();
			}
		}
		
		if(opcao==0) exit(0);
			
	}while(opcao!=0);
}

bool autenticarUsuario(){
	
	char s[20];
	
	system("cls");
	
	printf("#########################################################\n");
	printf("                   CR1P70 - 4U73N71C4R                   \n");
	printf("#########################################################\n\n");
	
	printf("Digite sua senha: ");
	scanf("%s", s);
	
	fflush(stdin);
	
	return strcmp(senha, s)==0 ? true : false;
}

void exibirSubmenu(){
	
	int opcao;
	
	printf("\nO que deseja fazer?\n");
	printf("1 - Retornar ao menu\n");
	printf("0 - Sair do sistema\n\n");
	printf("- > ");
	
	scanf("%d", &opcao);
	
	if(opcao==0){
		
		exit(0);
	}
	else{
		
		exibirMenu();
	}
}

char* criptografarTexto(char* texto){
	
	int i;
	
	for(i=0; i<strlen(texto); i++){
		
		if(isalpha(texto[i])){
			
			if(texto[i]+nivelSeguranca>122){
				
				texto[i] += nivelSeguranca-26;
			}
			else{
				
				texto[i] += nivelSeguranca;
			}
		}
	}
	
	return texto;
}