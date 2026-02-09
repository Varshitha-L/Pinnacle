#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX 5
#define NUM_PRODUCERS 2
#define NUM_CONSUMERS 2

int buffer[MAX];
int in = 0, out = 0, count = 0;

pthread_mutex_t lock;
pthread_cond_t not_full, not_empty;

void* producer(void* arg) {
    int id = *(int*)arg;
    int item = 1;

    while (1) {
        pthread_mutex_lock(&lock);

        while (count == MAX)
            pthread_cond_wait(&not_full, &lock);

        buffer[in] = item;
        printf("Producer %d → Produced %d at index %d | Count = %d\n",
               id, item, in, count + 1);

        in = (in + 1) % MAX;
        count++;
        item++;

        pthread_cond_signal(&not_empty);
        pthread_mutex_unlock(&lock);

        usleep((rand() % 500 + 200) * 1000);
    }
}

void* consumer(void* arg) {
    int id = *(int*)arg;

    while (1) {
        pthread_mutex_lock(&lock);

        while (count == 0)
            pthread_cond_wait(&not_empty, &lock);

        int item = buffer[out];
        printf("Consumer %d → Consumed %d from index %d | Count = %d\n",
               id, item, out, count - 1);

        out = (out + 1) % MAX;
        count--;

        pthread_cond_signal(&not_full);
        pthread_mutex_unlock(&lock);

        usleep((rand() % 700 + 300) * 1000);
    }
}

int main() {
    srand(time(NULL));

    pthread_t prod[NUM_PRODUCERS], cons[NUM_CONSUMERS];
    int prod_id[NUM_PRODUCERS], cons_id[NUM_CONSUMERS];

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&not_full, NULL);
    pthread_cond_init(&not_empty, NULL);

    for (int i = 0; i < NUM_PRODUCERS; i++) {
        prod_id[i] = i + 1;
        pthread_create(&prod[i], NULL, producer, &prod_id[i]);
    }

    for (int i = 0; i < NUM_CONSUMERS; i++) {
        cons_id[i] = i + 1;
        pthread_create(&cons[i], NULL, consumer, &cons_id[i]);
    }

    for (int i = 0; i < NUM_PRODUCERS; i++)
        pthread_join(prod[i], NULL);

    for (int i = 0; i < NUM_CONSUMERS; i++)
        pthread_join(cons[i], NULL);

    return 0;
}
