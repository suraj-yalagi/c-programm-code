#include<stdio.h>
int main()
{
     double fact=1;
     int i,n;
    printf("enter the value of n:\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        fact=fact*i;
    }
    printf("%f",fact);
    return 0;

}
