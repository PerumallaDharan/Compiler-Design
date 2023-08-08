#include<stdio.h>
#include<stdlib.h>
int main(){

    FILE *f1 = fopen("input.txt", "r");
    if(f1 == NULL){
        printf("Error opening file\n");
        exit(1);
    }

    char c;
    FILE *f2 = fopen("output.txt", "w");

    while ((c=fgetc(f1)) != EOF)
    {
        fputc(c, f2);
    }
    
    printf("File copied successfully\n");
    fclose(f1);
    fclose(f2);
    return 0;    
}