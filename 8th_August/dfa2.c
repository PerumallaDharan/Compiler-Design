// Design a DFA to accept even no of zeroes
// Date: 8/08/2023

#include<stdio.h>
#include<stdlib.h>
#define max 100
int main(){
    char str[max], f = 'a';
    FILE *fp1 = fopen("dfa2_input.txt", "r");
    if (fp1 == NULL)
    {
        printf("Error in opening file");
        return 0;
    }
    fgets(str,max,fp1);

    for (int i = 0; str[i] != '\0'; i++)
    {
        switch (f)
        {
        case 'a':
            if (str[i] == '0')
                f = 'b';
            else if (str[i] == '1')
                f = 'a';
            break;
        case 'b':
            if (str[i] == '0')
                f = 'a';
            else if (str[i] == '1')
                f = 'b';
            break;
        }
    }

    FILE *fp2 = fopen("dfa2_output.txt", "w");
    if (fp2 == NULL)
    {
        printf("Error in opening file");
        return 0;
    }
    
    if (f=='a')
        fprintf(fp2, "String is accepted");
    else
        fprintf(fp2, "String is not accepted");

    fclose(fp1);
    fclose(fp2);
    return 0;    
}