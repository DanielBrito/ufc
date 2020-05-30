// https://www.urionlinejudge.com.br/judge/en/problems/view/1557

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int N = 1, i, j;

    while (N != 0){

        scanf("%d", &N);

        for (i = 1; i < pow(2, N); i *= 2){

            for (j = i; j < pow(2, N) * i; j *= 2){

                printf("%d ", j); // It doesn't format the required output properly
            }

            printf("\n");
        }
    }

    return 0;
}
