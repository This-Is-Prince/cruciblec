#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void whileDemo(bool run);
void whileDemoStr(bool run);
void doWhileDemo(bool run);

int main() {

    whileDemo(false);
    whileDemoStr(true);
    doWhileDemo(false);

    return 0;
}

void whileDemo(bool run) {
    if (!run) {
        return;
    }

    int number = 0;

    while (number <= 0) {
        printf("Enter a number greater than 0: ");
        scanf("%d", &number);
    }
}

void whileDemoStr(bool run) {
    if (!run) {
        return;
    }

    char name[50] = "";

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0';

    while (strlen(name) == 0) {
        printf("Name can't be empty, please enter your name again: ");
        fgets(name, sizeof(name), stdin);
        name[strlen(name) - 1] = '\0';
    }

    printf("You have entered: %s", name);
}

void doWhileDemo(bool run) {
    if (!run) {
        return;
    }

    int number = 0;

    do {
        printf("Enter a number greater than 0: ");
        scanf("%d", &number);
    } while (number <= 0);
}