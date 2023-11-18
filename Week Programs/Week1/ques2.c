// Week 1 Question 2
// Lab Assignment: Set of all strings ending with two symbols of the same type.

#include <stdio.h>

int isValidString(const char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    if (length >= 2 && (str[length - 1] == str[length - 2]))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char input[100];
    printf("Enter input: ");
    scanf("%s", input);
    if (isValidString(input))
    {
        printf("Valid String.\n");
    }
    else
    {
        printf("Invalid String.\n");
    }
    return 0;
}
