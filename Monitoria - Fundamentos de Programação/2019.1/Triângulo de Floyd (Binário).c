/* Exercício da lista de Teste das engenharias */

#include<stdio.h>

int main(){
    
    int N, cont=1, i;
    
    printf("Digite o valor de N: ");
    scanf("%d", &N); // Variável que será utilizada para definir a quantidade de números na última linha, bem como a altura do triângulo
    
    while(cont<=N){ // Laço para verificar a quantidade de linhas do triângulo

        for(i=1; i<=cont; i++){ // Laço para imprimir os elementos de uma determinada linha

            // Percebam que quando (a linha (cont) é ímpar && a coluna (i) é ímpar) OU (a linha (cont) é par e a coluna (i) é par) imprimimos o valor 1.
            // Caso contrário, imprimimos o valor 0:
            
            if((cont%2==1 && i%2==1) || (cont%2==0 && i%2==0)){
                
                printf("1");
            }
            else{
                
                printf("0");
            }
        }
        
        printf("\n");
        cont++; // Contador para fazer o controle da quantidade de elementos em uma linha e incrementar a quantidade de linhas após cada iteração
    }
    
    return 0;
}
