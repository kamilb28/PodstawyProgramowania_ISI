#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void zadanie_1(){
    //Funkcja, która kopiuje tablicę statyczną i zwraca
    /*taką funkcją jest strcp :? */
}
void print_arr(int *array,int size){
    for(int i=0; i< size; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}
void push_back(int *array,int size){
    array = realloc(array,(size+1)*sizeof(int));
    *(array+size) = 1;
}
void zadanie_2(){
    //Zdefiniować funkcję push_back, która do istniejącej tablicy dynamicznej doda element na koniec i zwróci tablicę o jeden większą:
    //    A: jak zrobić takie dodawanie elementów optymalniejszym?
    int rozmiar = 4;
    int *arr;
    arr = malloc(rozmiar * sizeof(*arr));
    for(int i=0; i<rozmiar;i++){
        *(arr+i) = 0;
    }
    print_arr(arr,rozmiar);
    push_back(arr,rozmiar);
    print_arr(arr,++rozmiar);
    free(arr);
}
void arr_zero(int *array,int size){
    for(int i=0; i < size; i++){
        array[i]=0;
    }
}
void zadanie_3(){
    //- Funkcja, która dla rozmiaru numeru zwróci wyzerowaną tablicę dynamiczną:
    //    A: jak wyzerować tablicę statyczną bez pętli
    int arr[]={13,4,2,5,745,54,23,45,123,};
    arr_zero(arr,sizeof(arr)/4);
}
int *nieparzysta(int size){
    int *array;
    array = malloc(sizeof(*array)*size);
    int a=1;
    for(int i=0; i<size; i++){
        array[i] = a;
        a +=2;
    }
    return array;
}
void zadanie_4(){
    //- Funkcja, która dla podanego numeru zwróci tablicę dynamiczną zawierającą kolejne liczby nieparzyste:
    //    A: jak się robi kolejne liczby nieparzyste:
    int size=10;
    int *tablica = nieparzysta(size);
    print_arr(tablica,size);
    free(tablica);
}
int *liczby(int size, char* str[2]){
    bool b;
    if (str == "dw") b = false;
    else b = true;

    int *array_tmp = malloc(size*sizeof(*array_tmp));
    for(int i=0; i < size; i++){
        if(b==1) array_tmp[i] = i+1;
        else array_tmp[i] = size-i;
        //printf("%d\n",array_tmp[i]);
    }
    return array_tmp;
}
void zadanie_5(){
    //- Funkcja, która dla podanego numeru zwróci tablicę dynamiczną zawierającą kolejne liczby z zakresu rosnącego:
    //  -- Jeśli będzie również obsługa zakresu malejącego (od większego do mniejszego
    int size=15;
    int *arr = liczby(size,"dw");
    print_arr(arr,size);
    free(arr);
}
int *doublee_array(int *array,int size){
    int *arr = malloc(2 * size * sizeof(*arr));
    for(int i=0; i< size ; i++){
        *(arr+i)=*(array+i);
        *(arr+size+i)=*(array+i);
    }
    return arr;
}
void zadanie_6(){
    //F. podwajająca tablicę i zwracająca podwojoną tablicę
    int array[]={2,4,6,7,4,5,8,9,2,3,1,19};
    //int *doubleearray;
    int a = sizeof(array)/4;
    int *doubleearray = doublee_array(array,a);
    print_arr(doubleearray,a*2);
}
char *two_times_a(char *array,int size){
    int *arr_tmp= malloc(2*size*sizeof(*arr_tmp));
    int d=0,i=0;
    for(; i < size;i++) {
        if (array[i] == 'a' || array[i] == 'e' || array[i] == 'i' || array[i] == 'o' || array[i] == 'u') {
            arr_tmp[d] = array[i];
            arr_tmp[d + 1] = array[i];
            d++;
        }
        else arr_tmp[d] = array[i];
        d++;
    }
    //for(int i=0; i < 12*2 ; i++) printf("%c",*(arr_tmp+i));
    return arr_tmp;
}
void zadanie_7(){
    //F. podwajająca samogłoski i zwracająca podwojoną tablicę
    char *tekst={"Lubie placki"};
    //printf("%d",12);
    char *tekst_2 = two_times_a(tekst, 12);
    for(int i=0; i < 4*24 ; i++) printf("%c",*(tekst_2+i));
    printf("\n");
}
void zadanie_8(){
    //!- Proszę o zdefiniowanie tablicy dynamicznej zbyt dużej i porównanie zachowania do tablic zmiennej długości: 2p i 1p
    //! A: co się stanie jak nie uda się dynamiczna alokacja pamięci

}
void zadanie_9(){
    //- Zdefiniować typ wyliczeniowy do dni tygodnia/miesięcy, oraz:
    //    1-- Zrobić funkcję konwertującą wartość enum na tekst
    //    A: jakie wartości mają poszczegulne wyliczenia w typie enum?
    enum Dni_tygodnia {pon,wt,śr,czw,pt,sb,ndz};

    enum Dni_tygodnia dzien_tygodnia = wt;
    dzien_tygodnia = ndz;
    switch (dzien_tygodnia){
        case pon: printf("Poniedziałek");
            break;
        case wt: printf("Wtorek");
            break;
        case śr: printf("środa");
            break;
        case czw: printf("Czwartek");
            break;
        case pt: printf("Piątek");
            break;
        case sb: printf("Sobota");
            break;
        case ndz: printf("Niedziela");
            break;
    }
}
void zadanie_10(){
    //2-- Zrobić funkcje konwertującą tekst na odpowiednią wartość enum
    //    A: co się stanie gdy przypiszemy w C inną wartość, niż ma enum
    //    A: jaki jest rozmiar typu enum?
}
void zadanie_11(){
    // -- Zrobić funkcje, która wyświetli wszystkie wartości enum (możemy korzystać tylko ze standardowego C):
    //    A: jak można sprawdzić ile jest takich wartości?
}
void zadanie_12(){
    //--* Zrób program, który wczytuje dzień i aktywność (tekst),
    // oraz potem można przeszukiwać swoje aktywności na dany dzień
}
void zadanie_13(){
    //- F. wyświetlającą wiadomość poprzedzoną informacją jakiej
    // rangi jest ta wiadomość ("[ERROR]", "[WARNING]", ...),
    // typ ma być podawany jako argument funkcji w postaci typu enum
}
void zadanie_14(){
    //2- Funkcja, która zmienia tekst na duże/małe litery
    //- Funkcja, która zmienia małe na duże i duże na małe litery:
}
void zadanie_15(){
    //2- F. zwracająca ilośc małych liter w tekście:
}
void zadanie_16(){
    //2- F. przycinająca tekst do określonej długości (w razie gdy tekst jest za krótki nic nie robiąca):
}
void zadanie_17(){
    //:D 1- Proszę o zaimplementowanie funkcji flegmatyk,
    // która tekst zwróci ze zwielokrotnionymi samogłoskami: 2p i 1,5p i 1p (jeśli losową ilość zwielokratniamy to +1 punkty)
}
void zadanie_18(){
    //3:D 1- Proszę o zaimplementowanie funkcji jakającej,
    //która tekst zwróci ze zwielokrotnionymi sylabami: 3p i 2,5p i 2p
    // (jeśli losową ilość zwielokratniamy to +1 punkty)
}
void zadanie_19(){
    //Funkcja, która imię i nazwisko połączy w jeden tekst (wyświetlamy dopiero podłączone)
}
int main(void){
    //---- Dynamiczna allokacja ----
    //zadanie_1();
    //zadanie_2();
    //zadanie_3();
    //zadanie_4();
    //zadanie_5();
    //zadanie_6();
    //zadanie_7();
    //zadanie_8(); nie ma
    //---- Enum ----
    //zadanie_9();
    zadanie_10();
    zadanie_11();
    zadanie_12();
    zadanie_13();
    zadanie_14();
    //--- operacje tekstowe ---
    zadanie_15();
    zadanie_16();
    zadanie_17();
    zadanie_18();
    zadanie_19();
    return 0;
}




//3- F. łącząca imię i liczbę w jeden tekst (wyświetlamy dopiero podłączone)
//2,3- Skopiowanie z tekstu zawierającego imię i nazwisko do dwóch oddzienych tablic (w jednej samo imię, w drugiej samo nazwisko)
//------ suffixy:
//A: co to za liczba: 10e6
//A: co to za liczba 12L
//A: co to za liczba 12LL
//A: co to za liczba 12LL
//! - proszę porównać: -1 < 0u i co wychodzi: printf("%d", -1 < 0u);
//A: jak się mają te liczby: 0xf i 15 i 017
//1,2 A: co to jest "martwa wołowina", ang. deadbeef
//---- struktury:
//1!- Zaimplementuj dwie strukruty  struct S1
//    {
//        bool b; //
//        double d; //
//        char c; //
//        int i; //
//    };
//    struct S2
//    {
//        double d; //
//        int i; //
//        bool b; //
//        char c; //
//    };
//    i porównaj rozmiary.
//    A: jak zainicjalizować strukturę

