#include <stdio.h>

int main()
{
    int h,m,s;
    printf("Godzina(HH:MM:SS): ");
    scanf("%d:%d:%d",&h,&m,&s);
    printf("ma %d sekund", h*3600+m*60+s);

    return 0;

