// Implement lexical analyzer using C for recognizing the following tokens:
// - A minimum of 10 keywords of your choice
// - Identifiers with the regular expression : letter(letter | digit)*
// - Integers with the regular expression: digit+
// - Relational operators: &lt;, &gt;, &lt;=, &gt;=, ==, !=
// - Storing identifiers in symbol table.
// - Using files for input and output.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_KEYWORDS 100
#define MAX_INDENT_LEN 100

char keywords[MAX_KEYWORDS][MAX_INDENT_LEN]={
    "int",
    "float",
    "char",
    "double",
    "if",
    "else",
    "for",
    "while",
    "do",
    "switch",
    "main()"
};

int isKeyword(char *str){
    for(int i=0;i<MAX_KEYWORDS;i++){
        if(strcmp(str,keywords[i])==0){
            return 1;
        }
    }
    return 0;
}

int isIdentifier(char *str){
    if(!((str[0]>='a' && str[0]<='z') || (str[0]>='A' && str[0]<='Z'))){
        return 0;
    }
    for(int i=1;i<strlen(str);i++){
        if(!((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') || (str[i]>='0' && str[i]<='9'))){
            return 0;
        }
    }
    return 1;
}

int isInteger(char *str){
    for(int i=0;i<strlen(str);i++){
        if(!(str[i]>='0' && str[i]<='9')){
            return 0;
        }
    }
    return 1;
}

int isRelationalOperator(char *str){
    if(strcmp(str,"<")==0 || strcmp(str,">")==0 || strcmp(str,"<=")==0 || strcmp(str,">=")==0 || strcmp(str,"==")==0 || strcmp(str,"!=")==0){
        return 1;
    }
    return 0;
}

int isParenthesis(char *str){
    if(strcmp(str,"(")==0 || strcmp(str,")")==0 || strcmp(str,"{")==0 || strcmp(str,"}")==0){
        return 1;
    }
    return 0;
}

int main(){
    FILE *fp;
    fp=fopen("input.txt","r");
    if(fp==NULL){
        printf("Error opening file\n");
        exit(0);
    }
    char ch;
    char str[MAX_INDENT_LEN];
    int i=0;
    FILE *fp2=fopen("output.txt","w");
    while((ch=fgetc(fp))!=EOF){
        if(ch==' ' || ch=='\n' || ch=='\t'){
            if(i>0){
                str[i]='\0';
                if(isKeyword(str)){
                    // printf("%s is a keyword\n",str);
                    fprintf(fp2,"Keyword             : %s\n",str);
                }
                else if(isIdentifier(str)){
                    // printf("%s is an identifier\n",str);
                    fprintf(fp2,"Identifier          : %s\n",str);
                }
                else if(isInteger(str)){
                    // printf("%s is an integer\n",str);
                    fprintf(fp2,"Interger            : %s\n",str);
                }
                else if(isRelationalOperator(str)){
                    // printf("%s is a relational operator\n",str);
                    fprintf(fp2,"Relational Operator : %s\n",str);
                }
                else if(isParenthesis(str)){
                    // printf("%s is a parenthesis\n",str);
                    fprintf(fp2,"Parenthesis         : %s\n",str);
                }
                else{
                    // printf("%s is an invalid token\n",str);
                    fprintf(fp2,"Invalid Token       : %s\n",str);
                }
                i=0;
            }
        }
        else{
            str[i++]=ch;
        }
    }
    fclose(fp);
    fclose(fp2);
    return 0;
}