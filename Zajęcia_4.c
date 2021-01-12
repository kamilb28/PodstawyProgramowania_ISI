#include <stdio.h>
#include <stdbool.h>

const int table_1[10]={5,7,3,4,9,7,0,1,12,3};
const int table_2[10]={8,4,1,9,20,4,8,3,5,6};

void zadanie_1(){
    for(int i=1; i<=10; i++) printf("%d ",i);
}
void zadanie_2(){
    for(int i=10; i>0; i -= 2) printf("%d ",i);
}
bool if_exist(int a,int tab[]){
    for(int i=0; i<sizeof(tab); i++){
        if(tab[i] == a) return true;
    }
    return false;
}
void zadanie_3(){
    int tablica[10]={1,4,6,8,2,3,6,6,1,3};
    int liczba;
    printf("Czy liczba jest w tablicy: (podaj liczbę 0-9) "); scanf("%d",&liczba);
    printf("%d\n",if_exist(liczba,tablica));
}
zadanie_4(){
    char litera;
    char słowo[4][20]= {{'a','n','a','n','a','s'},
                        {'b','a','n','a','n'},
                        {'c','y','t','r','y','n','a'},
                        {'d','y','n','i','a'}};
    printf("Litera: "); scanf("%c",&litera);
    for(int i=0; i < sizeof(słowo)/20; i++){
        if( słowo[i][0] == litera ) printf("%s\n", słowo[i]);
    }
}
void zadanie_6(){
    int tablica[10] = {9,6,8,2,1,13,4,6,5,7};
    int min = tablica[0];
    for(int i=1; i < sizeof(tablica)/4; i++){
        if(tablica[i] < min) min = tablica[i];
        if(tablica[i] == '\0') break;
    }
    printf("%d\n",min);
}
int l_word(char word[]){
    int i;
    for(i=0; i < sizeof(word); i++){
        if(word[i] == '\0') break;
    }
    return i;
}
void zadanie_7(){
    char tekst1[50];
    char tekst2[50];
    bool takie_same = true;
    scanf("%s",&tekst1);
    scanf("%s",&tekst2);
    if(l_word(tekst1) == l_word(tekst2)) {
        for (int i = 0; i < 50; i++) {
            if (tekst1[i] != tekst2[i]) {
                takie_same = false;
            }
        }
        if (takie_same == true) printf("są takie same");
        else if(takie_same == false) printf("nie są takie same");
    }
    else{printf("nie są takie same");}
}
void zadanie_11(){
//  Wyświetl iloczyn kartezjański elementów dwóch tablic
    int a = 10; //popatrz na to raz jeszcze
    for(int i=0; i < a; i++) {
        for (int j = 0; j < a; j++)
            printf("(%d,%d),", table_1[i], table_2[j]);
        printf("\n");
    }
}
void zadanie_12(){
// Napisz program, ktory wyswietli wszystkie liczby podzielne przez 6 mniejsze niz 100
    for(int i=0; i < 100; i++)
        if(i % 6 == 0) printf("%d\n",i);
}
void zadanie_13(){
// Napisz program, ktory zsumuje liczby od 30 do 100 i wyswietli je na ekranie wykorzystując pętle while
    int a=30;
    int b=a;
    while(a <= 100){
        a++;
        b += a;
    }
    printf("%d",b);
}
void zadanie_14(){
    //Kalkulator w switchu
    int i=1;
    char operator;
    float a,b,wynik;
    printf("(a (+,-,*,/) b): "); scanf("%f%c%f", &a, &operator, &b);
    switch (operator){
        case '+': wynik = a+b;
            break;
        case '-': wynik = a-b;
            break;
        case '*': wynik = a*b;
            break;
        case '/': wynik = a/b;
            break;
        default: i=0;
    }
    if(i != 0) printf("= %f\n",wynik);
}
void zadanie_15(){
    //Sprawdzić długość tekstu i wyświetlić
    const char tekst[]="Tutaj tekst";
    printf("%d",sizeof(tekst)-1);
}
void zadanie_16(){
    //Wczytać dwie liczby jako wymiary macierzy, następnie wczytać tyle liczb, wyświetlić transponowane
    int x,y;
    printf("Wprowadź wymiary macierzy:\nx: "); scanf("%d", &x); printf("y: "); scanf("%d", &y);

    int macierz[x][y];
    int macierz_t[y][x];

    for(int i=0; i < x; i++) {
        for (int j = 0; j < y; j++)
            printf("[x%dy%d]", i + 1, j + 1);
        printf("\n");
    }
    printf("\n");

    for(int i=0; i < x; i++)
        for (int j = 0; j < y; j++) {
            printf("[x%dy%d]= ", i + 1, j + 1);
            scanf("%d", &macierz[i][j]);
        }

    printf("Twoja macierz:\n");
    for(int i=0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("[%d]", macierz[i][j]);
            macierz_t[j][i] = macierz[i][j];
        }
        printf("\n");
    }

    printf("macierz transponowana:\n");
    for(int i=0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            printf("[%d]", macierz_t[i][j]);
        }
        printf("\n");
    }
}
bool czy_posortowana(int tab[]){
    if(tab[0] >= tab[1]) {
        for (int i = 1; i < sizeof(tab); i++){
            if(tab[i] < tab[i+1]) return false;
        }
        return true;
    }
    else if (tab[0] <= tab[1]){
        for (int i = 1; i < sizeof(tab); i++){
            if(tab[i] > tab[i+1]) return false;
        }
        return true;
    }
    return false;
}
void napis_TAK_NIE(int a,bool b){
    if(b == true) printf("Tablica_%d jest posortowana\n",a);
    else printf("Tablica_%d nie jest posortowana\n",a);
}
void zadanie_17(){
    const int tablica_1[]={0,1,2,3,4,5,6,7,8,9};
    const int tablica_2[]={8,9,1,5,4,3,5,2,2,1};
    const int tablica_3[]={9,8,7,6,5,4,3,2,1,0};
    bool t_1,t_2,t_3;
    t_1 = czy_posortowana(tablica_1);
    t_2 = czy_posortowana(tablica_2);
    t_3 = czy_posortowana(tablica_3);
    napis_TAK_NIE(1,t_1);
    napis_TAK_NIE(2,t_2);
    napis_TAK_NIE(3,t_3);
}
void zadanie_18(){
    //Napisz pytanie, które będzie pytać użytkownika o coś czym użytkownik nie chce być, do czasu aż użytkownik odpowie twierdząco
    bool b = true;
    char a = 'n';
    while (b) {
        {
            printf("Proszę napisz 'T' ");
            scanf("%c", &a);
        }
        if( a == 'T' ) b = false;
    }
}
void zadanie_19() {
    printf("ANSCII\n");
    for (int i=0; i <= 127; i++){
        char wynik = (char)i; // efektem "wyniku" bedzie zank ANSII
        printf("%d\t%c\n", i, wynik);
    }
}
void zadanie_21(){
    // Program, który sprawdzi, czy zadana liczba rzeczywista jest w tablicy
    int a;
    scanf("%i", &a);
    for(int i=0; i < sizeof(table_1); i++){
        if( a == table_1[i] ) printf("%i jest w tablicy\n",a);
    }
}
bool if_prime(int a){
    for(int i=2; i <= a/2; i++){
        //printf("%d\n", i); //ilość literacji, pewnie można zoptymalizować
        if (( a % i ) == 0) return false;
    }
    return true;
}
int zadanie_22(){
    //Sprawdź czy liczba pierwsza
    int prime;
    printf("Insert number: "); scanf("%d", &prime);
    if( if_prime(prime) == true) {printf("%d is a prime number\n", prime);}
    else {printf("%d isnt a prime number\n", prime);}
}
void zadanie_23(){
    //Wyliczeniu sumy N liczb i ich średniej wczytywanych z klawiatury
    int N;
    printf("podaj  ilość \"N\" liczb: "); scanf("%d",&N);
    int suma=0;
    for(int i=1; i <= N; i++){
        int a;
        printf("Podaj %d liczbę: ", i); scanf("%d", &a);
        suma += a;
    }
    float srednia = suma;
    srednia /= N;
    printf("Suma = %d\nŚrednia = %.2f", suma, srednia);
}
void zadanie_24(){
    //Znaleźć największy element w tablicy liczb całkowitych
    int max = table_1[0];
    for (int i=1; i < sizeof(table_1)/4; i++){
        if(max < table_1[i]) max = table_1[i];
    }
    printf("max=%d\n", max);
}
void zadanie_25(){
    //tabliczka mnożenia
    for (int i=1; i <=10; i++){
        for (int j=1; j <= 10; j++){
            printf("[\t%d\t] ",i*j);
        }
        printf("\n");
    }
}
void zadanie_26() {
    //posortować tablicę liczb
    int posortowana[sizeof(table_1)/4];
    for (int i = 0; i < sizeof(table_1)/4; i++) {
        posortowana[i] = table_1[i];
        printf("[%d] ",posortowana[i]);
    }
    printf("\n\n||\n\\/\n\n");
    for(int i = 0; i < (sizeof(posortowana)/4)-1; i++) {
        for ( int j = i+1 ; j < sizeof(posortowana) / 4; j++) {
            if(posortowana[i] > posortowana[j]){
                int tmp = posortowana[j];
                posortowana[j] = posortowana[i];
                posortowana[i] = tmp;
            }
        }
    }
    for (int i = 0; i < sizeof(posortowana)/4; i++) {
        printf("[%d] ",posortowana[i]);
    }
    printf("\n");
}
void zadanie_27(){
    //liczba małych liter w tekście
    char str[100];
    fgets(str, sizeof(str), stdin);
    int count;
    for(int i=0; i < sizeof(str); i++){
        if(97 <= str[i] && str[i] <= 122) count++;
        //if();                          >>>(char)i<<< // pokazuje numer litery w ANSII
    }
    printf("Liczba malych liter w tekscie: %d", count);
}
void zadanie_28(){
    //liczba liczb w tekście
    char str[100];
    fgets(str, sizeof(str), stdin);
    int count;
    for(int i=0; i < sizeof(str); i++){
        if(48 <= str[i] && str[i] <= 57) count++;
    }
    printf("Liczba liczb w tekscie: %d", count);
}
void zadanie_29(){
    //liczba samogłosek w tekście
    char str[100];
    fgets(str, sizeof(str), stdin);
    int count;
    for(int i=0; i < sizeof(str); i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') count++;
    }
    printf("Liczba samogłosek w tekscie: %d", count);
}
void zadanie_30(){
    //Napisz program, ktory bedzie czytal liczby dodatnie z klawiatury i kolejno je sumował.
    //Jedyny sposób na przerwanie nieskonczonej pętli ma byc wpisanie liczby 0.
    // Na koniec program ma wyswietlic sume wszystkich wprowadzonych liczb
    int suma=0;
    while(1){
        int a;
        printf("liczba: "); scanf("%d",&a);
        if(a == 0) break;
        else if(a > 0) suma += a;
    }
    printf("SUMA: %d\n", suma);
}
void zadanie_31(){
    //dodanie dwóch liczb zespolonych i wyświetlenie
    int Re_z1, Im_z1, Re_z2, Im_z2;
    printf("Dodanie liczb z1 + z2\n");
    printf("Re(z1)="); scanf("%d",&Re_z1);
    printf("Im(z1)="); scanf("%d",&Im_z1);
    printf("Re(z2)="); scanf("%d",&Re_z2);
    printf("Im(z2)="); scanf("%d",&Im_z2);
    printf("Z=%d+%di\n",Re_z1+Re_z2,Im_z1+Im_z2);
}
int main(){
    //zadanie_1();
    //zadanie_2();
    //zadanie_3();
    //zadanie_4();
    //zadanie_6();
    //zadanie_7(); // nie działa
    //zadanie_11();
    //zadanie_12();
    //zadanie_13();
    //zadanie_14();
    //zadanie_15();
    //zadanie_16();
    //zadanie_17();
    //zadanie_18(); //poprawic
    //zadanie_19();
    //zadanie_21();
    //zadanie_22();
    //zadanie_23();
    //zadanie_24();
    //zadanie_25();
    //zadanie_26(); //sortowanie
    //zadanie_27(); //czasem pokazuje o jednen więcej
    //zadanie_28(); // -||-
    //zadanie_29();
    //zadanie_30();
    //zadanie_31();
