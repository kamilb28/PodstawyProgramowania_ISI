#include <stdio.h>
#include <time.h>
#include <float.h>
#include <limits.h>

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

    //funkcja();
    //printf("\n%u", ~UINT_MAX);



    return 0;
}