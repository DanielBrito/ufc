#include<stdio.h>
#include<math.h>

int main(){

    int num, i;

    printf("Didite um numero: ");
    scanf("%d", &num);

    printf("\n");

    for(i=2; i<=num; i++){

        if(num%i == 0){

            printf("%d\n", i);
        }
    }

    printf("\n\n");

    return 0;
}
