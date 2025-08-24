#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

struct Student {
    char* name;
    int age;
    float gpa;
    bool isFullTime;
};

typedef struct {
    char* name;
    int age;
} Person;

int main() {
    struct Student student1 = {malloc(50 * sizeof(char)), 24, 5.5, true};
    strcpy(student1.name, "Prince");
    printf("%s\n", student1.name);
    printf("%p\n", student1.name);
    // student1.name = "Prince Kumar";
    strcpy(student1.name, "Prince Kumar");
    printf("%s\n", student1.name);
    printf("%p\n", student1.name);

    Person person1 = {"Prince", 24};

    printf("");

    return 0;
}