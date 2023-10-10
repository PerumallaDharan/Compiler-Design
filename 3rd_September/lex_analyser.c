#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEYWORDS 100
#define MAX_INDENT_LEN 100

char keywords[MAX_KEYWORDS][MAX_INDENT_LEN] = {
    "int",
    "if",
    "else",
    "for",
    "while",
    "then",
    "endif",
    "print",
};

int isKeyword(char *str)
{
    for (int i = 0; i < MAX_KEYWORDS; i++)
    {
        if (strcmp(str, keywords[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int isDigit(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
        {
            return 0;
        }
    }
    return 1;
}

int isLetter(char *str)
{
    if (!((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z')))
    {
        return 0;
    }
    for (int i = 1; i < strlen(str); i++)
    {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
        {
            return 0;
        }
    }
    return 1;
}

int isMulop(char *str)
{
    if (strcmp(str, "*") == 0 || strcmp(str, "/") == 0)
    {
        return 1;
    }
    return 0;
}

int isAddop(char *str)
{
    if (strcmp(str, "+") == 0 || strcmp(str, "-") == 0)
    {
        return 1;
    }
    return 0;
}

int isRelop(char *str)
{
    if (strcmp(str, "<") == 0 || strcmp(str, ">") == 0 || strcmp(str, "<=") == 0 || strcmp(str, ">=") == 0 || strcmp(str, "==") == 0 || strcmp(str, "!=") == 0)
    {
        return 1;
    }
    return 0;
}

int isAssignmnetop(char *str)
{
    if (strcmp(str, "=") == 0)
    {
        return 1;
    }
    return 0;
}

int isParenthesis(char *str)
{
    if (strcmp(str, "(") == 0 || strcmp(str, ")") == 0 || strcmp(str, "{") == 0 || strcmp(str, "}") == 0)
    {
        return 1;
    }
    return 0;
}

int isIdentifier(char *str)
{
    if (!((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z')))
    {
        return 0;
    }
    for (int i = 1; i < strlen(str); i++)
    {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')))
        {
            return 0;
        }
    }
    return 1;
}

int isComment(char *str)
{
    if ((str[0] == '/' && str[1] == '/') || (str[0] == '/' && str[1] == '*') || (str[0] == '*' && str[1] == '/'))
    {
        return 1;
    }

    return 0;
}

int main()
{
    FILE *fp;
    fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(0);
    }
    char ch;
    char str[MAX_INDENT_LEN];
    int i = 0;
    FILE *fp2 = fopen("output.txt", "w");
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == ' ' || ch == '\n' || ch == '\t' || isspace(ch))
        {
            if (i > 0)
            {
                str[i] = '\0';
                if (isKeyword(str))
                {
                    fprintf(fp2, "Keyword : %s\n", str);
                }
                else if (isDigit(str))
                {
                    fprintf(fp2, "Integer : %s\n", str);
                }
                else if (isLetter(str))
                {
                    fprintf(fp2, "Letter : %s\n", str);
                }
                else if (isMulop(str))
                {
                    fprintf(fp2, "Multiplication Operator : %s\n", str);
                }
                else if (isAddop(str))
                {
                    fprintf(fp2, "Addition Operator : %s\n", str);
                }
                else if (isRelop(str))
                {
                    fprintf(fp2, "Relational Operator : %s\n", str);
                }
                else if (isAssignmnetop(str))
                {
                    fprintf(fp2, "Assignment Operator : %s\n", str);
                }
                else if (isParenthesis(str))
                {
                    fprintf(fp2, "Parenthesis : %s\n", str);
                }
                else if (isIdentifier(str))
                {
                    fprintf(fp2, "Identifier : %s\n", str);
                }
                else if (isComment(str))
                {
                    fprintf(fp2, "Comment : %s\n", str);
                }
                else
                {
                    fprintf(fp2, "Invalid : %s\n", str);
                }
                i = 0;
            }
        }
        else
        {
            str[i++] = ch;
        }
    }
    fclose(fp);
    fclose(fp2);
    return 0;
}