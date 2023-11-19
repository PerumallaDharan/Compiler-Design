#include <stdio.h>
#include <stdlib.h>

void shift(char *input, int *ptr) {
    printf("Shift %c\n", input[*ptr]);
    (*ptr)++;
}

void reduce() {
    printf("Reduce\n");
}

void parse(char *input) {
    int ptr = 0;

    shift(input, &ptr);

    while (input[ptr] != '\0') {
        if (input[ptr] == 'd') {
            shift(input, &ptr);
        } else if (input[ptr] == '+' || input[ptr] == '*') {
            reduce();
            ptr++;
        } else if (input[ptr] == '(') {
            shift(input, &ptr);
        } else if (input[ptr] == ')') {
            reduce();
            ptr++;
        } else {
            printf("Invalid string\n");
            exit(0);
        }
    }

    reduce();

    printf("Valid string\n");
}

int main() {
    char str[100];
    printf("Enter the string: ");
    scanf("%s", str);

    parse(str);

    return 0;
}
