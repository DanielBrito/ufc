#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {

    int i, idade;
    float cont_f=0, cont_m=0, cont_m_exp=0, cont_m_45=0, menor_idade_f=INT_MAX;
    float perc_m_45=1;
    char sexo, experiencia;

    for(i=0; i<8; i++){

        printf("Digite o sexo da pessoa %d (M/F): ", i+1);
        scanf(" %c", &sexo);

        printf("Digite a idade da pessoa %d: ", i+1);
        scanf("%d", &idade);

        printf("Digite a experiencia da pessoa %d (S/N): ", i+1);
        scanf(" %c", &experiencia);
        
        if(sexo == 'm'|| sexo == 'M'){
        	
            if( idade>45){
            	
                cont_m_45++;
            }
            
            if(experiencia=='s' || experiencia=='S'){
            	
                cont_m_exp++;
            }

            cont_m++;
        }

        if (sexo=='f' || sexo=='F'){

            if(experiencia=='s' || experiencia=='S'){

                if (idade<menor_idade_f){
                	
                        menor_idade_f = idade;
                }
            }
            
            cont_f=cont_f+1;
        }
        
        printf("\n");
    }

    if(cont_m==0){
    	
    	perc_m_45=0;    	
	}       
    else{
    	
    	perc_m_45=(cont_m_45/cont_m)*100;
	}
            

    if(menor_idade_f==INT_MAX){
    	
        menor_idade_f=0;
    }

    printf("\n\n\t\t* RELATORIO *\n\n");
    printf("a) O numero de pessoas do sexo FEMININO e %.0f.\n", cont_f); // a)
    printf("b) O numero de pessoas do sexo MASCULINO com experiencia e %.0f.\n", cont_m_exp); // b)
    printf("c) O percentual de homens com mais de 45 ANOS e %.2f%%.\n", perc_m_45); // c)
    printf("d) A menor idade entre as mulheres que ja tem experiencia e %.0f.\n\n", menor_idade_f); // d)
    
    return 0;
}
