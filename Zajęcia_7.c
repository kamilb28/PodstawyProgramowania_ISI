#include <stdio.h>
#include <stdlib.h>

int **make2Darray(int i,int j){
    int **array = malloc(i * sizeof(*array));
    for (int a=0; a < i; a++){
        array[a] = malloc(j*sizeof(**array));
    }
    return array;
}
void FREE(int **array,int i) {
    for(int a=0; a < i; a++) {
        free(array[i]);
    }
    free(array);
}
void FREE_char(char **array,int i) {
    for(int a=0; a < i; a++) {
        free(array[i]);
    }
    free(array);
}
void zadanie_1_2(){
    //Proszę napisanie funkcji, zwracającej tablicę dynamiczną dwu-wymiarową dla zadanych wartości i, j
    //Proszę o napisanie funkcji, która zwalnia pamięć po tablicy dwu-wymiarowej
    int i=2,j=2;
    int **tablica = make2Darray(i,j);
    FREE(tablica,i);
}
int **suma_macierzy2x2(int **a,int **b){

    int **array;
    array = malloc(2 * sizeof(*array));
    for(int i=0; i < 2; i++){
        array[i] = malloc(2* sizeof(**array));
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            array[i][j] = a[i][j] + b[i][j];
        }
    }
    return array;
}

void print_2x2_free(int **array){
    for(int i=0;i< 2;i++){
        for(int j=0;j< 2;j++){
            printf("%d ", *(*(array+i)+j));
        }
        printf("\n");
        free(array[i]);
    }
    free(array);
}
void zadanie_3(){
    //Proszę o napisanie funkcji sumującej dwie macierze 2*2
    int **macierz_1 = make2Darray(2,2);
    int **macierz_2 = make2Darray(2,2);
    macierz_1[0][0]=1;
    macierz_1[0][1]=2;
    macierz_1[1][0]=3;
    macierz_1[1][1]=4;
    macierz_2[0][0]=8;
    macierz_2[0][1]=7;
    macierz_2[1][0]=6;
    macierz_2[1][1]=5;
    int **wynik = suma_macierzy2x2(macierz_1,macierz_2);
    print_2x2_free(wynik);
}
void wyznacznik_2x2(int m[2][2]){
    printf("%d\n",(m[0][0]*m[1][1]) - (m[0][1]*m[1][0]));
}
void zadanie_4(){
    //Napisz funkcję liczącą wyznacznik macierzy 2*2
    int macierz[2][2]={{1,2},{3,4}};
    wyznacznik_2x2(macierz);
}
void zadanie_5(){
    // Proszę o napisanie funkcji odejmującej jedną macierz od drugiej, macierze mają wymiar 2*2
    //analogicznie co zadanie3 tylko w funkcji dajemy -
}
int words_count(char string[],int size){
    int count = 0;
    for(int i=0; i<size; i++){
        if(string[i] == ' ') count++;
        if(string[i] == ' ' && string[i+1] == ' ') count --;
        if(string[0] == ' ') count --;
    }
    return count;
}
void print2Darray(char **arr,int i, int j){
    for(int a=0;a<i;a++)
        for(int b=0;b<j;b++)
            printf("%c",**(arr+i));
    printf("\n");
}
void zadanie_6(){
    // Proszę o napisanie funkcji split, która przyjmie tekst i zwróci poszczególne słowa (tablica tablic),
    // za ostatnim słowem powinien być wskaźnik do NULL: 3p
    char string[100];
    fgets(string,100,stdin);
    int count = words_count(string,sizeof(string)/sizeof(string[0]));
    printf("%d",count);
    char **array;
    array = malloc((count+1) * sizeof(*array));
    for (int i=0; i< count+1; i++) {
        array[i] = malloc(20 * sizeof(**array));
    }
    int a=0;
    for(int j=0 ; j<count+1; j++) {
        for (int i = 0; i < sizeof(string) / sizeof(string[0]); i++) {
            if (j == count){ array[j] = NULL; break; }
            else if (string[i] != ' ')array[j][i] = string[a];
            else break;
            a++;
        }
    }
    print2Darray(array,count,20);
    FREE_char(array,count+1);
}
void zadanie_7(){
    // Proszę o napisanie funkcji, która połączy tablicę słów w jeden tekst i zwróci
    char tab[4][20]={{"kamil"},{"bernacik"},{"natalia"},{"slusarczyk"}};
    char *array = malloc(4*20*sizeof(*array));
    int a=0;
    for(int i=0; i<4;i++){
        for(int j=0; j< 20; j++){
            if(tab[i][j] == '\0'){   //jeżeli koniec słowa jest to dajemy ' ' i następne słowo
                array[a] = ' ';
                a++;
                break;
            }
            array[a] = tab[i][j];
            a++;
        }
    }
    for(int i=0; i < 4*20*sizeof(*array); i++){
        printf("%c",*(array+i));
    }

    free(array);
}
int main(){
//---- Dynamiczna allokacja
    //zadanie_1_2();
    //zadanie_3();
    //zadanie_4();
    ///zadanie_5();
    ///zadanie_6(); ///ni dziala
    //zadanie_7();
    ///zadanie_8();

    return 0;
}

