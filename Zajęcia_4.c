#include <stdio.h>
#include <stdbool.h>

int table_1[10]={5,7,3,4,9,7,0,1,12,3};
int table_2[10]={8,4,1,9,20,4,8,3,5,6};

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
void zadanie_10(){
// Użycie (wczytanie, podwojenie) typów przenośnych z <stdint.h>
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
int main(){
    //zadanie_1();
    //zadanie_2();
    //zadanie_3();
    //zadanie_4();
    //zadanie_6();
    //zadanie_7(); // nie działa
    //   zadanie_10();
    //zadanie_11();
    //zadanie_12();
    //zadanie_13();
}

