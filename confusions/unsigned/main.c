#include <stdio.h>

int main() {
    int a = -5;
    unsigned int b = 6;

    if (a < b) {
        printf("a is less than b");
    } else {
        printf("This is a common pitfall of c because c converted our signed a to a long unsigned int before comparison.");
    }

    return 0;
}