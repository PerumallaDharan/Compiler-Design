
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[100];
int pointer = 0;
int error = 0;

void S();
void B();

void match(char c) {
    if (input[pointer] == c) {
        pointer++;
    } else {
        error = 1;
    }
}

void S() {
    if (input[pointer] == 'a') {
        printf("S -> a");
        match('a');
        B();
        printf("a\n");
        if (input[pointer] == 'a') {
            match('a');
        } else {
            error = 1;
            printf("Error: Expected 'a' after 'B'\n");
        }
    } else {
        error = 1;
        printf("Error: Expected 'a' at the beginning\n");
    }
}

void B() {
    if (input[pointer] == 'b') {
        printf("B -> b");
        match('b');
        B();
        printf("b\n");
    } else {
        printf("B -> e\n");
    }
}

int main() {
    char grammar[100];
    char line[100];

    printf("Enter the grammar rules line by line. Type 'break' on a new line to finish grammar input:\n");
    grammar[0] = '\0';

    while (1) {
        fgets(line, sizeof(line), stdin);

        if (strcmp(line, "break\n") == 0) {
            break;
        }

        strcat(grammar, line);
    }

    printf("Grammar input completed. Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    pointer = 0;
    error = 0;

    if (strcmp(grammar, "S -> aBa\nB -> bB | e\n") != 0) {
        printf("Grammar is not as expected.\n");
        return 1;
    }

    printf("Parsing steps:\n");
    S();

    if (error == 0 && input[pointer] == '\0') {
        printf("Parsing successful\n");
    } else {
        printf("Parsing error\n");
    }

    return 0;
}
