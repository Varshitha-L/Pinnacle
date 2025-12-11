#include <stdio.h>
int main() {
    double balance=1000; int choice; double amt;
    do {
        printf("1.Check 2.Deposit 3.Withdraw 4.Exit\n");
        scanf("%d",&choice);
        if(choice==1) printf("Balance=%.2lf\n",balance);
        else if(choice==2){ printf("Amount: "); scanf("%lf",&amt); balance+=amt; }
        else if(choice==3){ printf("Amount: "); scanf("%lf",&amt); if(amt<=balance) balance-=amt; else printf("Insufficient!\n"); }
    } while(choice!=4);
}
