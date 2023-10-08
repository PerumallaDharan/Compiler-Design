%{
#include<stdio.h>
%}

%%
["int"] { printf("%s is a keyword\n", yytext); }
[0123456789] { printf("%s is a digit\n", yytext); }
%%

int yywrap(){
    return 1;
}

int main(){
    yylex();
    return 0;
}