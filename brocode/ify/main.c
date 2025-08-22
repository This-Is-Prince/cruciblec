#include <stdio.h>


int main() {

    int age = 21;

    if (age >= 50) {
        printf("You are an Old guy");
    } else if (age >= 18 && age < 50) {
        printf("You are not an adult");
    } else if (age >= 12 && age < 18) {
        printf("You are a guy");
    } else {
        printf("You are a noob");
    }

    return 0;
}