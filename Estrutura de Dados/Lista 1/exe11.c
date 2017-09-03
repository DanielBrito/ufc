#include<stdio.h>
#include<math.h>

int triangular(int n);

int main(){

int num;

printf("Digite um inteiro nao-negativo: ");
scanf("%d", &num);

if(triangular(num))

    printf("\nO numero e triangular.");
else
    printf("\nO numero nao e triangular.");

printf("\n\n");

    return 0;
}


int triangular(int n){

    int i=1, j=2, k=3;
    int r=0;

    while(r<n){

        r = i*j*k;

        if(r == n){

            return 1;
        }

        i++;
        j++;
        k++;
    }

    return 0;
}

