#include <stdio.h>

void zadanie_3(){
    int a;
    printf("Wpisz numer syna: ");
    scanf("%d", &a);
    if(a == 1 || a == 2) printf("słynął z mądrości");
    else if (a == 3) printf("poszedł do łączności");
    else printf("nie było tylu synów");
}
void zadanie_4(){
    int macierz[2][2];
    for(int i=0; i < sizeof(macierz)/8; i++) {
        for (int j = 0; j < sizeof(macierz)/8; j++) {
        printf("Wpisz [%d][%d] miejsce macierzy: ", i + 1, j + 1);
        scanf("%d",&macierz[i][j]);
        }
    }
    printf("twoja macierz:\n");
    for(int i=0; i < sizeof(macierz)/8; i++) {
        for (int j = 0; j < sizeof(macierz)/8; j++) {
            printf("[%d]", macierz[i][j]);
        }
        printf("\n");
    }
    printf("twoja macierz transponowana:\n");
    for(int i=0; i < sizeof(macierz)/8; i++) {
        for (int j = 0; j < sizeof(macierz)/8; j++) {
            printf("[%d]", macierz[j][i]);
        }
        printf("\n");
    }
}
int zadanie_5(){
    int a,b,x;
    printf("Wpisz dwie liczby:");
    scanf("%d %d",&a,&b);
    printf("dodaj(1), odejmij(2), pomnóż(3), podziel(4)");
    scanf("%d",&x);
    if(x==1) return a+b;
    else if (x==2)return a-b;
    else if (x==3) return a*b;
    else if (x==4){
        if(b != 0) return a/b;
        else{
            printf("nie wolno dzielić przez 0");
            return 0;
        }
    }
    else{
        printf("nie ma takiej operacji!");
        return 0;
    }
}

int main(){
    //zadanie_3();
    //zadanie_4(); //tylko dla macierzy kwadratowych
    printf("\n%d", zadanie_5());

    return 0;
}