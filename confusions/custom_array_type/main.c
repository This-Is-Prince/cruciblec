#include <stdio.h>

typedef unsigned char int8;

typedef int8 Stack[0xffff];

int main() {

    Stack s = {0};
    for (size_t i = 0; i < sizeof(s); ++i) {
        s[i] = i;
    }
    printf("%zu\n", sizeof(s));
    for (size_t i = 0; i < sizeof(s); ++i) {
        printf("%d,", s[i]);
    }

    return 0;
}