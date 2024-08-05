#include <stdio.h>

#include "lexer.c"
#include "parser.c"

int main(){
    char lexema[TAMANHO_MAX_ENTRADA], token[19];

    puts("Insira abaixo uma expressão matemática: ");
    fgets(entrada, TAMANHO_MAX_ENTRADA, stdin);

    puts(" ");

    lex(lexema, token);
    while(strcmp(token, "EOF")){
        printf("Lexema: %s e Token: %s\n", lexema, token);
        lex(lexema, token);
    }

    return 0;
}
