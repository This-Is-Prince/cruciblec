#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 3;
    int cols_row0 = 2;
    int cols_row1 = 3;

    int **nestedArray = malloc(rows * sizeof(int*));
    // int **nestedArray = malloc(rows * sizeof(*nestedArray));

    if (nestedArray == NULL) {
        return 1;
    }

    nestedArray[0] = malloc(cols_row0 * sizeof(int));

    nestedArray[1] = malloc(cols_row1 * sizeof(int));

    nestedArray[2] = NULL;

    if (nestedArray[0] == NULL || nestedArray[1] == NULL) {
        return 1;
    }

    nestedArray[0][0] = 1;
    nestedArray[0][1] = 2;
    nestedArray[1][0] = 10;
    nestedArray[1][1] = 20;
    nestedArray[1][2] = 30;

    printf("nestedArray[1][2] = %d\n", nestedArray[1][2]);

    free(nestedArray[0]);
    free(nestedArray[1]);

    free(nestedArray);

    return 0;
}