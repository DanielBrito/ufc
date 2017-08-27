#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>


// Prototipos das funcoes:

void gerar_conjuntoA(int vetorA[], int tamA);
void gerar_conjuntoB(int vetorB[], int tamB);
void exibir_menu();
void verificar_pertinencia(int vetorA[], int tamA, int vetorB[], int tamB);
void mostrar_maior_menor(int vetorA[], int tamA, int vetorB[], int tamB);
void verificar_igualdade(int vetorA[], int tamA, int vetorB[], int tamB);
void verificar_se_contem(int vetorA[], int tamA, int vetorB[], int tamB);
void gerar_uniao(int vetorA[], int tamA, int vetorB[], int tamB);
void gerar_intersecao(int vetorA[], int tamA, int vetorB[], int tamB);
void gerar_diferenca(int vetorA[], int tamA, int vetorB[], int tamB);
void complemento_A_B(int vetorA[], int tamA, int vetorB[], int tamB);

int main()
{
    int tam_A=0, tam_B=0;
    int op=0;

    printf("*********************** VALORES DOS CONJUNTOS ***********************\n\n");


    // Entrada para definir o tamanho do vetor de numeros aleatorios:

    printf("Digite o tamanho do conjunto A: ");
    scanf("%d", &tam_A);

    int conjunto_A[tam_A];


    // Funcao para gerar o conjunto A com numeros aleatorios:

    gerar_conjuntoA(conjunto_A, tam_A);

    printf("\n");


    // Entrada para definir o tamanho do vetor de numeros digitados pelo usuario:

    printf("Digite o tamanho do conjunto B: ");
    scanf("%d", &tam_B);

    int conjunto_B[tam_B];


    // Funcao para gerar o conjunto B com numeros digitados pelo usuario:

    gerar_conjuntoB(conjunto_B, tam_B);


    // Chamada da funcao para exibicao do menu e escolha da opcao desejada:

    exibir_menu();

    while(1)
    {
        printf("  > Opcao: ");
        scanf("%d", &op);

        switch(op)
        {
        // Opcao 1 - Verificar pertinencia de um elemento:

        case 1: system("cls");
                verificar_pertinencia(conjunto_A, tam_A, conjunto_B, tam_B);
                system("PAUSE");
                exibir_menu();
                break;

        // Opcao 2 - Exibir elementos de maior e menor valor de A e B:

        case 2: system("cls");
                mostrar_maior_menor(conjunto_A, tam_A, conjunto_B, tam_B);
                system("PAUSE");
                exibir_menu();
                break;

        // Opcao 3 - Verificar igualdade dos conjuntos:

        case 3: system("cls");
                verificar_igualdade(conjunto_A, tam_A, conjunto_B, tam_B);
                system("PAUSE");
                exibir_menu();
                break;

        // Opcao 4 - Verificar se A e subconjunto de B ou se B e subconjunto de A:

        case 4: system("cls");
                verificar_se_contem(conjunto_A, tam_A, conjunto_B, tam_B);
                system("PAUSE");
                exibir_menu();
                break;

        // Opcao 5 - Gerar o conjunto de Uniao de A e B:

        case 5: system("cls");
                gerar_uniao(conjunto_A, tam_A, conjunto_B, tam_B);
                system("PAUSE");
                exibir_menu();
                break;

        // Opcao 6 - Gerar o conjunto de Intersecao entre A e B:

        case 6: system("cls");
                gerar_intersecao(conjunto_A, tam_A, conjunto_B, tam_B);
                system("PAUSE");
                exibir_menu();
                break;

        // Opcao 7 - Gerar os conjuntos de Diferenca A-B e B-A:

        case 7: system("cls");
                gerar_diferenca(conjunto_A, tam_A, conjunto_B, tam_B);
                system("PAUSE");
                exibir_menu();
                break;

        // Opcao 8 - Gerar o Conjunto das Partes de B:

        case 8: system("cls");
                printf("\n * OPCAO 8 - GERAR O CONJUNTO DAS PARTES DE B *\n\n");
                printf("Esta funcao nao foi implementada.\n\n\n");
                system("PAUSE");
                exibir_menu();
                break;

        // Opcao 9 - Gerar os conjuntos de Complemento de A e Complemento de B:

        case 9: system("cls");
                complemento_A_B(conjunto_A, tam_A, conjunto_B, tam_B);
                system("PAUSE");
                exibir_menu();
                break;

        // Opcao 0 - Sair:

        case 0: return 0;

        // Exibir o menu ate que seja digitada uma das opcoes:

        default: exibir_menu();
        }

    }

    printf("\n\n");

    system("PAUSE");
    return 0;
}


