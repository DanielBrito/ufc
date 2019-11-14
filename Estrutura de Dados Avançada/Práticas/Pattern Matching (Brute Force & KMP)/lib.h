#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>

#define MAX_TEXTO     1000
#define MAX_PADRAO    50

typedef char TipoTexto[MAX_TEXTO];
typedef char TipoPadrao[MAX_PADRAO];

void menu(void);
void forca_bruta(TipoTexto T, int n, TipoPadrao P, int m);
void mapearPrefixo(TipoPadrao P, int m, int* prefixo);
void kmp(TipoTexto T, int n, TipoPadrao P, int m);
