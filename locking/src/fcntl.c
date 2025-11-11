#include "fcntl.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

void FileControl(bool run) {
    if (!run) {
        return;
    }

    int flags;

    flags = fcntl(STDIN_FILENO, F_GETFL);
    if (flags == -1) {
        perror("error getting flags");
        exit(1);
    }

    if (fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK) == -1) {
        perror("error setting non block flags");
        exit(1);
    }

    printf("stdin is now non-blocking. Try typing something!\n");
    printf("The loop will spin ('.') while waiting for input...\n");

    char buffer[100];

    while (true) {
        ssize_t bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
        
        if (bytes_read > 0) {
            buffer[bytes_read] = '\0';
            printf("\n--- You typed: %s", buffer);
        } else if (bytes_read == 0) {
            printf("\nEnd of file. Exiting.\n");
            break;
        } else {
            if (errno == EWOULDBLOCK || errno == EAGAIN) {
                printf(".");
                fflush(stdout);
                sleep(1);
            } else {
                perror("\nread error");
                break;
            }
        }
    }

    fcntl(STDIN_FILENO, F_SETFL, flags);
    printf("Restored blocking mode.\n");
}