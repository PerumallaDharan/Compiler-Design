// Implement Predictive Parser using C for the Expression Grammar

// E  -> TE’
// E’ -> +TE’ | ε
// T  -> FT’
// T’ -> *FT’ | ε
// F  -> (E) | d

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

char input[100];
int i = 0;

bool E();
bool E_();
bool T();
bool T_();
bool F();

bool E()
{
    if (T())
    {
        if (E_())
        {
            return true;
        }
    }
    return false;
}

bool E_()
{
    if (input[i] == '+')
    {
        i++;
        if (T())
        {
            if (E_())
            {
                return true;
            }
        }
    }
    else
    {
        return true;
    }
    return false;
}

bool T()
{
    if (F())
    {
        if (T_())
        {
            return true;
        }
    }
    return false;
}

bool T_()
{
    if (input[i] == '*')
    {
        i++;
        if (F())
        {
            if (T_())
            {
                return true;
            }
        }
    }
    else
    {
        return true;
    }
    return false;
}

bool F()
{
    if (input[i] == '(')
    {
        i++;
        if (E())
        {
            if (input[i] == ')')
            {
                i++;
                return true;
            }
        }
    }
    else if (isdigit(input[i]))
    {
        i++;
        return true;
    }
    return false;
}

int main()
{
    FILE *fp1,*fp2;
    fp1 = fopen("input.txt","r");
    fp2 = fopen("output.txt","w");
    fscanf(fp1, "%s", input);
    if (E())
    {
        if (input[i] == '\0')
        {
            fprintf(fp2,"String is accepted\n");
        }
        else
        {
            fprintf(fp2,"String is not accepted\n");
        }
    }
    else
    {
        fprintf(fp2,"String is not accepted\n");
    }
    return 0;
}