// Funcao para gerar valores aleatorios para o conjunto A:

void gerar_conjuntoA(int vetorA[], int tamA)
{
	int i=0, j=0, valor=0;

	srand(time(NULL));

	for(i=0; i<tamA; i++)
	{
		valor = (rand()%99)-49;

		for(j=0; j<tamA; j++)
        {
            if(valor == vetorA[j])
            {
                valor = (rand()%99)-49;
                j = -1;
            }
        }

        vetorA[i] = valor;
	}

    /*
	// Teste de impressao do conjunto A:

	for(i=0; i<tamA; i++)
    {
        printf ("%d\n", vetorA[i]);
    }
    */
}


// Funcao para receber valores do usuario para o conjunto B:

void gerar_conjuntoB(int vetorB[], int tamB)
{
	int i=0, j=0, valor=0;

	printf("\n");

	for(i=0; i<tamB; i++)
	{
	    printf("Digite o valor da posicao [%d] do conjunto B: ", i);
	    scanf("%d", &valor);

	    for(j=0; j<=i; j++)
        {
            /*

            Obs.: Por algum motivo, em alguns testes houveram resultados inesperados na nova solicitao.

            Por exemplo, se o usuario digitar o numero 3 como tamanho do vetor, durante o recebimento dos
            valores, quando o indice atingir a posicao [2], e o usuario digitar o numero 3 (mesmo se ele
            não tiver sido digitado antes), o programa informa que o 3 ja foi digitado.

            Estranhamente, se ele for digitado na posicao [0] ou [1], funciona normalmente. E isso nao
            esta ocorrendo com outros valores, por enquanto, so com o 3.

            Gostaria de uma explicacao sobre o motivo desta ocorrencia, se possivel.

            */

            /*

            Para gerar o Complemento de B (questao 9), o valor digitado pelo usuario para o Conjunto B
            tem que pertencer ao Conjunto Universo (-49 a 49), portanto, ele deve ser testado:

            */

            while(valor==vetorB[j] || valor<-49 || valor>49) //
            {
                printf("\nErro: O valor ja existe no conjunto\n");
                printf(" OU\n");
                printf("Erro: O valor nao pertence ao intervalo de -49 a 49\n\n");


                printf("Digite o valor da posicao [%d] do conjunto B: ", i);
                scanf("%d", &valor);
            }
        }

        vetorB[i] = valor;
	}

    /*
	// Teste de impressao do conjunto B:

	printf("\n");

    for(i=0; i<tamB; i++)
    {
        printf ("%d\n", vetorB[i]);
    }
    */
}


// Funcao para exibir o menu:

void exibir_menu()
{
    system("cls");

    printf("******************************** MENU ********************************\n\n");
    printf("1 - Verificar pertinencia de um elemento\n");
    printf("2 - Exibir elementos de maior e menor valor de A e B\n");
    printf("3 - Verificar igualdade dos conjuntos\n");
    printf("4 - Verificar se A e subconjunto de B ou se B e subconjunto de A\n");
    printf("5 - Gerar o conjunto de Uniao de A e B\n");
    printf("6 - Gerar o conjunto de Interseccao de A e B\n");
    printf("7 - Gerar os conjuntos de Diferenca A-B e B-A\n");
    printf("8 - Gerar o conjunto das partes de B\n");
    printf("9 - Gerar os conjuntos de Complemento de A e Complemento de B\n");
    printf("0 - Sair\n");
    printf("\n**********************************************************************\n\n");
}


// Funcao para verificar se o valor digitado pelo usuario pertence aos conjuntos:

