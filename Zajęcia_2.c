#include <stdio.h>
#include <limits.h>

int global;
void zadanie_6(){
    int lokal;
    printf("%d i %d", lokal, global);
}
void zadanie_18a() {
    int a;
    //<><><><><><><><><><><><>//
    printf("Wpisz liczbę całkowitą: ");
    scanf("%i", &a);
    a = a / 100;
    a = a * 100;
    printf("%i\n", a);
    //<><><><><><><><><><><><>//
}
void zadanie_18b(){
    double b;
    printf("Wpisz liczbę zmiennąprzecinkową: ");
    scanf("%lf", &b); //1234,56
    int temp1,temp2; //temp
    temp1 = b; //temp1 = 1234
    b = b - temp1; //b = 0,56
    temp1 = temp1/100;
    temp1 = temp1*100; //temp1 = 1200
    b = b*10; //5,6
    temp2 = b; //temp2 = 5
    b = b-temp2; // b = 0,6
    b = b/10; // b = 0,06
    b = b + temp1; // b = 1200 + 0,06 = 1200,06
    printf("%.2lf\n", b);
}
void zadanie_14()
{
    static int a;
    printf("%d\n", a);
    a = 10;
    printf("%d\n", ++a);
    printf("%d\n", a++);
}
int modulo(int a){ //do zadanie_2
    if(a >= 0) return a;
    else return -a;
}
void zadanie_2(){
    int a;
    printf("Wprodaź liczbę: ");
    scanf("%d", &a);
    printf("Kwadrat liczby: %d\nSześcian liczby: %d\nModulo: %d", a*a, a*a*a, modulo(a));
}
void zadanie_26(){
    printf("INT: %d ", INT_MAX);
    printf("Long: %ld ", LONG_MAX);
    printf("Long long: %lld ", LLONG_MAX);
    printf("char: %d ", CHAR_MAX);
}
void zadanie_5(){
    int liczba;
    printf("Wpisz liczbę nieparzystą: ");
    scanf("%d", &liczba);
    if((liczba % 2) == 0){
        zadanie_5();
    }
    else{
        double tmp = liczba;
        printf("%f", tmp/2);
    }
}
void zadanie_12(){
    int a,b;
    printf("Wpisz dwie liczby(np. 2,1): ");
    scanf("%d,%d", &a, &b);
    printf("Reszta z dzielenia pierwszej o drugą to: %d", a % b);
}
void zadanie_16(){
    double a;
    int tmp;
    scanf("%lf",&a);
    a *= 1000;
    tmp = a;
    a = tmp;
    a /= 1000;
    printf("%lf", a);
}
void zadanie_18(){
    double a;
    int tmp;
    printf("liczba zmienno przecinkowa: ");
    scanf("%lf",&a);
    tmp = a;
    if((tmp % 100) >= 50 ){
        a = (tmp / 100) * 100 +1;
    }
    else a = (tmp / 100) * 100;
    printf("%.lf", a);
}
void zadanie_3(){
    int a;
    scanf("%d",&a);
    printf("---------\n|\t%d\t|\n---------",a);
}
void zadanie_15(){
    double a;
    int tmp;
    scanf("%lf",&a);
    tmp = a;
    a = tmp;
    printf ("%lf", a);
}
void zadanie_15b(){
    double a;
    int tmp;
    scanf("%lf",&a);
    printf ("%.lf", a);
}
void zadanie_HELLOWORLD(){
    printf("Witam wszystkich\n");

    return 0;
}
void zadanie_1(){
    int x;

    scanf("%d", &x);
    printf("%d\n", x);
    printf("%d\n", ++x);
    printf("%d\n", x);
    printf("%d\n", x++);
    printf("%d\n", x);
    return 0;
}
void zadanie2(){
    unsigned int i=0;
    printf("%u\n", i-1);

    return 0;
}
void zadanie3(){
    printf("%d\n", i);

    int i = 1;

    printf("%d\n", i);
    {
        int i = 2;
        printf ("%d\n",i);
    }
    printf("%d\n", i);
    return 0;
}
void zadanie4(){
    int h,m,s;
    printf("Godzina (HH:MM:SS): ");
    scanf("%d:%d:%d", &h, &m, &s);

    s += m*60 + h*3600;
    printf("to: %d sekund", s);
    return 0;
}
void zadanie5(){
    float liczba_zmiennoprzecinkowa;
    int liczba_całkowita;
    scanf("%f", &liczba_zmiennoprzecinkowa);
    liczba_całkowita = liczba_zmiennoprzecinkowa;
    printf("%f", liczba_zmiennoprzecinkowa-liczba_całkowita);
    return 0;
}
void zadanie6(){
char imie[50];
char nazwisko[50];

scanf("%s", &imie);
scanf("%s", &nazwisko);

printf("Nazwisko: %s\nImie: %s\n", nazwisko, imie);

return 0;
}
void zadanie23(){
    printf("int size: %d\n",sizeof(int));
    printf("double size: %d\n",sizeof(double));
    printf("long size: %d\n",sizeof(long));
    printf("char size: %d\n",sizeof(char));
    printf("float size: %d\n",sizeof(float));
    printf("short size: %d\n",sizeof(short));
}
void zadanie25(){
    int h,m,s;
    printf("Godzina(HH:MM:SS): ");
    scanf("%d:%d:%d",&h,&m,&s);
    printf("ma %d sekund", h*3600+m*60+s);

}
void zadanie24(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    printf("Delta: %d\n", b*b-4*a*c );
    return 0;
}
int main(){
    zadanie_6();
    zadanie_18a();
    zadanie_18b();
    zadanie_14();
    zadanie_2();
    zadanie_26();
    zadanie_5();
    zadanie_12();
    zadanie_16();
    zadanie_18();
    zadanie_3();
    zadanie_15();
    zadanie_15b();
    zadanie_HELLOWORLD();
    zadanie_1();
    zadanie2();
    zadanie3();
    zadanie4();
    zadanie5();
    zadanie6();
    zadanie23();
    zadanie25();
    zadanie24();
    return 0;

