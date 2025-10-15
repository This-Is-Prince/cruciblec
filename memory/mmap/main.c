#include <stdio.h>
#include <sys/mman.h>
#include <string.h>

int main() {

    void *my_memory_land = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    // void *my_memory_land = mmap(NULL, 4096, PROT_READ, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (my_memory_land == MAP_FAILED) {
        printf("Oh no! The OS said no to our mmap request.\n");
        return 1;
    }

    printf("Success! The OS gave us a new plot of land at address: %p\n", my_memory_land);

    strcpy((char *)my_memory_land, "Hello, memory-mapped world!");
    
    printf("I wrote this to the new memory: '%s'\n", (char *)my_memory_land);

    int result = munmap(my_memory_land, 4096);

    if (result == -1) {
        printf("Oh no ! munmap failed.\n");
        return 1;
    }

    printf("Success! The land has been returned to the OS.\n");

    return 0;
}