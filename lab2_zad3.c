#include <stdio.h>

int i=0;

int main()
{
    printf("%d\n", i);

    int i = 1;

    printf("%d\n", i);
    {
        int i = 2;
        printf ("%d\n",i);
    }
    printf("%d\n", i);
    return 0;
}