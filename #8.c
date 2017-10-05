#include <stdio.h>
extern int Fibonacci(int n);
extern int Fibonacci2(int n);
int main(int argc, char const *argv[])
{
    printf("%d\n", Fibonacci(10));
    printf("%d\n", Fibonacci2(10));
    return 0;
}


int Fibonacci(int n)
{
    if(n == 1)
        return 0;
    else if(n == 2)
        return 1;
    else
        return (Fibonacci(n - 1) + Fibonacci(n - 2));
}
int Fibonacci2(int n)
{
    int x = 0, y = 1;
    int temp;
    if(n == 1)
        return 0;
    else if(n == 2)
        return 1;
    else
        while(n - 2 > 0)
        {
            --n;
            temp = x + y;
            x = y;
            y = temp;
        }
    return temp;
}