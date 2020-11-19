#include <stdio.h>

int main()
{
    char imie[50];
    char nazwisko[50];

    scanf("%s", &imie);
    scanf("%s", &nazwisko);

    printf("Nazwisko: %s\nImie: %s\n", nazwisko, imie);

    return 0;
}

