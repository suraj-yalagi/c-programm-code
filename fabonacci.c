#include<stdio.h>
#include<ctype.h>
#define SIZE 40
int main()
{
    char ch,filename[SIZE];
    int num;
    int t1=0;
    int t2=1;
    int i;
    int result;
    FILE*fp;
    printf("enter the file name to read:\n");
    gets(filename);
    if((fp=fopen(filename,"r"))==NULL)
    {
        printf("cannot open the file=%s\n",filename);
    }
    else
    {
        puts("successfully opened,now reading.\n");
    }
    while((num=getw(fp))!=EOF)
        {
            if(num==1)
            {
                result=0;
            }
            else if(num==2)
            {
                result=1;
            }
            else
            {
                for(i=2;i<=num;i++)
                {
                    result=t1+t2;
                    t1=t2;
                    t2=result;
                }
            }
        }
        fclose(fp);
        char filename2[SIZE];
        FILE*fp2;
        fprintf(stdout,"please enter the file name to write in:\n");
        gets(filename2);
        if((fp2=fopen(filename2,"w"))==NULL)
        {
            printf("cannot create the file,%s\n",filename2);
        }
        else
        {
            fprintf(stdout,"%d",result);
        }
        fclose(fp2);
        fprintf(stdout,"%s\n",filename2);
    }
