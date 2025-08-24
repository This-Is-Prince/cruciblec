#include <stdio.h>
#include <string.h>

struct Item {
    char code1;
    int quantity;
    char code2;
};

int main() {
    int numbers[4];

    printf("sizeof(int) is %zu bytes.\n\n", sizeof(int));

    for (int i = 0; i < 4; i++) {
        printf("Address of numbers[%d] is %p\n", i, &numbers[i]);
    }

    char name[] = "Bob";

    printf("\n\n\nsizeof(char) is %zu bytes.\n\n", sizeof(name[0]));

    for (int i = 0; i < 5; i++) {
        printf("Address of '%c' char[%d] is %p\n", name[i], i, &name[i]);
    }

    printf("\n\n");

    struct Item item1;

    printf("Size of char: %zu\n", sizeof(char));
    printf("Size of int: %zu\n", sizeof(int));
    printf("Total size of Item struct: %zu\n\n", sizeof(struct Item));

    printf("Address of item1: %p\n", &item1);
    printf("Address of code1: %p\n", &item1.code1);
    printf("Address of quantity: %p\n", &item1.quantity);
    printf("Address of code2: %p\n", &item1.code2);

    return 0;
}