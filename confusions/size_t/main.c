#include <stdio.h>
#include <stdlib.h>

int main() {

    int numbers[] = {10, 20, 30, 40, 50};
    size_t count = sizeof(numbers) / sizeof(numbers[0]);
    printf("The array has %zu elements.\n\n", count);

    for (size_t i = 0; i < count; i++) {
        printf("%d, ", numbers[i]);
    }

    printf("\n\n");

    int *arr = malloc(100 * sizeof(int));

    char name[] = "India";
    size_t length = sizeof(name); // Includes the null terminator '\0'

    printf("The size of the 'name' array is: %zu bytes.\n\n", length);

    return 0;
}