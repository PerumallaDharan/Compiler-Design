// Week 7: Predictive parser
// Write a C program for the computation of FIRST and FOLLOW for a given CFG

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Take every small letter as a terminal symbol
// Take every capital letter as a non-terminal symbol
// Take every symbol other than letters as a terminal symbol
// Take ∈ as a terminal symbol
// Take $ as a terminal symbol

int main()
{
    FILE *fp1, *fp2;
    char input[100];
    int i = 0;
    fp1 = fopen("input.txt", "r");
    fp2 = fopen("output.txt", "w");
    fscanf(fp1, "%s", input);
    while (input[i] != '\0')
    {
        first();
    }
    close(fp1);
    close(fp2);
    return 0;
}