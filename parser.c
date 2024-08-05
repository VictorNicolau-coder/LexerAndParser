#include "parser.h"

void factor(){
    if (!strcmp(next_token, "IDENT") || !strcmp(next_token, "LITERALINTEIRO")){
        //next_token = lex();
    } else {
        if (!strcmp(next_token, "PARENTESESESQUERDO")){
            //next_token = lex();
            expr();
            if (!strcmp(next_token, "PARENTESESDIREITO")){
                int b; //next_token = lex();
            } else {
                return;
            }
        } else { 
            return; 
        }
    }
}

void term(){
    factor();
    while (!strcmp(next_token, "OPMULTIPLICACAO") || !strcmp(next_token, "OPDIVISAO")){
        //next_token = lex();
        factor();
    }
}

void expr(){
    term();
    while (!strcmp(next_token, "OPSOMA") || !strcmp(next_token, "OPSUBTRACAO")) {
        //next_token = lex();
        term();
    }
}

