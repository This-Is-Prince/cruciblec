#include <stdio.h>
#include <stdbool.h>

int main() {
    printf("Variables in C\n");

    int age = 25; // Integer variable
    float height = 5.9; // Float variable
    printf("You are %d years old and %.1f feet tall.\n", age, height);

    int years = 2025; // Integer variable for year
    printf("The year is %d.\n", years);

    int quantity = 10; // Integer variable for quantity
    printf("You have %d items.\n", quantity);

    float gpa = 2.5;
    printf("Your GPA is %.1f\n", gpa);

    float price = 19.99;
    printf("The price is $%.3f\n", price);

    float temperature = -10.1;
    printf("The temperature is %.1f degrees.\n", temperature);

    double pi = 3.141592653589793;
    printf("The value of pi is %.15lf\n", pi);

    char grade = 'A'; // Character variable
    printf("Your grade is %c and %d\n", grade, grade);

    char name[] = "Prince"; // String variable
    printf("Your name is %s\n", name);

    bool isStudent = true; // Boolean variable
    printf("Are you a student? %s\n", isStudent ? "Yes" : "No");

    bool isOnline = true;
    bool isStudent1 = true;

    if (isStudent1) {
        printf("You are a student");
    } else {
        printf("You are not a student");
    }

    if (isOnline) {
        printf("You are ONLINE\n");
    } else {
        printf("You are OFFLINE\n");
    }

    return 0;
}