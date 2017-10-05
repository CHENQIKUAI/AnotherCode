#include <stdio.h>
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
extern void swap(int *a, int *b);
int main(int argc, char const *argv[])
{
    int array[3];
    for(int i = 0; i < 3; ++i)
    {
        scanf("%d", &array[i]);
    }
    for(int i = 0; i < 3 - 1; ++i)
    {
        for(int j = i; j < 3; ++j)
        {
            if(array[i] > array[j])
            {
                //SWAP(array[i], array[j], temp);
                swap(&array[i], &array[j]);
            }
        }
    }
    for(int i = 0; i < 3; ++i)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}