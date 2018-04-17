#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "operacoes.h"

void menu(){

	int op=-1, i;

	system("clear");

	printf("#######################################\n");
	printf("         CALCULADORA - BIG INT         \n");
	printf("#######################################\n\n");

	printf("1 - ADIÇÃO\n");
	printf("2 - COMPARAÇÃO\n");
	printf("3 - QUADRADO\n");
	printf("4 - MULTIPLICAÇÃO\n");
	printf("5 - MDC\n");
	printf("6 - FATORIAL\n");
	printf("7 - EXPONENCIAÇÃO\n");
	printf("8 - MÓDULO\n");
	printf("0 - SAIR\n\n");

	printf("- > ");
	scanf("%d", &op);

	if(op==0) exit(0);

	char *ch1 = (char*)malloc(sizeof(char));
	char *ch2 = (char*)malloc(sizeof(char));

	switch(op){

		case 1: system("clear");

				printf("#######################################\n");
				printf("                 SOMA                  \n");
				printf("#######################################\n\n");

				Lista* parcela1 = cria();
				Lista* parcela2 = cria();

				printf("Digite a primeira parcela: ");
				scanf("%s", ch1);

				for(i=0; i<strlen(ch1); i++){

					parcela1 = lerNumero(parcela1, ch1[i]);
				}

				printf("Digite a segunda parcela: ");
				scanf("%s", ch2);

				for(i=0; i<strlen(ch2); i++){

					parcela2 = lerNumero(parcela2, ch2[i]);
				}

				parcela1 = removeZeroInicio(parcela1);
				parcela2 = removeZeroInicio(parcela2);

				printf("\nResultado = ");
				imprime(adicao(parcela1, parcela2));

				printf("\n\n");

				libera(parcela1); libera(parcela2);

				printf("RETORNAR? 0-NÃO | 1-SIM: ");
				scanf("%d", &op);

				if(op==0){

					free(ch1); free(ch2); exit(0);
				}
				
				menu();

		case 2: system("clear");

				printf("#######################################\n");
				printf("              COMPARAÇÃO               \n");
				printf("#######################################\n\n");

				Lista* numero1 = cria();
				Lista* numero2 = cria();

				printf("Digite o primeiro número: ");
				scanf("%s", ch1);

				for(i=0; i<strlen(ch1); i++){

					numero1 = lerNumero(numero1, ch1[i]);
				}

				printf("Digite o segundo número: ");
				scanf("%s", ch2);

				for(i=0; i<strlen(ch2); i++){

					numero2 = lerNumero(numero2, ch2[i]);
				}

				numero1 = removeZeroInicio(numero1);
				numero2 = removeZeroInicio(numero2);

				printf("\n");

				if(compara(numero1, numero2)==-1){

					printf("O primeiro número é menor que o segundo.\n");
				}
				else
				if(compara(numero1, numero2)==1){

					printf("O primeiro número é maior que o segundo.\n");
				}
				else
				if(compara(numero1, numero2)==0){

					printf("Os números são iguais.\n");
				}

				libera(numero1); libera(numero2);

				printf("\n");

				printf("RETORNAR? 0-NÃO | 1-SIM: ");
				scanf("%d", &op);

				if(op==0){

					free(ch1); free(ch2); exit(0);
				}
				
				menu();

		case 3: system("clear");

				printf("#######################################\n");
				printf("                QUADRADO               \n");
				printf("#######################################\n\n");

				Lista* numeroQuad = cria();

				printf("Digite um número: ");
				scanf("%s", ch1);

				for(i=0; i<strlen(ch1); i++){

					numeroQuad = lerNumero(numeroQuad, ch1[i]);
				}

				numeroQuad = removeZeroInicio(numeroQuad);

				printf("\nResultado = ");
				imprime(quadrado(numeroQuad));

				printf("\n\n");

				libera(numeroQuad);

				printf("RETORNAR? 0-NÃO | 1-SIM: ");
				scanf("%d", &op);

				if(op==0){

					free(ch1); free(ch2); exit(0);
				}
				
				menu();

		case 4: system("clear");

				printf("#######################################\n");
				printf("             MULTIPLICAÇÃO             \n");
				printf("#######################################\n\n");

				Lista* fator1 = cria();
				Lista* fator2 = cria();

				printf("Digite o primeiro fator: ");
				scanf("%s", ch1);

				for(i=0; i<strlen(ch1); i++){

					fator1 = lerNumero(fator1, ch1[i]);
				}

				printf("Digite o segundo fator: ");
				scanf("%s", ch2);

				for(i=0; i<strlen(ch2); i++){

					fator2 = lerNumero(fator2, ch2[i]);
				}

				fator1 = removeZeroInicio(fator1);
				fator2 = removeZeroInicio(fator2);

				printf("\nResultado = ");
				imprime(produto(fator1, fator2));

				printf("\n\n");

				libera(fator1); libera(fator2);

				printf("RETORNAR? 0-NÃO | 1-SIM: ");
				scanf("%d", &op);

				if(op==0){

					free(ch1); free(ch2); exit(0);
				}
				
				menu();

		case 5: system("clear");

				printf("#######################################\n");
				printf("                  MDC                  \n");
				printf("#######################################\n\n");

				Lista* numero1Mdc = cria();
				Lista* numero2Mdc = cria();

				printf("Digite o primeiro número: ");
				scanf("%s", ch1);

				for(i=0; i<strlen(ch1); i++){

					numero1Mdc = lerNumero(numero1Mdc, ch1[i]);
				}

				printf("Digite o segundo número: ");
				scanf("%s", ch2);

				for(i=0; i<strlen(ch2); i++){

					numero2Mdc = lerNumero(numero2Mdc, ch2[i]);
				}

				numero1Mdc = removeZeroInicio(numero1Mdc);
				numero2Mdc = removeZeroInicio(numero2Mdc);

				printf("\nResultado = ");
				imprime(mdc(numero1Mdc, numero2Mdc));

				printf("\n\n");

				libera(numero1Mdc); libera(numero2Mdc);
				
				printf("RETORNAR? 0-NÃO | 1-SIM: ");
				scanf("%d", &op);

				if(op==0){

					free(ch1); free(ch2); exit(0);
				}
				
				menu();

		case 6: system("clear");

				printf("#######################################\n");
				printf("               FATORIAL                \n");
				printf("#######################################\n\n");

				Lista* numeroFat = cria();

				printf("Digite um número: ");
				scanf("%s", ch1);

				for(i=0; i<strlen(ch1); i++){

					numeroFat = lerNumero(numeroFat, ch1[i]);
				}

				numeroFat = removeZeroInicio(numeroFat);

				printf("\nResultado = ");
				imprime(fatorial(numeroFat));

				printf("\n\n");

				libera(numeroFat);

				printf("RETORNAR? 0-NÃO | 1-SIM: ");
				scanf("%d", &op);

				if(op==0){

					free(ch1); free(ch2); exit(0);
				}
				
				menu();

		case 7: system("clear");

				printf("#######################################\n");
				printf("             EXPONENCIAÇÃO             \n");
				printf("#######################################\n\n");

				Lista* base = cria();
				Lista* expoente = cria();

				printf("Digite a base: ");
				scanf("%s", ch1);

				for(i=0; i<strlen(ch1); i++){

					base = lerNumero(base, ch1[i]);
				}

				printf("Digite o expoente: ");
				scanf("%s", ch2);

				for(i=0; i<strlen(ch2); i++){

					expoente = lerNumero(expoente, ch2[i]);
				}

				base = removeZeroInicio(base);
				expoente = removeZeroInicio(expoente);

				printf("\nResultado = ");
				imprime(expo(base, expoente));

				printf("\n\n");

				libera(base); libera(expoente);

				printf("RETORNAR? 0-NÃO | 1-SIM: ");
				scanf("%d", &op);

				if(op==0){

					free(ch1); free(ch2); exit(0);
				}
				
				menu();

		case 8: system("clear");

				printf("#######################################\n");
				printf("                MÓDULO                 \n");
				printf("#######################################\n\n");

				Lista *divisor = cria();
				Lista *dividendo = cria();

				printf("Digite o dividendo: ");
				scanf("%s", ch1);

				for(i=0; i<strlen(ch1); i++){

					dividendo = lerNumero(dividendo, ch1[i]);
				}

				printf("Digite o divisor: ");
				scanf("%s", ch2);

				for(i=0; i<strlen(ch2); i++){

					divisor = lerNumero(divisor, ch2[i]);
				}

				dividendo = removeZeroInicio(dividendo);
				divisor = removeZeroInicio(divisor);

				printf("\nResultado = ");
				imprime(modulo(dividendo,divisor));

				libera(divisor); libera(dividendo);

				printf("\n\n");
				
				printf("RETORNAR? 0-NÃO | 1-SIM: ");
				scanf("%d", &op);

				if(op==0){ 

					free(ch1); free(ch2); exit(0);
				}

				menu();

		case 0: free(ch1); free(ch2); exit(0);

		default: menu();
	}
}

