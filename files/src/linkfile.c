#include "linkfile.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void print_stats(const char *filename) {
    struct stat s;
    if (stat(filename, &s) == -1) {
        perror("failed to get stat of a file");
        exit(1);
    }

    printf("Stats for '%s':\n", filename);
    printf("Inode number: %llu\n", s.st_ino);
    printf("Hard links: %d\n", s.st_nlink);
    printf("---------------\n");
}

void LinkFile(bool run) {
    if (!run) {
        return;
    }

    const char *original = "assets/original.txt";
    const char *hardlinked = "assets/hardlink.txt";

    int fd = open(original, O_WRONLY | O_CREAT, 0644);
    write(fd, "hello", 5);
    close(fd);

    print_stats(original);

    if (link(original, hardlinked) == -1) {
        perror("hard linking creation failed!");
        exit(1);
    }

    printf(">>> Created hard link: %s -> %s\n\n", hardlinked, original);

    print_stats(original);
    print_stats(hardlinked);
    
    sleep(5);

    unlink(original);
    unlink(hardlinked);
}