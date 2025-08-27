#include <stdio.h>

typedef union {
    int i;
    float f;
    char c;
} Data;

int main() {
    Data my_data;

    my_data.i = 10;
    printf("As integer: %d\n", my_data.i);

    my_data.f = 3.14;
    printf("As float: %f\n", my_data.f);
    
    printf("As integer after float assignment: %d (garbage value)\n", my_data.i);

    my_data.c = 'A';
    printf("As char: %c\n", my_data.c);

    return 0;
}