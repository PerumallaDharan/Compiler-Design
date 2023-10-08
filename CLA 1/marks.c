// Write a program in C to calculate of gradation of student marks considering the following scenario.
// Obtained marks < 40 → Fail, Obtained marks < 50 → ‘D’ grade, Obtained marks < 60 → ‘C’ grade,
// Obtained marks < 70 → ‘B’ grade, Obtained marks < 80 → ‘A’ grade, Obtained marks < 90 → ‘A+’
// grade, Obtained marks <= 100 → ‘O’ grade.

#include <stdio.h>
int main()
{
    int marks;
    printf("Enter the marks: ");
    scanf("%d", &marks);
    if (marks < 40)
    {
        printf("Fail");
    }
    else if (marks < 50)
    {
        printf("D grade");
    }
    else if (marks < 60)
    {
        printf("C grade");
    }
    else if (marks < 70)
    {
        printf("B grade");
    }
    else if (marks < 80)
    {
        printf("A grade");
    }
    else if (marks < 90)
    {
        printf("A+ grade");
    }
    else if (marks <= 100)
    {
        printf("O grade");
    }
    else
    {
        printf("Invalid marks");
    }
    return 0;
}