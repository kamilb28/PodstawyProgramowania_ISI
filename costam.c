#include<stdio.h>
#include<stdlib.h>

int main(){
    const char cytat[] = "To, że milczę, nie znaczy, że nie mam nic do powiedzenia.";
    FILE *plik;
    if ((plik = fopen("cytat.txt", "w")) == NULL){
        printf("nie mozna otworzyć\n");
        exit(1);
    }
    fprintf(plik, "%s", cytat);
    fclose(plik)

    return 0;
}
