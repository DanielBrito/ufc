#include<stdio.h>
#include<string.h>
#include<limits.h>

void votosCandidato615(int mat[6][6]);
void homensVotaram312(int mat[6][6]);
void idadeMediaTotal(int mat[6][6]);
void candidatoMaisVotos(int mat[6][6]);
int menorIdadeVotaram312(int mat[6][6]);
int maiorEscolaridadeVotaram312(int mat[6][6]);
float idadeMediaEleitoras(int mat[6][6]);
void votaram615Centro(int mat[6][6]);

int main(){
	
	int matriz[6][6] = {1001,18,2,1,1,615,
						1002,25,2,1,2,615,
						1202,33,1,3,3,312,
						1333,65,1,4,2,615,
						1412,30,1,2,3,312,
						1444,44,2,1,1,615};
						
	printf("     RELATORIO\n\n");
	
	printf("a) Calcule e mostre a quantidade de votos do candidato 615\n");
	votosCandidato615(matriz);
	printf("\n\n");
	
	printf("b) Calcule e mostre a quantidade de homens que votaram no candidato 312\n");
	homensVotaram312(matriz);
	printf("\n\n");
	
	printf("c) Calcule e mostre a idade media dos seis eleitores\n");
	idadeMediaTotal(matriz);
	printf("\n\n");
	
	printf("d) Mostre qual candidato recebeu mais votos\n");
	candidatoMaisVotos(matriz);
	printf("\n\n");
	
	printf("e) Retorne a menor idade dentre os eleitores do candidato 312\n");
	int menorIdade312 = menorIdadeVotaram312(matriz);
	printf("%d\n\n", menorIdade312);
	
	printf("f) Retorne a maior escolaridade dentre os eleitores do candidato 312\n");
	int maiorEscolaridade312 = maiorEscolaridadeVotaram312(matriz);
	printf("%d\n\n", maiorEscolaridade312);
	
	printf("g) Retorne a media das eleitoras (sexo feminino)\n");
	float mediaEleitoras = idadeMediaEleitoras(matriz);
	printf("%.2f\n\n", mediaEleitoras);
	
	printf("h) Mostre a quatidade de pessoas que moram no Centro e votaram 615\n");
	votaram615Centro(matriz);	
	
	printf("\n\n");
	
	return 0;
}


void votosCandidato615(int mat[6][6]){
	
	int i, j=5, cont=0;
	
	for(i=0; i<6; i++){
		
		if(mat[i][j]==615){
			
			++cont;
		}
	}
	
	printf("%d", cont);
}

void homensVotaram312(int mat[6][6]){
	
	int i, cont=0, sexo=0, voto=0;
	
	for(i=0; i<6; i++){
				
		if(mat[i][2]==2 && mat[i][5]==312){
				
			++cont;	
		}
	}
	
	printf("%d", cont);
}

void idadeMediaTotal(int mat[6][6]){
	
	int i, j=1, soma=0;
	float media;
	
	for(i=0; i<6; i++){
		
		soma += mat[i][j];
	}
	
	media = (float)soma/6;
	
	printf("%.2f", media);
}

void candidatoMaisVotos(int mat[6][6]){
	
	int i, j=5;
	int cont615=0, cont312=0;
	
	for(i=0; i<6; i++){
		
		if(mat[i][j]==615){
			
			++cont615;
		}
		else{
			
			++cont312;
		}
	}
	
	if(cont312>cont615){
		
		printf("312");
	}
	else{
		
		printf("615");
	}
}

int menorIdadeVotaram312(int mat[6][6]){
	
	int i, menor=INT_MAX;
	
	for(i=0; i<6; i++){
		
		if(mat[i][5]==312){
			
			if(mat[i][1]<menor){
				
				menor = mat[i][1];
			}
		}
	}
	
	return menor;
}

int maiorEscolaridadeVotaram312(int mat[6][6]){
	
	int i, maior=INT_MIN;
	
	for(i=0; i<6; i++){
		
		if(mat[i][5]==312){
			
			if(mat[i][3]>maior){
				
				maior = mat[i][3];
			}
		}
	}
	
	return maior;
}

float idadeMediaEleitoras(int mat[6][6]){
	
	int i, soma=0, cont=0;
	float media=0;
	
	for(i=0; i<6; i++){
		
		if(mat[i][2]==1){
			
			soma += mat[i][1];
			++cont;
		}
	}
	
	media = (float)soma/cont;
	
	return media;
}

void votaram615Centro(int mat[6][6]){
	
	int i, cont=0;
	
	for(i=0; i<6; i++){
		
		if(mat[i][4]==1 && mat[i][5]==615){
			
			++cont;
		}
	}
	
	printf("%d", cont);
}
