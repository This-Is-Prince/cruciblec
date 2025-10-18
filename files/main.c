#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd;
    const char *text = "Hello, Kernel!";
    ssize_t bytes_written;

    fd = open("test.txt", O_WRONLY | O_CREAT, 0644);
    int fd1 = open("test.txt", O_WRONLY, 0654);

    printf("File descriptor is: %d, %d\n", fd, fd1);

    if (fd == -1) {
        perror("error opening file");
        return 1;
    }

    bytes_written = write(fd, text, strlen(text));

    if (bytes_written == -1) {
        perror("error writing to file");
        close(fd);
        return 1;
    }

    printf("Successfully wrote %ld bytes to the file.\n", bytes_written);

    if (close(fd) == -1) {
        perror("error closing file");
        return 1;
    }

    return 0;
}