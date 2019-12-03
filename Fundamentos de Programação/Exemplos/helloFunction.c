#include<stdio.h>

void hello(char* nome){

    printf("Hello, %s!\n", nome);
}

void greet(void (*greeter)(), char* name){

     greeter(name);
}

int main(){

    char name[30];

    printf("What's your name?\n-> ");
    scanf("%s", name);

    greet(hello, name);
}