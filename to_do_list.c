#include <stdio.h>
#include <string.h>
struct Task { char name[50]; int done; };
int main() {
    struct Task tasks[10];
    int count=0, choice;
    do {
        printf("1.Add 2.Mark Done 3.List 4.Exit\n");
        scanf("%d",&choice);
        if(choice==1) {
            printf("Enter task: ");
            scanf(" %[^\n]", tasks[count].name);
            tasks[count].done=0; count++;
        } else if(choice==2) {
            int i; printf("Enter task number: "); scanf("%d",&i);
            tasks[i-1].done=1;
        } else if(choice==3) {
            for(int i=0;i<count;i++)
                printf("%d. %s [%s]\n", i+1, tasks[i].name, tasks[i].done?"Done":"Pending");
        }
    } while(choice!=4);
}