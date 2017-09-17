#include<stdio.h>
#include<stdlib.h>

int potenciacao(int b, int e);

int main(){

    int base, expoente;

    printf("Digite a base: ");
    scanf("%d", &base);

    printf("Digite o expoente: ");
    scanf("%d", &expoente);

    printf("%d elevado a %d = %d", base, expoente, potenciacao(base, expoente));

    printf("\n\n");

    return 0;
}

int potenciacao(int b, int e){

    if(e==0){

        return 1;
    }
    else{

        return b*potenciacao(b, e-1);
    }
}
