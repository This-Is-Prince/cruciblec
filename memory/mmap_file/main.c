#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {

    int fd = open("data.txt", O_RDWR);
    if (fd == -1) {
        printf("Error: Could not open data.txt\n");
        return 1;
    }

    struct stat file_stats;
    if (fstat(fd, &file_stats) == -1) {
        printf("Error: Could not get file stats.\n");
        return 1;
    }

    size_t file_size = file_stats.st_size;
    printf("File 'data.txt' is %zu bytes long.\n", file_size);

    char *file_in_memory = mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (file_in_memory == MAP_FAILED) {
        printf("Error: Memory mapping failed.\n");
        return 1;
    }

    printf("File mapped into memory at address: %p\n", file_in_memory);

    printf("Original content from memory: '%s'\n", file_in_memory);

    printf("\nChanging the first 5 characters to 'HELLO'...\n\n");
    memcpy(file_in_memory, "HELLO", 5);

    printf("New content from memory: '%s'\n", file_in_memory);

    munmap(file_in_memory, file_size);
    close(fd);

    printf("Cleaned up. Now check the contents of data.txt!\n");

    return 0;
}