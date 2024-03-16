#include<stdio.h>
#include<math.h>
int main()
{
    int n,i;
    printf("enter the value of n:\n");
    scanf("%d",&n);
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
           printf(" not prime");
        }
        else
        {
            printf(" prime");
        }
    }
     return 0;
}