Lista* lerNumero(Lista* l, char ch){

	l = insereFinal(l, ch);

	return l;
}

Lista* adicao(Lista* lA, Lista* lB){

	No* auxLA = acessaFim(lA), *auxLB = acessaFim(lB);
	Lista* result = cria();

	int carry = 0;

	if(lA == NULL){

		return lB;
	}
	else 
	if(lB == NULL){

		return lA;
	}

	while(auxLA!=NULL && auxLB!=NULL){

		int digA = acessaDigito(auxLA) + carry;
		int digB = acessaDigito(auxLB);

		int soma = digA + digB;

		if(soma >= 10){

			result = insereInicio(result, converteChar(soma%10));
			carry = 1;
		}
		else{

			result = insereInicio(result, converteChar(soma));
			carry = 0;
		}
		
		auxLA = acessaAnt(auxLA);
		auxLB = acessaAnt(auxLB);
	}

	if(auxLA!=NULL && auxLB==NULL){

		while(auxLA!=NULL){

			int soma = acessaDigito(auxLA) + carry;

			if(soma >= 10){

				result = insereInicio(result, converteChar(soma%10));
				carry = 1;
			}
			else{

				result = insereInicio(result, converteChar(soma));
				carry = 0;
			}

			auxLA = acessaAnt(auxLA);
		}

	}

	if(auxLA==NULL && auxLB!=NULL){

		while(auxLB!=NULL){

			int soma = acessaDigito(auxLB) + carry;

			if(soma >= 10){

				result = insereInicio(result, converteChar(soma%10));
				carry = 1;
			}
			else{

				result = insereInicio(result, converteChar(soma));
				carry = 0;
			}

			auxLB = acessaAnt(auxLB);
		}

	}

	if(carry == 1){

		result = insereInicio(result, converteChar(1));	
	}

	return result;
}

