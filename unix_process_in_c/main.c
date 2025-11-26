#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[]) {
    int id = fork();
    int n;

    if (id == 0) {
        n = 1;
    } else {
        n = 6;
        wait(NULL);
    }

    for (int i = n; i < n + 5; i++) {
        printf("%d ", i);
        fflush(stdout);
    }

    return 0;
}

int main_ch_1(int argc, char* argv[]) {
    int id = fork();

    if (id != 0) {
        fork();
    }

    // printf("Hello world from id: %d\n", id);
    printf("Hello world\n");

    // if (id == 0) {
    //     printf("Hello from child process\n");
    // } else {
    //     printf("Hello from the main process\n");
    // }

    return 0;
}