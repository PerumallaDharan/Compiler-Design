%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IDENT_LEN 50
#define MAX_KEYWORDS 10

struct SymbolTable {
    char name[MAX_IDENT_LEN];
    int tokenType;
};

struct SymbolTable symbolTable[MAX_KEYWORDS];
int symbolTableSize = 0;

%}

%option noyywrap

letter      [a-zA-Z]
digit       [0-9]
id          {letter}({letter}|{digit})*
integer     {digit}+
rel_op      "<"|">"|"<="|">="|"=="|"!="

%%

"/*"[\s\S]*?"*/" ;

{rel_op}     { printf("Relational Operator: %s\n", yytext); }

{integer}    { printf("Integer: %s\n", yytext); }

{id} {
    int isKeyword = 0;
    char keywords[10][10] = {"if", "else", "while", "for", "int", "float", "return", "break", "continue", "switch"};

    for (int i = 0; i < 10; i++) {
        if (strcmp(yytext, keywords[i]) == 0) {
            printf("Keyword: %s\n", yytext);
            isKeyword = 1;
            break;
        }
    }

    if (!isKeyword) {
        strcpy(symbolTable[symbolTableSize].name, yytext);
        symbolTable[symbolTableSize].tokenType = 1;
        symbolTableSize++;
        printf("Identifier: %s\n", yytext);
    }
}

.   { }

%%

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s input_file\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (!inputFile) {
        perror("Error opening input file");
        return 1;
    }

    yyin = inputFile;
    yylex();

    printf("\nSymbol Table:\n");
    for (int i = 0; i < symbolTableSize; i++) {
        printf("Name: %s, Token Type: %d\n", symbolTable[i].name, symbolTable[i].tokenType);
    }

    fclose(inputFile);

    return 0;
}
