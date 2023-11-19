#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool match(char expected, char input);
bool S(char input[], int *index);

int main() {
    char input[50];
    printf("Enter the input string: ");
    scanf("%s", input);

    int index = 0;
    if (S(input, &index) && input[index] == '\0') {
        printf("Accepted\n");
    } else {
        printf("Not Accepted\n");
    }

    return 0;
}

bool match(char expected, char input) {
    return expected == input;
}

bool S(char input[], int *index) {
    if (input[*index] == '0') {
        (*index)++;
        if (S(input, index) && input[*index] == '0') {
            (*index)++;
            return true;
        }
    } else if (input[*index] == '1') {
        (*index)++;
        if (S(input, index) && input[*index] == '1') {
            (*index)++;
            return true;
        }
    } else if (input[*index] == '2') {
        (*index)++;
        return true;
    }

    return false;
}
