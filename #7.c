#include <stdio.h>
extern int factorial(int);
extern int factorial2(int , int);
extern int factorial3(int);
int main(int argc, char const *argv[])
{
    printf("%d\n", factorial(10));
    printf("%d\n", factorial2(10, 1));
    printf("%d\n", factorial3(10));
    return 0;
}

int factorial(int n)
{
    if(n == 1)
        return 1;
    else
        return factorial(n - 1) * n;
}
int factorial2(int n, int s)// Let s = 1, so that the func will work.
{
    if (n == 1)
        return s;
    else
        return factorial2(n - 1, n * s);
}
int factorial3(int n)
{
    int s = 1;
    while(n > 0)
    {
        s *= n;
        --n;
    }
    return s;
}