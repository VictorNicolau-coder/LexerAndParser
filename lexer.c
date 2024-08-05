#include "lexer.h"

void getChar(){
    proximoChar = entrada[count++];

    if (proximoChar == '\0'){
        strcpy(classeChar, "FIMDEARQUIVO");
        return;
    }

    if (isalpha(proximoChar)) strcpy(classeChar, "LETRA");
    else if (isdigit(proximoChar)) strcpy(classeChar, "DÍGITO");
    else strcpy(classeChar, "DESCONHECIDO");
}

void getNaoVazio(){
    while (isspace(proximoChar)) getChar();
}

void lex(char *lexema, char *token) {
    int i = 0;
    char holder[100] = " ";
    getNaoVazio();

    if (!strcmp(classeChar, "LETRA")) {
        do{
            holder[i++] = proximoChar;
            getChar();
        } while (!strcmp(classeChar, "LETRA") || !strcmp(classeChar, "DÍGITO"));
        strcpy(lexema, holder);
        strcpy(token, "IDENTIFICADOR");
    } else if (!strcmp(classeChar, "DÍGITO")) {
        do{
            holder[i++] = proximoChar;
            getChar();
        } while (!strcmp(classeChar, "DÍGITO"));
        strcpy(lexema, holder);
        strcpy(token, "LITERALINTEIRO");
    } else if (!strcmp(classeChar, "DESCONHECIDO")) {
        holder[i] = proximoChar;
        strcpy(lexema, holder);
        strcpy(token, verificaToken());
        getChar();
    } else {
        strcpy(lexema, "EOF");
        strcpy(token, "EOF");
    }

}

char *verificaToken(){
    if (proximoChar == '(') return "PARENTESESESQUERDO";
    else if (proximoChar == ')') return "PARENTESESDIREITO";
    else if (proximoChar == '+') return "OPSOMA";
    else if (proximoChar == '-') return "OPSUBTRAÇÃO";
    else if (proximoChar == '*') return "OPMULTIPLICAÇÃO";
    else if (proximoChar == '/') return "OPDIVISÃO";
}