#include "seekfile.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define RECORD_SIZE 20

void SeekFile(bool run) {
    if (!run) {
        return;
    }

    int fd;
    char buffer[50];
    int record_to_read = 4;

    fd = open("assets/records.dat", O_RDONLY);
    if (fd == -1) {
        perror("records.dat file opened failed!");
        exit(EXIT_FAILURE);
    }

    off_t target_offset = record_to_read * RECORD_SIZE;

    printf("%lld\n", target_offset);

    if (lseek(fd, target_offset, SEEK_SET) == -1) {
        perror("seek failed");
        close(fd);
        exit(EXIT_FAILURE);
    }

    ssize_t bytes_read = read(fd, buffer, RECORD_SIZE);

    if (bytes_read > 0) {
        buffer[bytes_read] = '\0';
        printf("Record 5th: %s", buffer);
    }

    close(fd);
}