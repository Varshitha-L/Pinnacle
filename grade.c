#include <stdio.h>
int main() {
    int n; printf("Enter number of subjects: "); scanf("%d",&n);
    float marks[n], sum=0;
    for(int i=0;i<n;i++){ printf("Enter mark %d: ",i+1);
                         scanf("%f",&marks[i]); sum+=marks[i]; }
    printf("Average = %.2f\n", sum/n);
}
