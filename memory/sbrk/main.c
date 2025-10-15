#include <stdio.h>
#include <unistd.h>

int main() {
    void *initial_break = sbrk(0);
    printf("The playground fence (initial break) is at: %p\n", initial_break);

    void *new_memory_start = sbrk(100);

    if (new_memory_start == (void *)-1) {
        printf("Oh no! The OS said no more memory.\n");
        return 1;
    }

    printf("We asked for 100 bytes. Our new memory starts at: %p\n", new_memory_start);

    void *new_break = sbrk(0);
    printf("The playground fence (new break) is now at: %p\n", new_break);

    char *my_string = (char *)new_memory_start;
    // snprintf(my_string, 100, "Hello, sbrk!");
    my_string[0] = 'H';
    my_string[1] = 'i';
    my_string[2] = '!';
    my_string[3] = '\0';

    printf("I wrote this to my new memory: %s\n", my_string);
    
    return 0;
}