#include<stdio.h>
char ch;
int main()
{
    int a,b,c;


    while(1)
    {
    printf("enter case\n");
    scanf("%c",&ch);
     printf("enter two no's:\n");
    scanf("%d",&a);
    scanf("%d",&b);
        switch(ch)
        {
        case '+':
            c=a+b;
            break;

        case'-':
            c=a-b;
            break;

        case'*':
            c=a*b;
            break;

        case'/':
            c=a/b;
            break;

        }
        printf("%d\n",c);
    }
    return 0;

}
