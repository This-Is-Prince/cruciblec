#include <stdio.h>

int main() {

    int numbers[] = {10, 20, 30, 40, 50};
    char grades[] = {'A' , 'B', 'C', 'D', 'F'};
    char name[] = "Bro Code";

    printf("%lu\n", sizeof(numbers) / sizeof(numbers[0]));
    printf("%c\n", name[2]);
    printf("%c\n", grades[4]);
    printf("%d\n", numbers[2]);

    int scores[5] = {0};
    int size = sizeof(scores) / sizeof(scores[0]);

    for (int i = 0; i < 5; i++) {
        printf("%d ", scores[i]);
    }

    return 0;
}