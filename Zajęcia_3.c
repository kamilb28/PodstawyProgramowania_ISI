#include <stdio.h>
#include <math.h>
#include <stdbool.h>

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
double zadanie_5(){
    double a,b,x;
    printf("Wpisz dwie liczby: ");
    scanf("%lf %lf",&a,&b);
    printf("dodaj(1), odejmij(2), pomnóż(3), podziel(4) ");
    scanf("%lf",&x);
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
void zadanie_6(){
    double a,b,c,x,X;
    printf("ax^2+bx+c=0\nWpisz:\na=");
    scanf("%lf",&a);
    printf("b=");
    scanf("%lf",&b);
    printf("c=");
    scanf("%lf",&c);
    if(b*b-4*a*c < 0 ) printf("nie ma pierwiastków");
    else if(a == 0) printf("to nie jest równanie kwadratowe!");
    else {
        x = (-b - sqrt(b * b - 4 * a * c)) / 2 * a;
        X = (-b - sqrt(b * b - 4 * a * c)) / 2 * a;
        printf("pierwiastki: %.2lf i %.2lf\n",x,X);
    }
}
void zadanie_7()
{
    int tablica[3];
    for(int i=0; i < 3; i++){
        printf("Wpisz [%d] miejsce:",i);
        scanf("%d",&tablica[i]);
    }
    printf("Kolejność odwrotna:\n");
    for(int i=2; i >= 0; i--){
        printf("[%d]\t",tablica[i]);
    }
}
void zadanie_9(){
    char słowa[4][20];
    for(int i=0; i < sizeof(słowa)/20; i++){
        scanf("%s", &słowa[i]);
    }
    for(int i=0; i < sizeof(słowa)/20; i++){
        printf("%s", słowa[i]);
        if(i != sizeof(słowa)/20 - 1) printf(", ");
    }
}
void tró_zadanie_11(){
    double a,b,c;
    printf("Podaj boki trójkąta: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    printf("Obwód: %.lf, Pole: %lf", a+b+c, (sqrt((a+b+c)*(a+b-c)*(a-b+c)*(-a+b+c)))/4);
}
void kwad_zadanie_11(){
    int a;
    printf("Podaj bok kwadratu: ");
    scanf("%d",&a);
    printf("Obwód: %d, Pole: %d", 4*a, a*a);
}
void prost_zadanie_11(){
    int a,b;
    printf("Podaj boki prostokąta: ");
    scanf("%d %d", &a, &b);
    printf("Obwód: %d, Pole: %d", 2*a + 2*b, a*b);
}
void zadanie_11(){
    int a;
    printf("trójkąt(1), kwadrat(2), prostokąt(3): ");
    scanf("%d", &a);
    switch (a){
        case 1: tró_zadanie_11();
            break;
        case 2: kwad_zadanie_11();
            break;
        case 3: prost_zadanie_11();
            break;
        default: printf("nie ma takiej figury\n");
            zadanie_11();
    }
}
int pytanie(int liczba){
    char odpowiedz;
    printf("Czy %d to twoja liczba? (T, M, W) ", liczba);
    scanf("%c", &odpowiedz);
    switch (odpowiedz){
        case 'T': return 0;
            break;
        case 'M': return 1;
            break;
        case 'W': return 2;
            break;
        default: printf("źle wpisana odpowiedź\n");
            return pytanie(liczba);
    }
}
void zadanie_12(){
    int liczba=5;
    printf("Wybierz liczbę od 1 do 10\n");
    int ODP=10;
    while(ODP != 0){
        ODP = pytanie(liczba);
        if(ODP == 1){
            liczba /= 2;
        }
        else if(ODP == 2){
            liczba = liczba/2 + liczba;
        }
    }
}
void zadanie_13(){
    int a;
    double b=0;
    scanf("%d", &a);
    for(int i=1; i <= a; i++){
        double czytaj;
        scanf("%lf", &czytaj);
        b += czytaj;
    }
    printf("%lf", b);
}
void Kelwin_na_Celcjusz(){
    int a;
    scanf("%d", &a);
    if (a < 0) a=0;
    printf("%d C", a-273);
}
void Celcjusz_na_Kelwin(){
    int a;
    scanf("%d", &a);
    if (a < -273) a=273;
    printf("%d K", a+273);
}
void zadanie_17(){
    int bool_CK;
    printf("K->C (0), C->K (1): ");
    scanf("%d",&bool_CK);
    if(bool_CK == 0) Kelwin_na_Celcjusz();
    else if (bool_CK == 1) Celcjusz_na_Kelwin();
    else printf("zła liczba\n");
}
void zadanie_18(){
    int tab[3];
    tab[0]=12;
    for(int i=0; i<sizeof(tab[3])/4; i++) printf("[%d]", i);
}
bool mam_cztery_certyfikaty_na_to(){
    return true;
}
void zadanie_19(){
    if(mam_cztery_certyfikaty_na_to() == true){
        printf("Jestem hardkorem!");
    }
    else printf("Ty gnoju jeden");
}
void zadanie_20(){
    char słowo[20];
    printf("Wpisz słowo: ");
    scanf("%s", słowo);
    if ( słowo[0] == 'K' || słowo[0] == 'k') printf("słowo zaczyna się od 'K'\n");
    else printf("słowo nie zaczyna się od 'K'\n");
}
void km_to_mi(){
    double a;
    scanf("%lf", &a);
    printf("%lf miles", a*0.621);
}
void mi_tokm(){
    int a;
    scanf("%lf", &a);
    printf("%lf kilometers", a*1.609);
}
void zadanie_21(){
    int bool;
    printf("km->mi (0), mi->km (1): ");
    scanf("%d",&bool);
    if(bool == 0) km_to_mi();
    else if (bool == 1) mi_tokm();
    else printf("zła liczba\n");
}
void zadanie_22(){
    int tab1[3] = {1,2,3};
    int tab2[3] = {4,5,6};
    int tab[6];
    for(int i = 0; i < sizeof(tab)/4; i++){
        if (i<3) tab[i] = tab1[i];
        else tab[i] = tab2[i-3];
        printf("[%d]", tab[i]);
    }
}
void zadanie_23(){
    float invest,profit;
    int months;
    char plus_minus = ' ';

    printf("Wprowadź koszt inwestycji: "); scanf("%f",&invest);
    printf("Wprowadź całkoite przychody z inwestycji: "); scanf("%f",&profit);
    printf("Ilość miesięcy: "); scanf("%d",&months);

    if(profit > invest) plus_minus = '+';

    printf("Ogólnie: %c%.2f%%\n", plus_minus, (profit*100)/invest - 100);
    printf("Miesięcznie: %c%.2f%%\n", plus_minus, ((profit*100)/invest - 100)/months);
}
void zadanie_24(){
    char word[100];
    int licznik;
    printf("Insert Word: "); scanf("%s", word);
    for(licznik=0; licznik < sizeof(word); licznik++){
        if(word[licznik] == '\0') break;
    }
    printf("Number of characters: %d\n", licznik);
}
int main(){
    //zadanie_3();
    //zadanie_4(); //tylko dla macierzy kwadratowych
    //printf("\n%lf", zadanie_5());
    //zadanie_6();
    //zadanie_7();
    //zadanie_9();
    //zadanie_11();
    //zadanie_12();
    //zadanie_13();
    //zadanie_17();
    //zadanie_18();
    //zadanie_19();
    //zadanie_20();
    //zadanie_21();
    //zadanie_22();
    //zadanie_23();
    //zadanie_24();
}

