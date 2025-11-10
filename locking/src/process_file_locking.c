#include "process_file_locking.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/file.h>
#include <string.h>
#include <errno.h>

void ProcessFileLocking(bool run, int argc, char* argv[]) {
    if (!run) {
        return;
    }

    if (argc < 2) {
        printf("Usage: %s <YourName>\n", argv[0]);
        exit(1);
    }

    char* process_name = argv[1];

    int fd = open("my_diary.txt", O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("failed to open file");
        exit(1);
    }

    printf("[%s] Trying to get an exclusive lock...\n", process_name);


    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl failed to get lock");
        close(fd);
        exit(1);
    }

    printf("[%s] Got the lock! Writing to the diary.\n", process_name);

    char message[100];
    snprintf(message, sizeof(message), "Hello from %s!\nThis is my secret.\n", process_name);

    lseek(fd, 0, SEEK_END);
    write(fd, message, strlen(message));

    if (fsync(fd) == -1) {
        perror("fsync failed");
    }

    printf("[%s] I'm holding the lock for 5 seconds...\n", process_name);
    sleep(10);

    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("fcntl failed to release lock");
        close(fd);
        exit(1);
    }

    printf("[%s] Released the lock. Bye!\n", process_name);
    close(fd);
}