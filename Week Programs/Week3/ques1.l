%{
#include <stdio.h>

int vowelCount = 0;
int consonantCount = 0;
int lineCount = 0;

%}

%%
[aeiouAEIOU]    { printf("%s is a vowel\n", yytext); vowelCount++; }
[a-zA-Z]        { printf("%s is a consonant\n", yytext); consonantCount++; }
\n              { lineCount++; }
.*00$           { printf("String ending with 00: %s\n", yytext); }
.*000.*         { printf("String with three consecutive 0's: %s\n", yytext); }
.               { /* Ignore other characters */ }

%%

int yywrap() {
    return 1; // Signal that there are no more files to process
}

int main() {
    printf("Enter text:\n");
    yylex();
    
    printf("\nAnalysis Results:\n");
    printf("Number of vowels: %d\n", vowelCount);
    printf("Number of consonants: %d\n", consonantCount);
    printf("Number of lines: %d\n", lineCount);

    return 0;
}
