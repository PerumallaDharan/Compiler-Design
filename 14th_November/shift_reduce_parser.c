// // Implementation of Shift Reduce parser using C for the following
// // grammar and illustrate the parser’s actions for a valid and an invalid string.

// // S –&gt; 0S0 | 1S1 | 2

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int top = -1;
// char stack[100];

// void push(char c)
// {
//     stack[++top] = c;
// }

// void pop()
// {
//     if (top == -1)
//     {
//         printf("Invalid String\n");
//         exit(0);
//     }
//     else
//     {
//         top--;
//     }
// }

// int main()
// {
//     char str[100];
//     int i;
//     printf("Enter the string: ");
//     scanf("%s", str);
//     int count_2 = 0;
//     for (i = 0; i < strlen(str) && top != -1; i++)
//     {
//         if (str[i] == '0' || str[i] == '1')
//         {
//             push(str[i]);
//         }
//         else if (str[i] == '2')
//         {
//             count_2++;
//             for (int j = i ; j < strlen(str); j++)
//             {
//                 if (str[j] == '0' || str[j] == '1')
//                 {
//                     pop();
//                 }
//             }
//         }
//     }
//     if (top == -1 && count_2 == 1)
//     {
//         printf("Valid String\n");
//     }
//     else
//     {
//         printf("Invalid String\n");
//     }
//     return 0;
// }

//Implementation of Shift Reduce Parser

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
