#include <stdio.h>
#include <stdbool.h>


void printAny(int a, float b, char c, char d[], bool e) {
    printf("%d, %f, %c, %s, %s", a, b, c, d, e ? "true": "false");
}

float addFloat(float a, float b, float c) {
    return a + b + c;
}

int main() {
    int a = 10;
    float b = 10.5;
    char c = 'C';
    char d[] = "D for Dog";
    bool e = true;

    printAny(a, b, c, d, e);
    printf("\n%f", addFloat(3.2,3.2,3.2));

    return 0;
}