int compara(Lista* lA, Lista* lB){

	No* auxLA = acessaNo(lA);
	No* auxLB = acessaNo(lB);

	if(contaDigitos(lA) < contaDigitos(lB)){

		return -1;
	}
	else 
	if(contaDigitos(lA) > contaDigitos(lB)){

		return 1;
	}

	while(auxLA!=NULL && auxLB!=NULL){

		if(acessaDigito(auxLA) < acessaDigito(auxLB)){

			return -1;
		}

		if(acessaDigito(auxLA) > acessaDigito(auxLB)){

			return 1;
		}

		auxLA = acessaProx(auxLA);
		auxLB = acessaProx(auxLB);
	}
}

Lista* quadrado(Lista* l){

	return produto(l, l);
}

Lista* produto(Lista* lA, Lista* lB){

	Lista* result1 = cria(), *result2 = cria();
	No* auxLB = acessaFim(lB);
	int y=0, i;

	result1 = insereFinal(result1, '0');
	result2 = insereFinal(result2, '0');

	while(auxLB!=NULL){

		for(i=0; i<acessaDigito(auxLB); i++){

			result1 = adicao(result1, lA);
		}

		if(y>0){

			for(i=0; i<y; i++){

				result1 = insereFinal(result1, '0');
			}
		}

		y++;

		result2 = adicao(result1, result2);
		result1 = cria();

		result1 = insereFinal(result1, '0');

		auxLB = acessaAnt(auxLB);
	}

	return result2;
}

