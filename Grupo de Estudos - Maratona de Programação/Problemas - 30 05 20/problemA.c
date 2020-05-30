// https://www.urionlinejudge.com.br/judge/en/problems/view/1047

#include <stdio.h>
#include <stdlib.h>

int main() {

    int initialHour, initialMinute, finalHour, finalMinute, min, max, diff;

    scanf("%d %d %d %d", &initialHour, &initialMinute, &finalHour, &finalMinute);

    min = (initialHour*60)+initialMinute;
    max = (finalHour*60)+finalMinute;

    diff = (max>min) ? max-min : ((min-max)-(24*60))*(-1);

    if(diff!=0){

        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", diff/60, diff%60);
    }
    else{

        printf("O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)\n");
    }

    return 0;
}
