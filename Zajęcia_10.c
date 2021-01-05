/*
pierwsze zadanie
#include <stdio.h>

int isEnabled(long long num, int bit)
{
    int a =1;
    for(; bit > 1; --bit){
        1 *= 2;
    }

    if (num & a){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){

    long long number = 0;

    if(isEnabled(number, 4)){
        printf("%s\n", "Jest");
    }

    return 0;
}

 pierwsze zadanie (2)

#include <stdio.h>
#include <stdbool.h>

bool isEnabled(long long liczba, unsigned bit)
{
    if (liczba & (1 << (bit - 1)))
        return true;
    else
        return false;
}

int main(){

    bool check = isEnabled(7654323,2);
    printf("%d",check);

    return 0;
}

 drugie zadanie






 trzecie zadanie

#include <stdio.h>
#include <time.h>

int miesiąc(){
    time_t t;
    time(&t);
    struct tm *myTime = localtime(&t);

    return (myTime -> tm_mon+1);
}

int main(){

   printf("%i",miesiąc());

    return 0;
}

 zadanie 3

 #include <stdio.h>
#include <time.h>

int dodaj(int a,int b){
    return (a+b);
}


void funkcja(){

    clock_t start_clock = clock();

    for(int i=0; i<1000; i++){
        int a = dodaj(i,i);
    }

    printf("czas działania funkcji to: %lu ms", clock() - start_clock);
}

int main(void){

    funkcja();

    return 0;
}

