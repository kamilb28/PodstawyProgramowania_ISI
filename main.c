#include <stdio.h>

char BIERKA(int liczba_bierki);

void WYPISZ_PLANSZE(int PLANSZA[8][8])
{
    printf(" A | B | C | D | E | F | G | H |\n"); //litera kolumny
    for (int i = 0; i < 8; i++){  //wiersze
        printf("---|---|---|---|---|---|---|---|---\n"); //seperatory między wierszami
        for (int j = 0; j < 8; j++){  //kolumny
            printf(" %c |", BIERKA(PLANSZA[i][j]));  // wypisuje naszą bierkę i separator kolumn
        }
        printf(" %d\n", 8 - i); //liczba wiersza
    }
}

char BIERKA(int liczba_bierki)
{
    switch (liczba_bierki)
    {
        case -1:
            return 'P'; //Pion
        case -2:
            return 'W'; //Wieżą
        case -3:
            return 'S'; //Skoczek-Koń
        case -4:
            return 'G'; //Goniec-Laufr
        case -5:
            return 'H'; //Hetman-Królowa
        case -6:
            return 'K'; //Król

        case 1:
            return 'p'; //Pion przeciwnika
        case 2:
            return 'w'; //Wieżą przeciwnika
        case 3:
            return 's'; //Skoczek-Koń przeciwnika
        case 4:
            return 'g'; //Goniec-Laufer przeciwnika
        case 5:
            return 'h'; //Hetman-Królowa przeciwnika
        case 6:
            return 'k'; //Król przeciwnika

        case 0:
            return ' ';
    }
}

typedef struct Pole_na_planszy { char a; int i; };

void RUCH_GRACZA(int PLANSZA[8][8]){
    struct Pole_na_planszy RuchZ;
    struct Pole_na_planszy RuchDO;

    printf("Wybierz bierkę (np. A-2): ");
    scanf("%c-%d", &RuchZ.a, &RuchZ.i);
    RuchZ.i = 8-RuchZ.i;                //odejmujemy bo plansza ma na górze "8" a tablica 0
    if (!(RuchZ.a >= 'A' && RuchZ.a <= 'H') || !(RuchZ.i >= 0 && RuchZ.i <=7)){
        printf("źle wybrana bierka\n");
        RUCH_GRACZA(PLANSZA);
    }
    int RuchZZ = RuchZ.a - 'A';          // zamiana liter na liczby tablicy
    if (PLANSZA[RuchZ.i][RuchZZ] >= 0){
        printf("źle wybrana bierka (wybierz TWOJĄ bierkę)\n");
        RUCH_GRACZA(PLANSZA);
    }

    printf("Gdzie mam wykonać ruch?: ");
    scanf("%c-%d", &RuchDO.a, &RuchDO.i);
    RuchDO.i = 8-RuchDO.i;    //odejmujemy bo plansza ma na górze "8" a tablica 0
    printf("[%a][%d]", RuchDO.a, RuchDO.i);
    if (!(RuchDO.a >= 'A' && RuchDO.a <= 'H') || !(RuchDO.i >= 0 && RuchDO.i <=7)){
        printf("miejsce poza planszą\n");
        RUCH_GRACZA(PLANSZA);
    }
    int RuchDD = RuchDO.a - 'A';        // zamiana liter na liczby tablicy
    if (PLANSZA[RuchDO.i][RuchDD] < 0){
        printf("nie możesz zbić wsłasnych figur i pionków\n");
        RUCH_GRACZA(PLANSZA);
    }
    PLANSZA[RuchDO.i][RuchDD]=PLANSZA[RuchZ.i][RuchZZ];    // idziemy na wskazanie miejsce
    PLANSZA[RuchZ.i][RuchZZ]=0;                           // pozaostawiamy puste miejsce skad sie ruszylismy
}

void RUCH_PRZECIWNIKA(int PLANSZA[8][8]){
    printf("tu bedzie ruch przeciwnika");

}

int main()
{
    int PLANSZA[8][8]={{2, 3, 4, 6, 5, 4, 3, 2},
                       {1, 1, 1, 1, 1, 1, 1, 1},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {-1, -1, -1, -1, -1, -1, -1, -1},
                       {-2, -3, -4, -6, -5, -4, -3, -2}};

    WYPISZ_PLANSZE(PLANSZA);

    int bool = 1;
    while (bool){
        RUCH_GRACZA(PLANSZA);
        WYPISZ_PLANSZE(PLANSZA);
        RUCH_PRZECIWNIKA(PLANSZA);
        WYPISZ_PLANSZE(PLANSZA);
        return 0;
    }
/*
{B_Wieża, B_Skoczek, B_Goniec, B_Król, B_Hetman, B_Goniec, B_Skoczek, B_Wieża},
{B_Pion, B_Pion, B_Pion, B_Pion, B_Pion, B_Pion, B_Pion, B_Pion},
{-, -, -, -, -, -, -, -},
{-, -, -, -, -, -, -, -},
{-, -, -, -, -, -, -, -},
{-, -, -, -, -, -, -, -},
{B_Pion, B_Pion, B_Pion, B_Pion, B_Pion, B_Pion, B_Pion, B_Pion};
{B_Wieża, B_Skoczek, B_Goniec, B_Król, B_Hetman, B_Goniec, B_Skoczek, B_Wieża},
*/


    return 0;
}