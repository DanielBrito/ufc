#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int coprimos(int x, int y);

int main(){

    int num, i, j;
    int** matriz;

    printf("Digite um numero: ");
    scanf("%d", &num);

    printf("\n");

    matriz = (int**)malloc(sizeof(int*)*num);

    for(i=0; i<num; i++){

        matriz[i] = (int*)malloc(sizeof(int)*num);
    }

    for(i=1; i<=num; i++){

        for(j=1; j<=num; j++){

           matriz[i-1][j-1]=coprimos(i, j);

        }
    }

    for(i=0; i<num; i++){

        for(j=0; j<num; j++){

           printf("%d ", matriz[i][j]);
        }

        printf("\n");
    }

    printf("\n\n");

    return 0;
}


int coprimos(int x, int y){

    int i, j, cont=0;

    for(i=1, j=1; i<=x, j<=y; i++, j++){

        if(x%i==0 && y%i==0){

            cont++;

            if(cont > 1){

                return 0;
            }
        }
    }

    return 1;
}
