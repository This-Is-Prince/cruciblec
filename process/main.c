#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

extern char **environ;

int main() {
    printf("Main program started with process id: %d and Parent Process id: %d\n\n", getpid(), getppid());

    pid_t child_pid = fork();

    if (child_pid < 0) {
        perror("fork failed");
        exit(1);
    }
    
    if (child_pid == 0) {
        printf("Child process id: %d\n", getpid());

        char *pathname = "/bin/ls";
        char *argv[] = {
            "/bin/ls",
            "-l",
            "/",
            NULL
        };

        execve(pathname, argv, environ);

        perror("execve failed");
        exit(1);
    }

    int waiting_for_pid = wait(NULL);

    printf("We were waiting for this process id: %d in process id: %d which has parent id: %d\n", waiting_for_pid, getpid(), getppid());

    return 0;
}


// #TODO: Understanding fork
// int main() {
//     printf("Main program started with process id: %d and parent process id %d\n\n", getpid(), getppid());

//     const int NUM_CHILDREN = 3;

//     for (int i = 0; i < NUM_CHILDREN; i++) {
//         pid_t child_pid = fork();

//         if (child_pid < 0) {
//             perror("fork failed");
//             exit(1);
//         } else if (child_pid == 0) {
//             printf(" -> Child #%d created. My PID is %d, My parent is %d.\n", i + 1, getpid(), getppid());
//             sleep(i + 1);
//             printf(" -> Child #%d (PID: %d) is finishing.\n", i + 1, getpid());
//             exit(0);
//         }
//     }

//     printf("\nParent has created all children and is now waiting for them...\n\n");

//     for (int i = 0; i < NUM_CHILDREN; i++) {
//         pid_t terminated_child_pid = wait(NULL);
//         printf("Parent detected that child with PID %d has finished.\n", terminated_child_pid);
//     }

//     printf("Parent has finished waiting for all children. Exiting.\n");

//     sleep(10000000);

//     return 0;
// }