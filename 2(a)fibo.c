#include <stdio.h>

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    int t;

    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &t);

    printf("Fibonacci Series: ");
    for (int i = 0; i < t; i++)
    {
       int fib=fibonacci(i);
       printf("%d ",fib);
    }

    return 0;
}
