#include<stdio.h>

int main()
{
    int ano_nasc, ano_atual;

    printf("Digite o ano de nascimento: ");
    scanf("%d", &ano_nasc);
    printf("Digite o ano atual: ");
    scanf("%d", &ano_atual);

    printf("\n\n");

    printf("a) Idade atual: %d\n", ano_atual-ano_nasc);
    printf("b) Idade em 2050: %d\n\n", 2050-ano_nasc);

    return 0;

}
