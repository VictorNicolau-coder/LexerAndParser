#ifndef ANALISADOR_H
#define ANALISADOR_H

#include <ctype.h>
#include <string.h>

#define TAMANHO_MAX_ENTRADA 100

int count = 0;

char entrada[TAMANHO_MAX_ENTRADA];

char proximoChar = ' ';
char classeChar[13];

void getChar();
void getNaoVazio();
void lex(char *lexema, char *token);
char *verificaToken();

#endif