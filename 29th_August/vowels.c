#include<stdio.h>
#include<ctype.h>
#define m 100
int main()
{
    FILE *fp1 = fopen("input.txt", "r");
    FILE *fp2 = fopen("output.txt","w");
    int vowels=0,consonants=0,lines=0;
    char c;
    char buffer[m];
    if (fp1 == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    int i=0;
    while ((c = fgetc(fp1)) != EOF)
    {
        if(c==' ' || c=='\n')
        {
            int j=i;
            if(buffer[j]=='0' && buffer[j-1]=='0')
                fprintf(fp2,"%s - Ends with 00\n",buffer);
            for(int j=0;j<i;j++)
            {
                if(buffer[j]=='0')
                {
                    if(buffer[j+1] =='0' && buffer[j+2]=='0')
                    {
                        fprintf(fp2,"%s - Has 3 consecutive 0's\n",buffer);
                        break;
                    }
                    
                }
            }
            i=0;
        }
        else{
            buffer[i]=c;
            i++;
        }
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
        {
            fprintf(fp2,"%c - Vowel\n",c);
            vowels+=1;
        }
        else if(c!=' ' && c!='\n' && !isdigit(c))
        {
            fprintf(fp2,"%c - Consonant\n",c);
            consonants+=1;
        }
        if(c=='\n')
        lines+=1;
        
    }
    fprintf(fp2,"Number of Vowels - %d\n",vowels);
    fprintf(fp2,"Number of Consonants - %d\n",consonants);
    fprintf(fp2,"Number of Lines - %d\n",lines);
    fclose(fp1);
    fclose(fp2);
}