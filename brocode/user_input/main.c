#include <stdio.h>
#include <string.h>

int cleanup() {
    while (getchar() != '\n');
    return 0;
}

int main() {
    int age = 0;
    float gpa = 0.0f;
    char grade = '\0';
    char name[30] = "";

    printf("Enter your age: ");
    scanf("%d", &age);
    cleanup();

    printf("Enter your GPA: ");
    scanf("%f", &gpa);
    cleanup();
    
    printf("Enter your grade: ");
    // scanf(" %c", &grade);
    scanf("%c", &grade);
    cleanup();

    printf("Enter your full name: ");
    // scanf("%s", &name);
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0';
    // cleanup();

    printf("\n");
    printf("'%d'\n", age);
    printf("'%.1f'\n", gpa);
    printf("'%c'\n", grade);
    printf("'%s'\n", name);

    return 0;
}