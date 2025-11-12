#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

const char* SHM_NAME = "/my-magic/blackboard";
const int MESSAGE_SIZE = 128;

int main() {
    int shm_fd = shm_open(SHM_NAME, O_RDONLY, 0666);
    if (shm_fd == -1) {
        perror("shm_open failed");
        exit(1);
    }

    void* ptr = mmap(0, MESSAGE_SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap failed");
        exit(1);
    }

    printf("Read '%s' from %s\n", (char*)ptr, SHM_NAME);
    munmap(ptr, MESSAGE_SIZE);

    close(shm_fd);

    shm_unlink(SHM_NAME);
    printf("Reader is done and cleaned up the blackboard.\n");

    return 0;
}