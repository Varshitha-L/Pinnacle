#include <stdio.h>
int main() {
    double balance = 1000.0;
    int choice;
    double amt;
    printf("===== Simple Banking System =====\n");
    do {
        printf("\n------------------------------\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Current Balance: ₹%.2lf\n", balance);
                break;

            case 2:
                printf("Enter amount to deposit: ");
                scanf("%lf", &amt);

                if (amt > 0) {
                    balance += amt;
                    printf("Deposited ₹%.2lf successfully.\n", amt);
                } else {
                    printf("Invalid amount! Deposit must be positive.\n");
                }
                break;

            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%lf", &amt);

                if (amt <= 0) {
                    printf("Invalid amount! Withdrawal must be positive.\n");
                } 
                else if (amt > balance) {
                    printf("Insufficient balance!\n");
                } 
                else {
                    balance -= amt;
                    printf("Withdrawn ₹%.2lf successfully.\n", amt);
                }
                break;

            case 4:
                printf("Exiting... Thank you!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
