#include<stdio.h>
int main()
{
    char string[100];
    printf("Enter the word\n");
    gets(string);
    for(int i=0; i<strlen(string); i++)
    {
        if(i==0)
        {
           printf("%c",toupper(string[i]));
        }
        else if(string[i]==' ')
        {
           printf(" %c",toupper(string[i+1]));
           i++;
        }
        else
        {
            printf("%c",string[i]);
        }
    }
    return 0;
}
