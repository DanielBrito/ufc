#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"

int main(){

    Pilha* p = p_cria();
    char v[20] = "(([]))";
    int i;
    char ch;

    for(i=0; i<strlen(v); i++){

        if(v[i]=='(' || v[i]=='['){

            p_push(p, v[i]);
        }
        else
        if(v[i]==')' || v[i]==']'){

            if(!p_vazia(p)){

                ch = p_pop(p);

                if((ch=='(' && v[i]!=')')||ch=='[' && v[i]!=']'){

                    printf("Sequencia desbalanceada.\n");
                    p_libera(p);
                    return 0;
                }
            }
            else{

                printf("Sequencia desbalanceada.\n");
                p_libera(p);
                return 0;
            }
        }
    }

    if(!p_vazia(p)){

        printf("Sequencia desbalanceada.\n");
        p_libera(p);
        return 0;
    }
    else{

        printf("Sequencia balanceada.\n");
    }

    p_libera(p);
    
    return 0;
}