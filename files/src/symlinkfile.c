#include "symlinkfile.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

void inspect_file(const char* filename) {
    struct stat regular_stat;
    struct stat link_stat;

    if (lstat(filename, &link_stat) == -1) {
        perror("error finding symbolic link stats");
        exit(1);
    }

    printf("--- Inspected with lstat() ---\n");
    printf("Inode of '%s': %llu (This is the link's own inode)\n", filename, link_stat.st_ino);

    if (stat(filename, &regular_stat) == -1) {
        perror("error finding regular stats");
        exit(1);
    }

    printf("--- Inspected with stat() ---\n");
    printf("Inode of '%s': %llu (This is the original file's inode)\n", filename, regular_stat.st_ino);
    printf("=========================================\n");
}

void SymLinkFile(bool run) {
    if (!run) {
        return;
    }

    const char *original = "assets/original.txt";
    const char *softlink = "assets/softlink.txt";

    unlink(original);
    unlink(softlink);

    int fd = open(original, O_CREAT | O_WRONLY, 0644);
    close(fd);

    struct stat s_orig;
    stat(original, &s_orig);
    printf("Inode for original file is: %llu\n", s_orig.st_ino);
    printf("=========================================\n");

    const char *target_name = strrchr(original, '/');

    if (target_name == NULL) {
        target_name = original;
    } else {
        target_name = target_name + 1;
    }

    if (symlink(target_name, softlink) == -1) {
        perror("error creating symbolic link");
        exit(1);
    }
    printf(">>> Created symbolic link %s: %s\n\n", softlink, original);

    inspect_file(softlink);
}