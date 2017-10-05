#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n, temp;
    scanf("%d", &n);
    temp = n;
    for(int i = 1; i < n; ++i)
    {
        if(n % i == 0)
        {
            temp -= i;
        }
    }
    if(temp == 0)
    {
        printf("Yes, %d is the sum its divisors.\n", n);
    }
    else
    {
        printf("Sorry, %d can not be the sum its divisors.\n", n);
    }
    return 0;
}