void verificar_pertinencia(int vetorA[], int tamA, int vetorB[], int tamB)
{
    printf("\n * OPCAO 1 - VERIFICAR PERTINENCIA DE UM ELEMENTO *\n\n");

    int i=0, j=0, valor=0;
    int contA=0, contB=0;

    printf("Digite o valor a ser procurado nos conjuntos: ");
    scanf("%d", &valor);

    printf("\n\n");


    // Verificar pertinencia no conjunto A (aleatorio):

    for(i=0; i<tamA; i++)
    {
        if(valor==vetorA[i])
        {
            contA++;
        }
    }

    if(contA==1)
    {
        printf("O valor pertence ao conjunto A.\n");
    }
    else
    {
        printf("O valor nao pertence ao conjunto A.\n");
    }


    // Verificar pertinencia no conjunto B (usuario):

    for(j=0; j<tamB; j++)
    {
        if(valor==vetorB[j])
        {
            contB++;
        }
    }

    if(contB==1)
    {
        printf("O valor pertence ao conjunto B.\n");
    }
    else
    {
        printf("O valor nao pertence ao conjunto B.\n");
    }

    printf("\n\n");
}


// Funcao para mostrar o maior e menor elemento de cada um dos conjuntos:

void mostrar_maior_menor(int vetorA[], int tamA, int vetorB[], int tamB)
{
    printf("\n * OPCAO 2 - EXIBIR ELEMENTOS DE MAIOR E MENOR VALOR DE A E B *\n\n");

    int i=0, j=0;
    int maiorA = INT_MIN, menorA = INT_MAX, maiorB = INT_MIN, menorB = INT_MAX;


    // Verificar menor elemento do conjunto A:

    for(i=0; i<tamA; i++)
    {
        if(vetorA[i]<menorA)
        {
            menorA = vetorA[i];
        }
    }


    // Verificar maior elemento do conjunto A:

    for(j=0; j<tamA; j++)
    {
        if(vetorA[j]>maiorA)
        {
            maiorA = vetorA[j];
        }
    }


    // Verificar menor elemento do conjunto B:

    for(i=0; i<tamB; i++)
    {
        if(vetorB[i]<menorB)
        {
            menorB = vetorB[i];
        }
    }


    // Verificar maior elemento do conjunto B:

    for(j=0; j<tamB; j++)
    {
        if(vetorB[j]>maiorB)
        {
            maiorB = vetorB[j];
        }
    }


    // Impressao dos resultados:

    printf("\n");

    printf("O menor valor do conjunto A e %d.\n", menorA);
    printf("O maior valor do conjunto A e %d.\n", maiorA);

    printf("\n");

    printf("O menor valor do conjunto B e %d.\n", menorB);
    printf("O maior valor do conjunto B e %d.\n", maiorB);

    printf("\n\n");
}


// Funcao para verificar se os conjuntos sao iguais:

void verificar_igualdade(int vetorA[], int tamA, int vetorB[], int tamB)
{
    printf("\n * OPCAO 3 - VERIFICAR IGUALDADE DOS CONJUNTOS *\n\n");

    int i=0, j=0;
    int cont=0, total=0;

    if(tamA!=tamB)
    {
        printf("Os conjuntos sao diferentes.\n");
    }
    else
    {
        for(i=0; i<tamA; i++)
        {
            for(j=0; j<tamB; j++)
            {
                if(vetorA[i]==vetorB[j])
                {
                    cont++;
                }
            }
        }

        if(cont==tamA) // ou if(cont==tamB)
        {
            printf("Os conjuntos sao iguais.\n");
        }
        else
        {
            printf("Os conjuntos sao diferentes.\n");
        }
    }

    printf("\n\n");
}


// Funcao para verificar se o conjunto A esta contido em B ou se B esta contido em A:

void verificar_se_contem(int vetorA[], int tamA, int vetorB[], int tamB)
{
    printf("\n * OPCAO 4 - VERIFICAR SE A E SUBCONJUNTO DE B OU SE B E SUBCONJUNTO DE A *\n\n");

    int i=0, j=0;
    int cont=0;

    if(tamA>tamB)
    {
        for(i=0; i<tamA; i++)
        {
            for(j=0; j<tamB; j++)
            {
                if(vetorA[i]==vetorB[j])
                {
                    cont++;
                }
            }
        }

        if(cont==0)
        {
            printf("O conjunto A nao esta contido no conjunto B.\n"); // Por ser maior
            printf("O conjunto B nao esta contido no conjunto A.\n");
        }
        else
        if(cont==tamB)
        {
            printf("O conjunto A nao esta contido no conjunto B.\n"); // Por ser maior
            printf("O conjunto B esta contido no conjunto A.\n");
        }
    }
    else
    if(tamB>tamA)
    {
        for(i=0; i<tamA; i++)
        {
            for(j=0; j<tamB; j++)
            {
                if(vetorA[i]==vetorB[j])
                {
                    cont++;
                }
            }
        }

        if(cont==0)
        {
            printf("O conjunto B nao esta contido no conjunto A.\n"); // Por ser maior
            printf("O conjunto A nao esta contido no conjunto B.\n");
        }
        else
        if(cont==tamA)
        {
            printf("O conjunto B nao esta contido no conjunto A.\n"); // Por ser maior
            printf("O conjunto A esta contido no conjunto B.\n");
        }
    }
    else // Quando os conjuntos tiverem o mesmo numero de elementos:
    {
        for(i=0; i<tamA; i++)
        {
            for(j=0; j<tamB; j++)
            {
                if(vetorA[i]==vetorB[j])
                {
                    cont++;
                }
            }
        }

        if(cont==tamA) // ou if(cont==tamB)
        {
            printf("Os conjuntos sao iguais.\n");
        }
        else
        {
            printf("Os conjuntos sao disjuntos.\n");
        }
    }

    printf("\n\n");
}


