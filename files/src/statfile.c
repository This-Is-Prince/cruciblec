#include "statfile.h"
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

void StatFile(bool run) {
    if (!run) {
        return;
    }

    struct stat file_stats;

    if (stat("assets/records.dat", &file_stats) == -1) {
        perror("stats errors");
        exit(1);
    }

    printf("Information for %s:\n", "assets/records.dat");
    printf("-----------------------------------\n");
    printf("File Size: %lld bytes\n", file_stats.st_size);
    printf("Owner ID: %d\n", file_stats.st_uid);
    printf("Number of Hard Links: %hu\n", file_stats.st_nlink);

    printf("File Type: ");
    if (S_ISREG(file_stats.st_mode)) {
        printf("Regular File\n");
    } else if (S_ISDIR(file_stats.st_mode)){
        printf("Directory\n");
    }

    printf("Permissions: ");
    printf((file_stats.st_mode & S_IRUSR) ? "r" : "-");
    printf((file_stats.st_mode & S_IWUSR) ? "w" : "-");
    printf((file_stats.st_mode & S_IXUSR) ? "x" : "-");
    
    printf("\n");
    printf("Last Modified: %s\n", ctime(&file_stats.st_mtime));
}