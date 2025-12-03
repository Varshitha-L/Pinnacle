#include <stdio.h>
#include <time.h>
#include <unistd.h>
int main() {
    int alarmH, alarmM;
    printf("Set alarm (HH MM): ");
    scanf("%d %d",&alarmH,&alarmM);
    while(1) {
        time_t t=time(NULL);
        struct tm *tm=localtime(&t);
        printf("\r%02d:%02d:%02d", tm->tm_hour, tm->tm_min, tm->tm_sec);
        fflush(stdout);
        if(tm->tm_hour==alarmH && tm->tm_min==alarmM) {
            printf("\nAlarm ringing!\n"); break;
        }
        sleep(1);
    }
}