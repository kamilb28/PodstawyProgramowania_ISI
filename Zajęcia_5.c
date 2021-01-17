#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include <string.h>

void zadanie_1(){
    srand(time(0));
    char obiecanki[4][20]={"piwa piwa","czegos tam","kasy","spanka spanka"};
    printf("%s\n", obiecanki[(rand()%4)]);
}
void zadanie_2_3(){
    //Wyświetlić argumenty uruchomienia programu
    // W razie argumentów poniżej 1 proszę o komunikat o błędzie i awaryjne wyjście z programu (funkcja abort)
}
void zadanie_4(){
    //Napisać funkcje wczytującą z klawiatury jedną liczbę i zwracającą jej sześcian
    int a; scanf("%d",&a); printf("%d", a*a*a);
}

void funkcja(char *tab, int a){
    srand(time(a));
    char tekst[4][20]={"tekst1","tekst2","tekst3","tekst4"};
    int los = rand()%4;
    printf("[%s]%s\n", tab, tekst[los]); // tab bez * bo potrzebujemy adres a nie wratosć pod nią zapisaną
}
void zadanie_5(){
/* Napisać funkcję przyjmującą dwa argumenty i wyświetlającą dany tekst poprzedzony
słowem podanym jako pierwszy argument (słowo to może być "ERROR" lub "WARNING" lub "DEBUG"), przykładowy tekst:
"[ERROR]Brak uprawnień do zorganizowania wesela z powodu pandemii!" */
    char string[100];
    int i;
    printf("string: "); scanf("%s",&string);
    printf("liczba: "); scanf("%d",&i);
    funkcja( string,i );
}
int licznik_6 = 0;
void zadanie_6(){
    //Proszę o napisanie funkcji, która wyświetla tekst,
    //jednakże każde jej wywołanie jest poprzedzone numerem komunikatu, który rośnie
    printf("tekst\n");
    licznik_6 ++;
    printf("funkcja wywołana %d raz\n", licznik_6);
}
int silnia(int a){
    if (a == 1) return 1;
    return a * silnia(a-1);
}
void zadanie_7(){
    //Napisz funkcje liczącą silnię
    int a;
    printf("Wprowadź liczbę: "); scanf("%d",&a);
    printf("%d! = %d",a,silnia(a));
}
int podwoj(int p) { return 2*p;}
void zadanie_8(){
    int a=5;
    printf("%d = 2*%d", podwoj(a), a);
}
void clear_arr(int *array, int size){
    for(int i=0; i < size ; i++){
        *(array+i) = 0;
    }
}
void print_arr(int *array, int size){
    for(int i=0; i < size ; i++){
        printf("%d ", *(array+i));
    }
    printf("\n");
}
int arr_sum(int *array, int size){
    int suma=0;
    for(int i=0; i < size; i++){
        suma += array[i];
    }
    return suma;
}
void zadania_10_11() {
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("suma elementów: %d\n", arr_sum(arr, sizeof(arr) / 4));
    clear_arr(arr, sizeof(arr) / 4);
    print_arr(arr, sizeof(arr) / 4);
}
int fibb(int l){
    if(l < 1) return 0;
    else if(l == 1 || l == 2) return 1;
    int c,a=1,b=1;
    for (int i = 3; i <= l; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
void zadanie_12(){
    //Napisz funkcje liczącą ciąg Fibbonacciego
    int l;
    printf("Który element ciągu fibbonacciego wyświetlić??: "); scanf("%d", &l);
    printf("%d",fibb(l));
}
void cpy_arr(int *Z,int *DO,int a){
    for(int i=0; i<a; i++){
        DO[a-1-i] = Z[i];
    }
}
float average(int *array){
    float sum=0;
    for(int i = 0; i < 10; i++){
        sum += *(array+i);
    }
    return sum/10;
}
void zadanie_13_14() {
    //13: Funkcję, która skopiuje liczby z jednej tablicy do drugiej
    // ale w odwrotnej kolejności (rozmiar obydwu identyczny)
    //14: Funkcje average, która zwróci średnią liczb w tablicy
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr_2[10];
    print_arr(arr, sizeof(arr) / 4);
    cpy_arr(arr, arr_2, sizeof(arr) / 4);
    print_arr(arr_2, sizeof(arr_2) / 4);
    printf("Srednia 1tab= %.1f 2tab= %.1f\n", average(arr), average(arr_2));
}
void dable_array(int *array,int lenght){
    int arr[lenght];
    for(int i=0; i< lenght; i++){
        int a = *(array+i);
        arr[i] = 2*a;
    }
    print_arr(arr,lenght);
}
void zadanie_15(){
    //Napisz funkcje, która podwoi wartości tablicy, po wywołaniu funkcji wyświetl oryginalną tablicę
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int lenght = sizeof(arr)/4;
    dable_array(arr, lenght);
    //printf("%d\n",*(arr2+9));
    //print_arr(arr2,lenght);
    print_arr(arr,lenght);
}
void print(int a, int b){
    printf("%d i %d", a, b);
}
void zadanie_16(){
    // Proszę o przyjęcie funkcji, która przyjmie dwie liczby które wyświetli,
    // proszę wywołać ją print(++i, ++i) i przyjrzeć się kolejności wykonania działań
    int a=5,b=6;
    print(++a,++b);
}
int kalkulator(char op, int b){
    static int a = 6;
    switch (op){
        case '/': return b/a;
            break;
        case '*': return b*a;
            break;
        case '-': return b-a;
            break;
        case '+': return b+a;
            break;
        default: printf("Zły operator"); return 0;
    }
    return 0;
}
void zadanie_17(){
//Napisz funkcje kalkulator(operacja, liczba), która dla danej liczby będącej wewnątrz tej funkcji (static)
// wykona zadaną operacje z podaną w argumencie liczbą i zwróci wynik
    char operacja;
    int liczba;
    printf("Podaj operracje i liczbę: "); scanf("%c %d",&operacja, &liczba);
    printf("%d\n", kalkulator(operacja, liczba));
}
void zadanie_19_menu(){
//Funkcja menu, która w razie wpisania 0 wyjdzie z programu
    int opcja;
    printf("Wybierz OPCJE:\n"
           "a) program1 [wpisz 1]\n"
           "b) program2 [wpisz 2]\n"
           "c) program3 [wpisz 3]\n"
           "WYJSCIE [wpisz 0]\n"); scanf("%d", &opcja);
    switch (opcja){
        case 1: printf("tutaj program 1");
            break;
        case 2: printf("tutaj program 2");
            break;
        case 3: printf("tutaj program 3");
            break;
        case 0: exit(0);
            break;
        default: printf("Nie ma takiej opcji\n"); zadanie_19_menu();
    }
}
void zadanie_20(){
//Proszę o zdefiniowanie funkcji wyświetlającej liczbę całkowitą wycentrowaną
//na danej szerokości tekstu (pytanie jak można sprawdzić ilość cyfr w tekście)
// nie rozumiem chyba XD
}
void zadanie_21(){
//Napisz funkcje, która przeliczy wyrazy w napisie
// (uprośćmy, że są podzielone spacją, ale za coś eksta +0,5 p) i zwróci
    char napis[100];
    fgets(napis, sizeof(napis), stdin);
    int count=0;
    for( int i =0; i <= sizeof(napis); i++){
        if(napis[0] == '/0') break;
        else if(napis[0] == ' ') continue;

        if(napis[i]==' ') count++;
        else if(napis[i]=='/0'){
            count++;
            break;
        }
    }
    printf("ilość wyrazów to: %d", count);
}
void zadanie_22() {
//Funkcję, która skopiuje tekst z jednej tablicy do drugiej ale w odwrotnej kolejności (rozmiary mogą się różnić)
    char string[]="Tutaj jest jakis tekst";
    int a = sizeof(string);
    printf("%d\n",a);
    char *odw = (char*) malloc(a*sizeof(char));
    for(int i=0; i<a;i++){
        odw[i] = string[a-1-i];
    }
    printf("%s",odw[0]);
    free(odw);
}
double mediana(int size, int *tablica){
    if(size%2 == 0){
        double a = tablica[size/2 - 1];
        double b = tablica[size/2];
        return (a+b)/2;
    }
    else {
        double a = tablica[size/2];
        return a;
    }
}
void zadanie_23(){
//Funkcja median, która zwróci medianę liczb w tablicy
    int tab[]={1,4,6,8,3,5,8,2,6,8,3,6,4,91,0,9};
    printf("%.2lf",mediana(sizeof(tab)/4,tab));
}
int  sum (int count,...) {
    int sum=0;
    va_list ap;

    va_start(ap,count);
    while((count--) != 0){
        int a = va_arg(ap,int);
        sum += a;
    }
    va_end(ap);
    return sum;
}
void zadanie_24(){
//Napisz funkcję, która przyjmuje dowolną ilość argumentów (nie trzeba ich wyświetlać)
//xd
    printf("%d",sum(3,2,3,4)); //(ilość do dodania, rzecz do dadania, itd ...)
}
void zadanie_25(){
//Funkcję, która nie przyjmuje argumentów (może ona wyświetlić jakiś tekst,
// który chcemy wykrzyknąć do strajkującej młodzieży), proszę sprawdzić, że nie przyjmuje argumentów
    printf("KRZYK");
}
void zadanie_27(){
    //roszę o napisanie fragmentu tekstu ulubionego wykonania #hot16challange i wyszukać w nim słowo "hot",
    // następnie wyświetlić pozycje znalezienia i tekst od tego momentu do końca
    char tekst[]={"Hejo hejka elo elka siemo siemka hot 16 challenge bdfijbieufnie jo jo elo wiefi ewfew wfhd"};
    int i;
    for(i=0; i < sizeof(tekst); i++){
        if(tekst[i] == 'H' || tekst[i] == 'h')
            if(tekst[i+1] != '\0' && tekst[i+1] == 'o')
                if(tekst[i+2] != '\0' && tekst[i+2] == 't')
                    if(tekst[i+3] == '\0' && tekst[i+3] == ' '){
                        printf("\"hot\" zaczyna się od %d znaku\n",i);
                        break;
                    }
    }
    for(int j=i; j<sizeof(tekst);j++)
        printf("%c",tekst[j]);
}
void erese_a(char* str, int size){
    char str_tmp[size];
    for(int i=0; i<size;i++){
        if(str[i] == 'a') str_tmp[i]=' ';
        else str_tmp[i] = str[i];
    }
    strcpy (str,str_tmp);

}
void zadanie_28(){
    //Proszę o napisanie funkcji, która z zadanego tekstu usunie literę 'a', ale przez skorzystanie z tablicy pomocniczej,
    //do której zostanie ten tekst skopiowany bez tejże litery, następnie proszę użyć strcpy lub strncpy
    char tekst[100];
    fgets(tekst,sizeof(tekst),stdin);
    erese_a(tekst,sizeof(tekst));
    printf("%s",tekst);
}
void zadanie_29(){

}
int main(){
    //zadanie_1();
    //zadanie_2_3(); //brak
    //zadanie_4();
    //zadanie_5();
    /*   zadanie_6();
       zadanie_6();
       zadanie_6(); */
    //zadanie_7();
    //zadanie_8();
    //zadanie_9(); //??? fflush(stdin); ???
    //zadania_10_11();
    //zadanie_12();
    //zadanie_13_14();
    //zadanie_15();
    //zadanie_16();
    //zadanie_17();
    //zadanie_19_menu();
    //zadanie_21();
    //zadanie_22(); // jeszcze raz potem
    //zadanie_23();
    //zadanie_24();
    //zadanie_25();
    //zadanie_27();
    //zadanie_28();
    // reszta w osobnym pliku
}

