#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    printf("Main program started with process id: %d and parent process id %d\n\n", getpid(), getppid());

    const int NUM_CHILDREN = 3;

    for (int i = 0; i < NUM_CHILDREN; i++) {
        pid_t child_pid = fork();

        if (child_pid < 0) {
            perror("fork failed");
            exit(1);
        } else if (child_pid == 0) {
            printf(" -> Child #%d created. My PID is %d, My parent is %d.\n", i + 1, getpid(), getppid());
            sleep(i + 1);
            printf(" -> Child #%d (PID: %d) is finishing.\n", i + 1, getpid());
            exit(0);
        }
    }

    printf("\nParent has created all children and is now waiting for them...\n\n");

    for (int i = 0; i < NUM_CHILDREN; i++) {
        pid_t terminated_child_pid = wait(NULL);
        printf("Parent detected that child with PID %d has finished.\n", terminated_child_pid);
    }

    printf("Parent has finished waiting for all children. Exiting.\n");

    sleep(10000000);

    return 0;
}