// Funcao para fazer a uniao do conjunto A com o conjunto B:

void gerar_uniao(int vetorA[], int tamA, int vetorB[], int tamB)
{
    printf("\n * OPCAO 5 - GERAR O CONJUNTO DE UNIAO DE A E B *\n\n");

    int i=0, j=0, x=0, n=0, repete=0;
    int tam_uniao = tamA+tamB;
    int concatenado[tam_uniao];
    int uniao[tam_uniao];


    // Lacos para fazer a concatenacao dos conjuntos A e B:

    for(i=0; i<tamA; i++)
    {
        concatenado[x] = vetorA[i];
        x++;
    }

    for(j=0; j<tamB; j++)
    {
        concatenado[x] = vetorB[j];
        x++;
    }


    // Laco para fazer a comparacao entre valores para eliminar os repetidos:

    for(i=0; i<x; i++)
    {
        if(i==0)
        {
            uniao[n] = concatenado[i];
            n++;
        }
        else
        {
            for(j=0; j<n; j++)
            {
                if(concatenado[i]==uniao[j])
                {
                    repete++;
                }
            }

            if(repete<1)
            {
                uniao[n] = concatenado[i];
                n++;
            }

            repete = 0;
        }
    }


    // Bubble sort para fazer a ordenacao dos valores:

    int aux=0;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n-1; j++)
        {
            if(uniao[j]>uniao[j+1])
            {
                aux = uniao[j];
                uniao[j] = uniao[j+1];
                uniao[j+1] = aux;
            }
        }
    }


    // Impressao do Conjunto Uniao ordenado em ordem crescente:

    for(j=0; j<n; j++)
    {
        printf("%d\n", uniao[j]);
    }

    printf("\n\n");
}


// Funcao para verificar os valores da intersecao entre o conjunto A e o B:

void gerar_intersecao(int vetorA[], int tamA, int vetorB[], int tamB)
{
    printf("\n * OPCAO 6 - GERAR O CONJUNTO DE INTERSECAO ENTRE A E B *\n\n");

    int i=0, j=0, n=0;
    int tam_intersecao=tamA+tamB;
    int intersecao[tam_intersecao];


    // Laco para criar um novo vetor com os valores presentes na intersecao:

    for(i=0; i<tamA; i++)
    {
        for(j=0; j<tamB; j++)
        {
            if(vetorA[i]==vetorB[j])
            {
                intersecao[n] = vetorA[i]; // ou vetorB[j];
                n++;
            }
        }
    }


    // Impressao do resultado:

    if(n==0)
    {
        printf("Os conjuntos sao disjuntos.\n");
    }
    else
    {
        // Bubble sort para fazer a ordenacao dos valores do conjunto:

        int aux=0;

        for(i=0; i<n; i++)
        {
            for(j=0; j<n-1; j++)
            {
                if(intersecao[j]>intersecao[j+1])
                {
                    aux = intersecao[j];
                    intersecao[j] = intersecao[j+1];
                    intersecao[j+1] = aux;
                }
            }
        }


        // Impressao dos valores da intersecao ordenados em ordem crescente:

        for(i=0; i<n; i++)
        {
            printf("%d\n", intersecao[i]);
        }
    }

    printf("\n\n");
}


// Funcao para gerar os conjuntos de Diferenca A-B e B-A:

