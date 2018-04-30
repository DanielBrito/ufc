/*TAD: Operações sobre Matrizes*/

#include "matriz.h"

/*Funções Exportadas*/

/* Função iguais - Retorna 1 se as matrizes forem iguais e 0 caso contrário. */
int iguais(Matriz *mat1, Matriz* mat2);

/* Função oposta - Retorna a matriz oposta à mat1. Isto é, uma matriz que somada com mat1 resulte em uma matriz nula*/
Matriz* oposta(Matriz *mat1);

/* Função transposta - Retorna a matriz transposta à mat1.*/
Matriz* transposta(Matriz *mat1);

/*Função soma - Retorna uma matriz composta pela soma de mat1 com mat2. Caso não seja possível fazer a soma, deve-se retornar NULL*/
Matriz* soma(Matriz *mat1, Matriz* mat2);

/*Função subtração - Retorna uma matriz composta pela subtração de mat1 com mat2. Caso não seja possível fazer a soma, deve-se retornar NULL*/
Matriz* subtracao(Matriz *mat1, Matriz* mat2);

/* Função multiplica - Retorna uma matriz composta pela multiplicação de mat1 por mat2. Caso não seja possível fazer a multiplicação, retorna NULL*/
Matriz* multiplica(Matriz *mat1, Matriz* mat2);