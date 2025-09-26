#include <stdio.h>

int main(void) {

    char buffer[100];

    printf("Enter something:-\n");
    fgets(buffer, sizeof(buffer), stdin);
    printf("'%s'", buffer);

    return 0;
}