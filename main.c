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

void RUCH_GRACZA(int PLANSZA[8][8]){

    printf("Wybierz bierkę (np. A-2): ");
    scanf("%c-%d",)
}

void RUCH_PRZECIWNIKA(int PLANSZA[8][8]){

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