#include <stdio.h>

typedef int Number;
typedef char String[5];
typedef char* StringExtended;

enum Day {
    SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
};

enum Status {
    SUCCESS = 5, FAILURE = 10, PENDING = 15
};

int main() {
    Number a = 10;
    Number b = 20;

    printf("%d\n", a + b);

    String c = "Hello World"; // Only Hello will printed
    printf("%s\n", c);

    StringExtended d = "Hello World";
    printf("%s\n", d);

    enum Day days[] = {SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY};

    int size = sizeof(days) / sizeof(days[0]);

    for (int i = 0; i < size; i++) {
        printf("%d, ", days[i]);
    }

    printf("\n");

    enum Status statues[] = {SUCCESS, FAILURE, PENDING};

    size = sizeof(statues) / sizeof(statues[0]);

    for (int i = 0; i < size; i++) {
        printf("%d, ", statues[i]);
    }

    return 0;
}