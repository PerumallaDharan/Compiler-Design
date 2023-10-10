#include <string.h>
#include <ctype.h>
#include <stdio.h>

void keyword(char str[10])
{
    if (strcmp("for", str) == 0 || strcmp("while", str) == 0 || strcmp("do", str) == 0 || strcmp("int", str) == 0 || strcmp("float", str) == 0 || strcmp("char", str) == 0 || strcmp("double", str) == 0 || strcmp("static", str) == 0 || strcmp("switch", str) == 0 || strcmp("case", str) == 0)
        printf("\n%s is a keyword", str);
    else
        printf("\n%s is an identifier", str);
}

int main()
{
    FILE *f1, *f2, *f3;
    char c, str[10], st1[10];
    int num[100], lineno = 0, tokenvalue = 0, i = 0, j = 0, k = 0;

    // Open the input file for reading
    f1 = fopen("input.txt", "r");

    // Check if the file was successfully opened
    if (f1 == NULL)
    {
        printf("Failed to open the input file.\n");
        return 1; // Exit with an error code
    }

    // Rest of the code remains mostly the same
    printf("\nThe numbers in the program are");
    while ((c = getc(f1)) != EOF)
    {
        if (isdigit(c))
        {
            tokenvalue = c - '0';
            c = getc(f1);
            while (isdigit(c))
            {
                tokenvalue = tokenvalue * 10 + (c - '0');
                c = getc(f1);
            }
            num[i++] = tokenvalue;
            ungetc(c, f1);
        }
        else if (isalpha(c))
        {
            f2 = fopen("identifier", "a"); // Open the file in append mode
            if (f2 == NULL)
            {
                printf("Failed to open the identifier file.\n");
                return 1; // Exit with an error code
            }
            putc(c, f2);
            c = getc(f1);
            while (isdigit(c) || isalpha(c) || c == '_' || c == '$')
            {
                putc(c, f2);
                c = getc(f1);
            }
            putc(' ', f2);
            fclose(f2);
            ungetc(c, f1);
        }
        else if (c == ' ' || c == '\t')
        {
            printf(" ");
        }
        else if (c == '\n')
        {
            lineno++;
        }
        else
        {
            f3 = fopen("specialchar", "a"); // Open the file in append mode
            if (f3 == NULL)
            {
                printf("Failed to open the specialchar file.\n");
                return 1; // Exit with an error code
            }
            putc(c, f3);
            fclose(f3);
        }
    }

    // Close the input file
    fclose(f1);

    // Print the numbers extracted from the input program
    for (j = 0; j < i; j++)
        printf("%d ", num[j]);
    printf("\n");

    // Open the identifier file for reading
    f2 = fopen("identifier", "r");

    // Check if the file was successfully opened
    if (f2 == NULL)
    {
        printf("Failed to open the identifier file.\n");
        return 1; // Exit with an error code
    }

    k = 0;
    printf("The keywords and identifiers are:");
    while ((c = getc(f2)) != EOF)
    {
        if (c != ' ')
            str[k++] = c;
        else
        {
            str[k] = '\0';
            keyword(str);
            k = 0;
        }
    }

    // Close the identifier file
    fclose(f2);

    // Open the specialchar file for reading
    f3 = fopen("specialchar", "r");

    // Check if the file was successfully opened
    if (f3 == NULL)
    {
        printf("Failed to open the specialchar file.\n");
        return 1; // Exit with an error code
    }

    printf("\nSpecial characters are: ");
    while ((c = getc(f3)) != EOF)
        printf("%c", c);
    printf("\n");

    // Close the specialchar file
    fclose(f3);

    printf("Total number of lines are: %d\n", lineno);

    return 0;
}