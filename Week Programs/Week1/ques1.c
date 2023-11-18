// Week 1 Question 1
// Set of all strings over binary alphabet containing even number of 0’s and even number of 1’s.

#include <stdio.h>

int isValidString(const char *str) {
    int count0 = 0, count1 = 0;
    while (*str != '\0') {
        if (*str == '0') {
            count0++;
        } else if (*str == '1') {
            count1++;
        } else {
            return 0;
        }
        str++;
    }
    return (count0 % 2 == 0) && (count1 % 2 == 0);
}

int main() {
    char input[100];
    printf("Enter input: ");
    scanf("%s", input);
    if (isValidString(input)) {
        printf("Valid String.\n");
    } else {
        printf("Invalid String.\n");
    }
    return 0;
}
