#include <stdio.h>

#include "lexer.c"
#include "parser.c"

int main() {
    char lexema[TAMANHO_MAX_ENTRADA], token[19];

    printf("Insira abaixo uma expressão matemática: ");
    fgets(entrada, TAMANHO_MAX_ENTRADA, stdin);

    puts("Análise Léxica: ");

    lex(lexema, token);
    while (strcmp(token, "EOF")) {
        printf("Lexema: %s e Token: %s\n", lexema, token);
        lex(lexema, token);
    }

    count = 0;
    proximoChar = ' ';

    puts("\nAnálise Sintática: ");
    parse();

    return 0;
}
