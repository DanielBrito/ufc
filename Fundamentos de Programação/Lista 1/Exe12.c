#include<stdio.h>

/*

Um trabalhador recebeu seu salário e o depositou em sua conta bancária. Esse
trabalhador emitiu dois cheques e agora deseja saber seu saldo atual. Sabe-se que
cada operação bancária de retirada paga uma taxa de 0,38% e o saldo inicial da
conta está zerado.

Faça um programa que receba o salario do trabalhador e o
valor dos dois cheques que ele emitiu e calcule e escreva o saldo atual da sua conta
depois da operações.

*/

int main()
{
    float salario, saldo;

    printf("Digite o salario recebido: ");
    scanf("%f", &salario);

    saldo = salario;

    saldo = saldo-(saldo*(0.0038)); // emissão do cheque 1

    saldo = saldo-(saldo*(0.0038)); // emissão do cheque 2


    printf("\nSaldo atual: %.2f\n\n", saldo);


    return 0;
}
