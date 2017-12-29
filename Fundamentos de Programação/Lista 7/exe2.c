#include <stdio.h>
#include <math.h>
#define TAM 6

void calculaS(int* vet){

    int i;
    float s = 0;

    for(i=0; i<TAM; i++){

        s += (float)vet[i]/(i + 1);
    }

    printf("O valor de S: %.2f", s);
}

void calculaT(int* vet){

    int i;
    float t = 1;

    for(i=0; i<TAM; i++){

        t *= (float)pow(vet[i], 2)/(i + 10);
    }

    printf("O valor de T: %.2f", t);
}

void calculaV(int* vet){

    int i, j = 2;
    float v = 0;

    for(i=0; i<TAM; i++){

        v += (float)sqrt(j)/vet[i];
        j += 2;
    }

    printf("O valor de V: %.2f", v);
}

int main(){

    int vetor[TAM] = {32,30,29,35,30,30};
    calculaS(vetor);
    //calculaT(vetor);
    //calculaV(vetor);

    return 0;
}