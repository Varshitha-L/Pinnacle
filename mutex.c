#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define MAX 5
int buffer[MAX], count = 0;
pthread_mutex_t lock;
pthread_cond_t not_full, not_empty;

void* producer(void* arg) {
    int item = 1;
    while (1) {
        pthread_mutex_lock(&lock);

        while (count == MAX)
            pthread_cond_wait(&not_full, &lock);

        buffer[count++] = item;
        printf("Produced: %d | Count = %d\n", item, count);
        item++;

        pthread_cond_signal(&not_empty);
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
}

void* consumer(void* arg) {
    while (1) {
        pthread_mutex_lock(&lock);

        while (count == 0)
            pthread_cond_wait(&not_empty, &lock);

        int item = buffer[--count];
        printf("Consumed: %d | Count = %d\n", item, count);

        pthread_cond_signal(&not_full);
        pthread_mutex_unlock(&lock);
        sleep(2);
    }
}

int main() {
    pthread_t p, c;

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&not_full, NULL);
    pthread_cond_init(&not_empty, NULL);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    return 0;
}
