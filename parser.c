#include <stdio.h>
#include <string.h>

#include "parser.h"
#include "lexer.h"

void factor(char* lexema, char* token);
void term(char* lexema, char* token);
void expr(char* lexema, char* token);

void factor(char* lexema, char* token) {
    if (!strcmp(token, "IDENTIFICADOR") || !strcmp(token, "LITERALINTEIRO")) {
        lex(lexema, token);
    } else {
        if (!strcmp(token, "PARENTESESESQUERDO")) {
            lex(lexema, token);
            expr(lexema, token);
            if (!strcmp(token, "PARENTESESDIREITO")) lex(lexema, token);
            else printf("Erro de sintaxe: Esperava ')'\n");
        } else { 
            printf("Erro de sintaxe: Token inesperado '%s'\n", lexema);
        }
    }
}

void term(char* lexema, char* token) {
    factor(lexema, token);
    while (!strcmp(token, "OPMULTIPLICAÇÃO") || !strcmp(token, "OPDIVISÃO")) {
        lex(lexema, token);
        factor(lexema, token);
    }
}

void expr(char* lexema, char* token) {
    term(lexema, token);
    while (!strcmp(token, "OPSOMA") || !strcmp(token, "OPSUBTRAÇÃO")) {
        lex(lexema, token);
        term(lexema, token);
    }
}

void parse() {
    char lexema[TAMANHO_MAX_ENTRADA], token[19];
    
    lex(lexema, token);
    expr(lexema, token);

    if (strcmp(token, "EOF") != 0) printf("Erro de sintaxe\n");
    else printf("Análise concluída com sucesso.\n");
}
