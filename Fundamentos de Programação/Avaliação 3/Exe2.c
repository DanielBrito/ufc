// Calcular distância média entre dois pontos

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct ponto{

    float x;
    float y;

};


void pontoMedio(struct ponto *a, struct ponto *b)
{
    float media_x = 0, media_y = 0;

    media_x = (a->x + b->x)/2;

    media_y = (a->y + b->y)/2;

    printf("Media = %.2f, %.2f", media_x, media_y);
}


int main()
{

    struct ponto a, b;

    a.x = 4;
    a.y = 6;
    b.x = 8;
    b.y = 10;

    pontoMedio(&a, &b);

    printf("\n\n");

    return 0;
}
