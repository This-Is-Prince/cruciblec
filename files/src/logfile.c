#include "logfile.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void OpenLogFile(bool run) {
    if (!run) {
        return;
    }

    int fd;
    char log_message[100];
    time_t now = time(NULL);

    int flags = O_WRONLY | O_CREAT | O_APPEND;
    mode_t mode = 0644;

    fd = open("assets/app.log", flags, mode);
    if (fd == -1) {
        perror("failed open log file");
        exit(EXIT_FAILURE);
    }

    char *t_str = ctime(&now);
    snprintf(log_message, sizeof(log_message), "%s: Application started.", t_str);

    log_message[strlen(t_str) - 1] = ' ';

    write(fd, log_message, strlen(log_message));

    close(fd);
}