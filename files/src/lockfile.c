#include "lockfile.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

void LockFile(bool run) {
    if (!run) {
        return;
    }

    int fd;
    const char *lock_file = "assets/lockfile";

    fd = open(lock_file, O_WRONLY | O_CREAT, 0666);
    if (fd == -1) {
        perror("file opening failed!");
        exit(1);
    }

    printf("Process %d: Trying to get lock...\n", getpid());

    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        if (errno == EACCES || errno == EAGAIN) {
            printf("Process %d: Could not get lock. File is already locked.\n", getpid());
            close(fd);
            exit(1);
        }
        perror("error while locking the file");
        exit(1);
    }

    printf("Process %d: Got the lock! Working for 10 seconds...\n", getpid());
    sleep(10);

    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_UNLCK, &lock) == -1) {
        perror("file unlocking failed!");
        exit(1);
    }

    printf("Process %d: Released the lock.\n", getpid());
    close(fd);
}