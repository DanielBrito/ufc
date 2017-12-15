#include<stdio.h>

int main()
{
    int i, aprovados=0, exame=0, reprovados=0;
    float nota1, nota2, mediaAluno=0, somaMedia=0, mediaClasse=0;;

    for(i=0; i<6; i++)
    {
    	printf("Aluno [%d] - Nota 1: ", i+1);
    	scanf("%f", &nota1);
    	
    	printf("Aluno [%d] - Nota 2: ", i+1);
    	scanf("%f", &nota2);
    	
    	mediaAluno = (nota1+nota2)/2.0;
    	
    	somaMedia = somaMedia + mediaAluno;
    	
    	printf("Media do Aluno [%d]: %.2f | ", i+1, mediaAluno);
    	
    	if(mediaAluno<4)
    	{
    		printf("Situacao: Reprovado\n\n");
    		
    		++reprovados;
		}
		if(mediaAluno>=4 && mediaAluno<7)
		{
			printf("Situacao: Exame final\n\n");
			
			++exame;
		}
		if(mediaAluno>=7)
		{
			printf("Situacao: Aprovado\n\n");
			
			++aprovados;
		}
    }
    
    mediaClasse = somaMedia/6;
    
    printf("\t RELATORIO FINAL\n");
    printf("Total de alunos aprovados: %d\n", aprovados);
    printf("Total de alunos reprovados: %d\n", reprovados);
    printf("Total de alunos de exame: %d\n", exame);
    printf("Media da classe: %.2f", mediaClasse);
    
    printf("\n\n");    

    system("PAUSE");
    return 0;
}
