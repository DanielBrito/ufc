#include<stdio.h>
#include<limits.h>

int main()
{
    int i; // contador de cidades
    int cod, num_vei, num_aci; // dados das cidades

    int maior_aci=INT_MIN, menor_aci=INT_MAX, cid_maior_aci=0, cid_menor_aci=0;
    float total_vei=0, total_aci=0, media_vei=0, media_aci_menos_2000=0;

    int cid_menos_2000_vei=0; // contador

    for(i=0; i<=4; i++)
    {
        printf("Digite o codigo da cidade: ");
        scanf("%d", &cod);

        printf("Digite o numero de veiculos: ");
        scanf("%d", &num_vei);

        printf("Digite o numero de acidentes: ");
        scanf("%d", &num_aci);

        printf("\n");

        // Calcula o total de veículos ao final das iterações
		total_vei = total_vei+num_vei;

        // Condicional para verificar o maior numero de acidentes e a respectiva cidade que se refere
        if(num_aci>maior_aci)
        {
            maior_aci = num_aci;
            cid_maior_aci = cod;
        }
        
        // Condicional para verificar o menor numero de acidentes e a respectiva cidade que se refere
        if(num_aci<menor_aci)
        {
            menor_aci = num_aci;
            cid_menor_aci = cod;
        }

        // Contador para verificar o numero de cidades com menos de 2000 veículos:
        if(num_vei<2000)
        {
            ++cid_menos_2000_vei;
        }

        // Contador para verificar o total de acidentes em cidades com menos de 2000 veículos:
        if(num_vei<2000)
        {
            total_aci = total_aci+num_aci;
        }
    }

   	// Calcula a media dos veiculos das cinco cidades
    media_vei = total_vei/5; 

    // Contador para verificar a media de acidentes em cidades com menos de 2000 veículos:
    media_aci_menos_2000 = total_aci/cid_menos_2000_vei;


    printf("\n\t\t\t* RELATORIO *   \n\n");
    printf("a) Maior e menor indice de acidentes e a qual cidade pertencem: \n");
    printf(" - Maior indice de acidentes: %2d | Cidade: %.3d\n", maior_aci, cid_maior_aci);
    printf(" - Menor indice de acidentes: %2d | Cidade: %.3d\n", menor_aci, cid_menor_aci);
    printf("b) Media dos veiculos das cinco cidades: %.2f\n", media_vei);
    printf("c) Media de acidentes em cidades com menos de 2000 veiculos: %.2f\n\n", media_aci_menos_2000);

    system("PAUSE");
    return 0;
}
