#include "mutex_lock.h"
#include <stdio.h>
#include <pthread.h>

long long shared_money = 0;

pthread_mutex_t money_mutex;

void* add_money(void *arg) {
    for (int i = 0; i < 1000000; i++) {
        pthread_mutex_lock(&money_mutex);

        shared_money++;

        pthread_mutex_unlock(&money_mutex);
    }
    return NULL;
}

void MutexLock(bool run) {
    if (!run) {
        return;
    }

    pthread_t thread1;
    pthread_t thread2;

    pthread_mutex_init(&money_mutex, NULL);

    pthread_create(&thread1, NULL, add_money, NULL);
    pthread_create(&thread2, NULL, add_money, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&money_mutex);

    printf("Final money: %lld\n", shared_money);
}