Lista* mdc(Lista* lA, Lista* lB){

	Lista* zero = cria();
	zero = insereFinal(zero, '0');

	if(compara(lA,lB) == 0){

		return lB;
	}

	if(compara(zero,lB) == 0 || compara(zero,lA) == 0){

		return NULL;
	}

	Lista* resto1;
	Lista* resto2;
	
	Lista* mdc = cria();
	
	mdc = insereFinal(mdc, '0');

	if(compara(lA,lB)==1){
		
		mdc = adicao(lB, mdc);

		resto1 = modulo(lA, mdc);
		resto2 = modulo(lB, mdc);
	
		while(compara(resto1, zero) != 0 || compara(resto2, zero) != 0){

			mdc = subtrai(mdc);

			resto1 = modulo(lA, mdc);
			resto2 = modulo(lB, mdc);
		}

		return mdc;
	}
	else{

		mdc = adicao(lA, mdc);

		resto1 = modulo(lA, mdc);
		resto2 = modulo(lB, mdc);

		while(compara(resto1, zero) != 0 || compara(resto2, zero) != 0){

			mdc = subtrai(mdc);

			resto1 = modulo(lA, mdc);
			resto2 = modulo(lB, mdc);
		}

		return mdc;
	}

}

Lista* fatorial(Lista* l){

	Lista* result = cria(), *zero = cria();
	zero = insereFinal(zero, '0');
	result = insereFinal(result, '0');
	result = adicao(result, l);

	if(compara(zero, l) == 0){

		Lista * aux = cria();
		aux = insereFinal(aux, '1');

		return aux;
	}

	l = subtrai(l);

	while(l != NULL){

		if(compara(zero, l) == 0){

			break;
		}
		else{

			result = produto(result, l);
			l = subtrai(l);
		}
	}

	return result;
}

Lista* expo(Lista* lA, Lista* lB){

	Lista *zero = cria(), *result = cria();
	zero = insereFinal(zero, '0');
	result = insereFinal(result, '1');

	while(compara(zero, lB) != 0){

		result = produto(result,lA);
		lB = subtrai(lB);
	}

	return result;
}

Lista* modulo(Lista* lA, Lista* lB){

	Lista* result = cria();
	result = insereFinal(result, '0');
	int x = 0, i;

	if(compara(result,lB)==0){

		return NULL;
	}

	while(compara(result, lA) != 0 && compara(result, lA) != 1){

		result = adicao(result, lB);
		x++;
	}

	if(compara(result,lA) == 0){

		result = cria();
		result = insereFinal(result,'0');

		return result;
	}
	else{

		result = cria();
		result = insereFinal(result,'0');
		
		for(i=1; i<x; i++){

			result = adicao(result,lB);
		}

		x = 0;

		while(compara(result, lA) != 0){

			lA = subtrai(lA);
			x++;
		}

		if(x > 9){
			
			result = cria();

			while(x>0){

 				result = insereInicio(result,converteChar(x%10));
				x = x/10;
			}
		}
		else{

			result = cria();
			result = insereFinal(result,converteChar(x));
		}

		return result;
	}
}

Lista* subtrai(Lista* l){

	No *aux = acessaFim(l);
	Lista *novo = cria();
	int x;

	while(aux!=NULL){

		if(acessaDigito(aux) == 0){

			novo = insereInicio(novo, '9');
		}
		else{

			x = acessaDigito(aux) -1;
			novo = insereInicio(novo, converteChar(x));

			break;
		}

		aux = acessaAnt(aux);
	}

	aux = acessaAnt(aux);

	while(aux!= NULL){

		x = acessaDigito(aux);
		novo = insereInicio(novo, converteChar(x));
		aux = acessaAnt(aux);
	}

	novo = removeZeroInicio(novo);

	return novo;
}