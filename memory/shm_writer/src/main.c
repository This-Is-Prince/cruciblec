#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

const char* SHM_NAME = "/my-magic/blackboard";
const char* MESSAGE = "Hello from C!";
const int MESSAGE_SIZE = 128;

int main() {
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("shm_open failed");
        exit(1);
    }

    ftruncate(shm_fd, MESSAGE_SIZE);

    void* ptr = mmap(0, MESSAGE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap failed");
        exit(1);
    }

    sprintf((char*)ptr, "%s", MESSAGE);
    printf("Wrote '%s' to %s\n", MESSAGE, SHM_NAME);

    munmap(ptr, MESSAGE_SIZE);

    close(shm_fd);

    printf("Writer is done. The reader can now read.\n");
    printf("Waiting for 30 seconds before exiting...\n");
    sleep(30);

    return 0;
}