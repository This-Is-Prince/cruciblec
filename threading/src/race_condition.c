#include "race_condition.h"
#include <stdio.h>
#include <pthread.h>

long long shared_counter = 0;

void* incrementor(void *arg) {
    for (int i = 0; i < 1000000; i++) {
        shared_counter++;
    }
    return NULL;
}

void RaceCondition(bool run) {
    if (!run) {
        return;
    }

    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, incrementor, NULL);
    pthread_create(&thread2, NULL, incrementor, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Expected result: 2000000\n");
    printf("Actual   result: %lld\n", shared_counter);

}