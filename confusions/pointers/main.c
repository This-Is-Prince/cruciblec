#include <stdio.h>
#include <stdlib.h>

void theFoundation() {
    int age = 25;
    int *pAge = &age;

    printf("Value of age: %d\n", age);
    printf("Address of age: %p\n", &age);

    printf("\n");

    printf("Value of pAge (the address it holds): %p\n", pAge);
    printf("Value at the address pAge points to: %d\n", *pAge);

    printf("\nChanging value through the pointer...\n");
    *pAge = 30;
    printf("New value of age: %d\n", age);

    printf("\n\n");
}

void pointersArithmetic() {
    int numbers[] = {10, 20, 30, 40};
    int *pNumbers = numbers;

    printf("Address 0: %p holds value %d\n", pNumbers, *pNumbers);

    pNumbers = pNumbers + 1;

    printf("Address 1: %p holds value %d\n", pNumbers, *pNumbers);

    printf("\nLooping with pointer arithmetic: \n");
    int *ptr = numbers;
    for (int i = 0; i < 4; ++i) {
        printf("Element %d: %d\n", i, *(ptr + i));
    }

    printf("\n\n");
}

typedef struct {
    int id;
    float gpa;
} Student;

void printStudent(const Student *s) {
    printf("Student ID: %d, GPA: %.2f\n", s->id, s->gpa);
}

void pointersAndStructs() {
    Student s1 = {101, 3.8f};

    printStudent(&s1);

    printf("\n\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void pointersAndFunctions() {
    int x = 5;
    int y = 10;

    printf("Before swap: x = %d, y = %d\n", x, y);

    swap(&x, &y);

    printf("After swap: x = %d, y = %d\n", x, y);
    
    printf("\n\n");
}

typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_CHAR,
} DataType;

void printGeneric(void *data, DataType type) {
    printf("The value is: ");

    switch (type) {
        case TYPE_INT:
            printf("%d\n", *(int*)data);
            break;
        case TYPE_FLOAT:
            printf("%f\n", *(float*)data);
            break;
        case TYPE_CHAR:
            printf("%c\n", *(char*)data);
            break;
    }
}

void pointersGeneric() {
    int myInt = 100;
    float myFloat = 3.14f;
    char myChar = 'A';

    printGeneric(&myInt, TYPE_INT);
    printGeneric(&myFloat, TYPE_FLOAT);
    printGeneric(&myChar, TYPE_CHAR);

    printf("\n\n");
}

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }

void calculate(int a, int b, int (*operation)(int, int)) {
    int result = operation(a, b);
    printf("Result: %d\n", result);
}

void functionsPointers() {
    int (*pFunc)(int, int);

    pFunc = add;
    printf("Direct call to add: %d\n", pFunc(10, 5));

    pFunc = subtract;
    printf("Direct call to subtract: %d\n\n", pFunc(10, 5));

    printf("Using calculate() as a callback:\n");
    calculate(20, 7, add);
    calculate(20, 7, subtract);

    printf("\n\n");
}

void allocate_fails(int *ptr) {
    ptr = malloc(sizeof(int));
    *ptr = 10;
    printf("Inside allocate_fails, ptr points to new memory holding %d\n", *ptr);
}

void allocate_succeeds(int **ptr_to_ptr) {
    *ptr_to_ptr = malloc(sizeof(int));
    **ptr_to_ptr = 20;
}

void pointersToPointers() {
    int *p1 = NULL;
    int *p2 = NULL;

    printf("Before calls: p1 = %p, p2 = %p\n", p1, p2);

    allocate_fails(p1);
    printf("After allocate_fails: p1 is still %p\n\n", p1);

    allocate_succeeds(&p2);
    printf("After allocate_succeeds: p2 is now %p\n", p2);
    printf("Value at p2: %d\n", *p2);

    free(p2);
    p2 = NULL;

    printf("\n\n");
}

int main () {
    theFoundation();
    pointersArithmetic();
    pointersAndStructs();
    pointersAndFunctions();
    pointersGeneric();
    functionsPointers();
    pointersToPointers();

    return 0;
}