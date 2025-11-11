#include "thread_rw_lock.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_rwlock_t config_lock;

char shared_config[100] = "Default Config";
int config_version = 1;


void* reader_thread(void* arg) {
    int thread_id = *(int*)arg;

    for (int i = 0; i < 5; i++) {
        pthread_rwlock_rdlock(&config_lock);

        printf("Reader %d: Reading config (Version %d): '%s'\n", thread_id, config_version, shared_config);

        pthread_rwlock_unlock(&config_lock);

        sleep(1);
    }

    return NULL;
}

void* writer_thread(void* arg) {
    int thread_id = *(int*)arg;

    for (int i = 0; i < 2; i++) {
        sleep(2);

        printf("Writer: %d: Trying to get WRITE lock...\n", thread_id);
        pthread_rwlock_wrlock(&config_lock);

        printf("Writer %d: Got WRITE lock! Updating config...\n", thread_id);

        config_version++;
        snprintf(shared_config, sizeof(shared_config), "New Config v%d", config_version);

        sleep(1);
        printf("Writer %d: Releasing WRITE lock.\n", thread_id);

        pthread_rwlock_unlock(&config_lock);
    }

    return NULL;
}

void ThreadRWLock(bool run) {
    if (!run) {
        return;
    }

    pthread_t readers[3];
    pthread_t writer;
    int reader_ids[3];

    pthread_rwlock_init(&config_lock, NULL);

    for (int i = 0; i < 3; i++) {
        reader_ids[i] = i + 1;
        pthread_create(&readers[i], NULL, reader_thread, &reader_ids[i]);
    }

    int writer_id = 99;
    pthread_create(&writer, NULL, writer_thread, &writer_id);

    for (int i = 0; i < 3; i++) {
        pthread_join(readers[i], NULL);
    }
    pthread_join(writer, NULL);

    pthread_rwlock_destroy(&config_lock);
    
    printf("Final config is: '%s'\n", shared_config);
}