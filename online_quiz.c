#include <stdio.h>
int main() {
    char ans;
    int score=0;
    printf("Q1: Capital of India? (a.Delhi b.Mumbai)\n");
    scanf(" %c",&ans);
    if(ans=='a') score++;
    printf("Q2: 2+2=? (a.3 b.4)\n");
    scanf(" %c",&ans);
    if(ans=='b') score++;
    printf("Score = %d\n",score);
}
