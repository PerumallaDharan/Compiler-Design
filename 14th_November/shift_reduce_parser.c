
#include <stdio.h>
#include <stdbool.h>

// Function prototypes
bool match(char expected, char input);
bool S(char input[], int *index);

int main() {
    char input[50];

    // Get input from the user
    printf("Enter the input string: ");
    scanf("%s", input);

    // Start parsing from the beginning of the input
    int index = 0;
    if (S(input, &index) && input[index] == '\0') {
        printf("Accepted\n");
    } else {
        printf("Not Accepted\n");
    }

    return 0;
}

// Function to check if the expected character matches the current input character
bool match(char expected, char input) {
    if (expected == input) {
        return true;
    } else {
        return false;
    }
}

// Recursive descent parser for the grammar S -> 0S0 | 1S1 | 2
bool S(char input[], int *index) {
    if (input[*index] == '0') {
        (*index)++;
        if (S(input, index)) {
            if (input[*index] == '0') {
                (*index)++;
                return true;
            }
        }
    } else if (input[*index] == '1') {
        (*index)++;
        if (S(input, index)) {
            if (input[*index] == '1') {
                (*index)++;
                return true;
            }
        }
    } else if (input[*index] == '2') {
        (*index)++;
        return true;
    }

    return false;
}
