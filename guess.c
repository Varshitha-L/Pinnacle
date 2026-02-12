#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(0));
    int num=rand()%100+1, guess;
    do {
        printf("Guess (1-100): ");
        scanf("%d",&guess);
        if(guess<num) printf("Too low!\n");
        else if(guess>num) printf("Too high!\n");
        else printf("Correct!\n");
    } 
        while(guess!=num);
}
