#include <stdio.h>

void counter() {
    int normal_count = 1;
    static int static_count = 1;

    printf("Normal: %d, Static: %d\n", normal_count, static_count);

    normal_count++;
    static_count++;
}

int main() {
    printf("First call:\n");
    counter();

    printf("Second call:\n");
    counter();

    printf("Third call:\n");
    counter();

    printf("Fourth call:\n");
    counter();

    return 0;
}