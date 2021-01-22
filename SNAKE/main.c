#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // dla usleep()
//#include <ncurses.h>  // dla getch()
#include <termios.h>  //dla kbhit()
#include <fcntl.h>     // kbhit()
#include <stdbool.h> // dla bool
#include <time.h>    // dla rand() i srand()
int kbhit();

const int width =40, height =10;  ///rozmiary planszy
int SCORE=0;              /// wynik gracza

bool gameover;

struct snake{ int x; int y; }; // położenie na planszy
struct snake head;   ///polozenie glowy weza
struct snake fruit;   ///polozenie owocu
struct snake tail[100];  /// ogon weża
int n_tail =0;  /// długość ogona węża

enum Direction {LEFT =1, RIGHT =2, UP =3, DOWN =4};
enum Direction dir;

void print_rules();
void game_start(){
    gameover = false;
    dir = RIGHT;  //domyślnie idziemy w prawo
    head.x = 5;    // domyślna pozycja startowa weza
    head.y = 5;
    fruit.x = (rand() % width) +1;    // losowe miejsce owocu
    fruit.y = (rand() % height) +1;
    print_rules();
}

void print_game_over();
void game_end(){
    print_game_over();
    printf("TWÓJ WYNIK TO: %d pkt.\n", SCORE);

}

void plansza(){
    for(int i=0; i< height+2; i++){ // dodajemy dwa bo to miejsce na nasze granice planszy
        for(int j=0; j< width+2; j++){
            if( i == 0 || i == height +1) printf("#");
            else if( j == 0 || j == width +1) printf("#");
            else if(j == head.x && i == head.y) printf("@");
            else if(j == fruit.x && i == fruit.y) printf("o");
            else {
                printf(" ");
                for (int l = 0; l < n_tail; l++) {
                    if (tail[l].x == j && tail[l].y == i) printf("\b$");
                }
            }
        }
        printf("\n");
    }
}
void game(){
    int tail1_x = tail[0].x;
    int tail1_y = tail[0].y;
    int tail2_x, tail2_y;

    tail[0].x = head.x;
    tail[0].y = head.y;

    for(int i=1; i<n_tail;i++){   //powiekszenie ogona
        tail2_x = tail[i].x;
        tail2_y = tail[i].y;

        tail[i].x = tail1_x;
        tail[i].y = tail1_y;

        tail1_x = tail2_x;
        tail1_y = tail2_y;
    }

    if(dir == LEFT) head.x--;     // zmiana kierunku
    else if(dir == RIGHT) head.x++;
    else if(dir == UP) head.y--;
    else if(dir == DOWN) head.y++;

    if(head.x == 0 || head.x == width+1) gameover = true;   // przegrana bo sciana
    if(head.y == 0 || head.y == height+1) gameover = true;

    if(head.x == fruit.x && head.y == fruit.y){   // zjedzenie owocu
        fruit.x = (rand() % width)+1;
        fruit.y = (rand() % height)+1;
        SCORE += 10;
        n_tail++;
    }

    for (int i = 0; i < n_tail; i++)
        if (tail[i].x == head.x && tail[i].y == head.y) { printf("ogon\n"); gameover = true; } //przegrana bo zjedzenie ogonad

}
void input(){
    system("stty raw");
    if (kbhit()) {
        int c = getchar();

        switch (c) {
            case 97:
                dir = LEFT;  // 97 ='a'
                break;

            case 100:
                dir = RIGHT;  // 100 ='d'
                break;

            case 119:
                dir = UP;   // 119 ='w'
                break;

            case 115:
                dir = DOWN;   // 115 ='s'
                break;

            case 113:
                gameover = true;    //113 ='q'
                break;
        }
    }
    system("stty cooked");
}

int main(){
    srand(time(0));
    //system ("/bin/stty raw");

    game_start();

    while(!gameover){
        plansza();   // rysuj plansze
        printf("%d pkt.\n", SCORE);
        input();   // wpisanie gracza

        game();     // bebechy gry

        if(dir == UP || dir == DOWN){ //predkosc weza
        usleep(200000);}   //300000 microsekund == 300 milisekund == 0,3 sekundy
        else usleep(100000);

        system("clear");
    }

    game_end();
    printf("\n\n\n");

    return 0;
}


void print_rules(){
    printf("\t**************************************\n"
           "\t ####   #    #    ##    #    #  ######\n"
           "\t#       ##   #   #  #   #   #   #     \n"
           "\t ####   # #  #  #    #  ####    ##### \n"
           "\t     #  #  # #  ######  #  #    #     \n"
           "\t#    #  #   ##  #    #  #   #   #     \n"
           "\t ####   #    #  #    #  #    #  ######\n"
           "\t**************************************\n\n"
           "Zasady:\n\n"
           "a) poruszanie\n"
           "*\"w\" w gore\n"
           "*\"s\" w dol\n"
           "*\"d\" w lewo\n"
           "*\"a\" w prawo\n\n"
           "b) budowa weza\n"
           "   @$$$$$$   \n"
           "   ^    ^\n"
           "glowa   ogon\n\n"
           "c) koniec gry\n"
           "sa 3 przypadki:\n"
           "1. wcisniecie \"q\"\n"
           "2. zjedzenie ogona\n"
           "3. udezenie w sciane\n\n"
           "d) zdobywanie punktow\n"
           "za kazdy zjedzony owoc (wyglad: o )\n"
           "otrzymujesz 10pkt\n\n");

    printf("jestes gotowy do gry? (nacisnij dowolny klawisz:)\n");
    system("stty raw");
    getchar();
    system("stty cooked");
    system("clear");
}
void print_game_over(){
    printf("\t****************************************************************\n"
           "\t #####     #    #     #  ####### ####### #     # ####### ###### \n"
           "\t#     #   # #   ##   ##  #       #     # #     # #       #     #\n"
           "\t#        #   #  # # # #  #       #     # #     # #       #     #\n"
           "\t#  #### #     # #  #  #  #####   #     # #     # #####   ###### \n"
           "\t#     # ####### #     #  #       #     #  #   #  #       #   #  \n"
           "\t#     # #     # #     #  #       #     #   # #   #       #    # \n"
           "\t #####  #     # #     #  ####### #######    #    ####### #     #\n"
           "\t****************************************************************\n\n");
}


int kbhit(){
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}