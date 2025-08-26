#include <stdio.h>

int main(int argc, const char* argv[]) {

    printf("%d\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("%s, ", argv[i]);
    }

    return 0;
}