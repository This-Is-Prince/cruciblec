#include "unlinkfile.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void UnlinkFile(bool run) {
    if (!run) {
        return;
    }

    int fd;
    const char *temp_file_path = "assets/mytempfile.tmp";


    fd = open(temp_file_path, O_RDWR | O_CREAT | O_EXCL, 0600);
    if (fd == -1) {
        perror("error opening file");
        return;
    }

    printf("Opened temporary file with fd = %d\n", fd);

    sleep(5);

    if (unlink(temp_file_path) == -1) {
        perror("unlink file failed");
        return;
    }

    printf("Unlinked the file. Go check your directory. It's gone!\n");

    const char *msg = "Secret data";
    write(fd, msg, strlen(msg));
    
    printf("Wrote '%s' to the invisible file.\n", msg);

    lseek(fd, 0, SEEK_SET);
    char buffer[20];
    ssize_t count = read(fd, buffer, sizeof(buffer));
    if (count <= 0) {
        perror("reading failed!");
        return;
    }
    buffer[count] = '\0';
    printf("Read back: '%s'\n", buffer);

    printf("Sleeping for 10 seconds before closing...\n");
    sleep(10);

    close(fd);
    printf("Closed fd. The file data is now gone forever.\n");

}