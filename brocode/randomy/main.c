#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {

    srand(time(NULL));

    // printf("%d", rand());
    // printf("\n%d", RAND_MAX);

    int randomNum = rand() % 10;
    printf("%d", randomNum);

    return 0;
}