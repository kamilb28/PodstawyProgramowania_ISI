#include <stdio.h>

int main()
{
    int h,m,s;
    printf("Godzina (HH:MM:SS): ");
    scanf("%d:%d:%d", &h, &m, &s);

    s += m*60 + h*3600;
    printf("to: %d sekund", s);
    return 0;
}