void gerar_diferenca(int vetorA[], int tamA, int vetorB[], int tamB)
{
    printf("\n * OPCAO 7 - GERAR OS CONJUNTOS DE DIFERENCA A-B e B-A *\n\n");

    int i=0, j=0, contA=0, contB=0, aux=0;
    int diferenca_AB[tamA];
    int diferenca_BA[tamB];
    int cont_dif=0;


    // Verificar a diferenca A-B

    for(i=0; i<tamA; i++)
    {
        for(j=0; j<tamB; j++)
        {
            if(vetorA[i]!=vetorB[j])
            {
                cont_dif++;
            }
        }

        if(cont_dif==tamB)
        {
            diferenca_AB[contA] = vetorA[i];
            contA++;
        }

     cont_dif=0;

    }


    // Verificar a diferenca B-A

    for(i=0; i<tamB; i++)
    {
        for(j=0; j<tamA; j++)
        {
            if(vetorB[i]!=vetorA[j])
            {
                cont_dif++;
            }
        }

        if(cont_dif==tamA)
        {
            diferenca_BA[contB] = vetorB[i];
            contB++;
        }

     cont_dif=0;

    }


    // Bubble sort para fazer a ordenacao dos valores de A-B:

        aux=0;

        for(i=0; i<contA; i++)
        {
            for(j=0; j<contA-1; j++)
            {
                if(diferenca_AB[j]>diferenca_AB[j+1])
                {
                    aux = diferenca_AB[j];
                    diferenca_AB[j] = diferenca_AB[j+1];
                    diferenca_AB[j+1] = aux;
                }
            }
        }


    // Impressao dos valores de A-B ordenados em ordem crescente:

    printf("Resultado de A - B:\n");

    for(i=0; i<contA; i++)
    {
        printf("%d\n", diferenca_AB[i]);
    }

    printf("\n");


    // Bubble sort para fazer a ordenacao dos valores de B-A:

        aux=0;

        for(i=0; i<contB; i++)
        {
            for(j=0; j<contB-1; j++)
            {
                if(diferenca_BA[j]>diferenca_BA[j+1])
                {
                    aux = diferenca_BA[j];
                    diferenca_BA[j] = diferenca_BA[j+1];
                    diferenca_BA[j+1] = aux;
                }
            }
        }


    // Impressao de B-A

    printf("Resultado de B - A:\n");

    for(i=0; i<contB; i++)
    {
        printf("%d\n", diferenca_BA[i]);
    }

    printf("\n\n");
}


// Funcao para exibir o Complemento de A e o Complemento de B em relacao ao Conjunto Universo:

void complemento_A_B(int vetorA[], int tamA, int vetorB[], int tamB)
{
    printf("\n * OPCAO 9 - GERAR OS CONJUNTOS DE COMPLEMENTO DE A E COMPLEMENTO DE B *\n\n");

    int i=0, j=0, n=0, cont=0;
    int conj_U[99], valor_U = -49, comp_A[99], comp_B[99];


    // Laco para gerar os valores do Conjunto Universo:

    for(i=0; i<99; i++)
    {
        conj_U[i] = valor_U;
        valor_U++;
    }


    /*
    // Teste de impressao do Conjunto Universo:

    for(i=0; i<99; i++)
    {
        printf("%d\n", conj_U[i]);
    }
    */


    // Laco para gerar o conjunto de Complemento de A:

    for(i=0; i<99; i++)
    {
        for(j=0; j<tamA; j++)
        {
            if(conj_U[i]!=vetorA[j])
            {
                cont++;
            }
        }

        if(cont==tamA)
        {
            comp_A[n] = conj_U[i];
            n++;
        }

        cont = 0;
    }


    // Impressao do Complemento de A:

    printf("Complemento de A:\n");

    for(i=0; i<n; i++)
    {
        printf("%d\n", comp_A[i]);
    }

    n = 0;
    cont = 0;

    printf("\n");


    // Laco para gerar o conjunto de Complemento de B:

    for(i=0; i<99; i++)
    {
        for(j=0; j<tamB; j++)
        {
            if(conj_U[i]!=vetorB[j])
            {
                cont++;
            }
        }

        if(cont==tamB)
        {
            comp_B[n] = conj_U[i];
            n++;
        }

        cont = 0;
    }


    // Impressao do Complemento de B:

    printf("Complemento de B:\n");

    for(i=0; i<n; i++)
    {
        printf("%d\n", comp_B[i]);
    }

    printf("\n\n");
}
